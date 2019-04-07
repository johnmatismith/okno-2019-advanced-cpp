//
// Created by mr on 24.02.19.
//

#include "db/DatabaseFactory.h"

#include "db/InMemoryDatabase.h"

#include <algorithm>

namespace db {

namespace {

class RecordGenerator {

public:
    InMemoryDatabase::Record generate();

private:
    int i_ = 0;
};

}

InMemoryDatabase DatabaseFactory::createInMemoryDatabase(int const size) {

    auto vector = std::vector<InMemoryDatabase::Record>();

    RecordGenerator generator;
    std::generate_n(std::back_inserter(vector), size, [&generator] { return generator.generate(); });

    return InMemoryDatabase(vector);
}

namespace {

InMemoryDatabase::Record db::RecordGenerator::generate() {

    InMemoryDatabase::Record record;

    record["key"] = "value " + std::to_string(i_);
    record["other_key"] = "other value " + std::to_string(i_);

    ++i_;

    return record;
}

} // namespace

} // namespace db
