
#include "db/InMemoryDatabase.h"
#include "db/DatabaseFactory.h"
#include "ui/UserInterface.h"

#include <iostream>
#include <algorithm>

int getDatabaseSize(int argc, char** argv);

int main(int argc, char** argv) {

    auto const size = getDatabaseSize(argc, argv);

    auto const database = db::DatabaseFactory::createInMemoryDatabase(size);

    ui::UserInterface ui(std::cout);

    ui.presentRecordSet(database.begin(), database.end(), "Initial database");

    return 0;
}

int getDatabaseSize(int argc, char** argv) {
    if (argc != 2) {
        throw std::runtime_error("Database size not provided");
    }
    
    return std::atoi(argv[1]);
}
