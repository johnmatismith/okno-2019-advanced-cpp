//
// Created by mr on 24.02.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_DATABASEFACTORY_H
#define OKNO_2019_ADVANCED_CPP_DATABASEFACTORY_H

#include "db/InMemoryDatabase.h"
#include "db/JsonFileDatabase.h"

#include <experimental/filesystem>
#include <memory>

namespace db {

class DatabaseFactory {

public:
    static InMemoryDatabase createInMemoryDatabase(int size);

    static JsonFileDatabase createJsonFileDatabase(std::experimental::filesystem::path const& path);

};

} // namespace db

#endif //OKNO_2019_ADVANCED_CPP_DATABASEFACTORY_H
