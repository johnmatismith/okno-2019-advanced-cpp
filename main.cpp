
#include "config/Configuration.h"
#include "db/InMemoryDatabase.h"
#include "db/DatabaseFactory.h"
#include "engine/ExpressionParser.h"
#include "engine/Scanner.h"
#include "ui/UserInterface.h"

#include <iostream>
#include <algorithm>

int main(int argc, char* argv[]) {

    auto const configuration = config::Configuration::parse(argc, argv);
    auto const expression = engine::ExpressionParser::parse(configuration.getExpression());
    auto const database = db::DatabaseFactory::createInMemoryDatabase(configuration.getDatabaseSize());
    ui::UserInterface ui(std::cout);

    engine::Scanner scanner(database);

    std::vector<std::map<std::string, std::string>> filtered;

    scanner.scan(*expression, std::back_inserter(filtered));

    ui.presentRecordSet(database.begin(), database.end(), "Initial database");
    ui.presentRecordSet(filtered.begin(), filtered.end(), "Filtered database");

    return 0;
}
