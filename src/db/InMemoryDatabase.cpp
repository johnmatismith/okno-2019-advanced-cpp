//
// Created by mr on 24.02.19.
//

#include "db/InMemoryDatabase.h"

namespace db {

std::vector<InMemoryDatabase::Record>::const_iterator InMemoryDatabase::begin() const {
    return values_.begin();
}

std::vector<InMemoryDatabase::Record>::const_iterator InMemoryDatabase::end() const {
    return values_.end();
}

} // namespace db
