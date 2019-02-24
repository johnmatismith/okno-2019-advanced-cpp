
#include "db/InMemoryDatabase.h"
#include "db/DatabaseFactory.h"

#include <iostream>
#include <algorithm>

int getDatabaseSize(int argc, char** argv);
void print(db::InMemoryDatabase const &database);
void printRecord(db::InMemoryDatabase::Record const &record);

int main(int argc, char** argv) {

    auto const size = getDatabaseSize(argc, argv);

    auto const database = db::DatabaseFactory::createInMemoryDatabase(size);

    print(database);

    return 0;
}

int getDatabaseSize(int argc, char** argv) {
    if (argc != 2) {
        throw std::runtime_error("Database size not provided");
    }
    
    return std::atoi(argv[1]);
}

void print(db::InMemoryDatabase const &database) {
    std::for_each(database.begin(), database.end(), printRecord);
}

void printRecord(db::InMemoryDatabase::Record const &record) {
    std::cout << "Database record";
    std::for_each(record.begin(), record.end(), [] (db::InMemoryDatabase::Record::value_type const& p) { std::cout << "\n\t" << p.first << " -> " << p.second; });
    std::cout << "\n\n" << std::flush;
}
