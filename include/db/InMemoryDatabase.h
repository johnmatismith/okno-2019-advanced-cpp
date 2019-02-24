//
// Created by mr on 24.02.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_INMEMORYDATABASE_H
#define OKNO_2019_ADVANCED_CPP_INMEMORYDATABASE_H

#include <string>
#include <map>
#include <vector>

namespace db {

class InMemoryDatabase {

public:
    typedef std::map<std::string, std::string> Record;

    // TODO (MR): might use iterators for constructing values_
    explicit InMemoryDatabase(std::vector<Record> const& values_);

    std::vector<Record>::const_iterator begin() const;
    std::vector<Record>::const_iterator end() const;

private:
    std::vector<Record> values_;
};

} // namespace db

#endif //OKNO_2019_ADVANCED_CPP_INMEMORYDATABASE_H
