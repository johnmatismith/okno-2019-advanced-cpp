//
// Created by mr on 22.05.19.
//

#include "Application.h"
#include "engine/lexer/Lexer.h"


Application::Application(config::Configuration configuration)
        : configuration_(configuration),
          ui_(std::cout) {
}

void Application::run() {

    // 1. Otwórz bazę danych

    auto database = openDatabase();

    // 2. Zamień zapytanie na listę leksemów

    std::vector<engine::Token> tokens;
    try {
        tokens = tokenize();
    } catch (engine::ParseException const& e) {
        ui_.presentException(configuration_, e);
        return;
    }

    ui_.presentTokens(tokens.begin(), tokens.end(), "Parsed tokens");

    // 3. Zamień listę leksemów na wyrażenie

    std::unique_ptr<engine::expression::Expression> expression;
    try {
        expression = parser_.parse(tokens.begin(), tokens.end());
    } catch (engine::ParseException const& e) {
        ui_.presentException(configuration_, e);
        return;
    }

    ui_.presentExpression(*expression, "Parsed expression");

    // 4. Wykonaj wyrażenie dla każdego rekordu bazy danych

    std::vector<std::map<std::string, std::string>> filtered;

    expressionExecutor_.execute(database, *expression, std::back_inserter(filtered));

    ui_.presentRecordSet(database.begin(), database.end(), "Initial database");
    ui_.presentRecordSet(filtered.begin(), filtered.end(), "Filtered database");
}

db::JsonFileDatabase Application::openDatabase() {

    std::experimental::filesystem::path path(configuration_.getDatabasePath());

    if (!std::experimental::filesystem::is_regular_file(path)) {
        throw std::runtime_error("Database file does not exist or is not accessible");
    }

    return db::JsonFileDatabase(path);
}

std::vector<engine::Token> Application::tokenize() {

    std::vector<engine::Token> tokens;

    lexer.tokenize(configuration_.getExpression(), std::back_inserter(tokens));

    return tokens;
}
