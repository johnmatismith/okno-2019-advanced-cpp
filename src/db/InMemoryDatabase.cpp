//
// Created by mr on 24.02.19.
//

#include "db/InMemoryDatabase.h"

namespace db {

InMemoryDatabase::InMemoryDatabase(std::vector<Record> const& values_)
        : values_(values_) {
}

std::vector<InMemoryDatabase::Record>::const_iterator InMemoryDatabase::begin() const {
    return values_.begin();
}

std::vector<InMemoryDatabase::Record>::const_iterator InMemoryDatabase::end() const {
    return values_.end();
}

} // namespace db
