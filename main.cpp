
#include "db/InMemoryDatabase.h"
#include "db/DatabaseFactory.h"
#include "ui/UserInterface.h"

#include <iostream>
#include <algorithm>
#include <config/Configuration.h>

int main(int argc, char* argv[]) {

    auto const configuration = config::Configuration::parse(argc, argv);
    auto const database = db::DatabaseFactory::createInMemoryDatabase(configuration.getDatabaseSize());

    ui::UserInterface ui(std::cout);

    ui.presentRecordSet(database.begin(), database.end(), "Initial database");

    return 0;
}
