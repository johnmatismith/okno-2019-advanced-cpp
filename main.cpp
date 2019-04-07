
#include "config/Configuration.h"
#include "db/InMemoryDatabase.h"
#include "db/DatabaseFactory.h"
#include "engine/lexer/Lexer.h"
#include "engine/parser/Parser.h"
#include "engine/ExpressionExecutor.h"
#include "ui/UserInterface.h"

#include <iostream>
#include <algorithm>


std::vector<engine::Token> performTokenization(config::Configuration const &configuration) {

    engine::lexer::Lexer lexer;
    std::vector<engine::Token> tokens;

    lexer.tokenize(configuration.getExpression(), std::back_inserter(tokens));

    return tokens;
}

int main(int argc, char* argv[]) {

    auto const configuration = config::Configuration::parse(argc, argv);
    auto const database = db::DatabaseFactory::createInMemoryDatabase(configuration.getDatabaseSize());
    ui::UserInterface ui(std::cout);

    std::vector<engine::Token> tokens;
    try {
        tokens = performTokenization(configuration);
    } catch (engine::ParseException const& e) {
        ui.presentException(configuration, e);
        return 1;
    }

    ui.presentTokens(tokens.begin(), tokens.end(), "Parsed tokens");

    engine::parser::Parser parser;
    std::unique_ptr<engine::expression::Expression> expression;
    try {
        expression = parser.parse(tokens.begin(), tokens.end());
    } catch (engine::ParseException const& e) {
        ui.presentException(configuration, e);
        return 1;
    }

    ui.presentExpression(*expression, "Parsed expression");

    engine::ExpressionExecutor executor(database);

    std::vector<std::map<std::string, std::string>> filtered;

    executor.execute(*expression, std::back_inserter(filtered));

    ui.presentRecordSet(database.begin(), database.end(), "Initial database");
    ui.presentRecordSet(filtered.begin(), filtered.end(), "Filtered database");

    return 0;
}
