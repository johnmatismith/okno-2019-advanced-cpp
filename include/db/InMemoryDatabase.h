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

    template <typename RecordIterator>
    explicit InMemoryDatabase(RecordIterator begin, RecordIterator end);

    std::vector<Record>::const_iterator begin() const;
    std::vector<Record>::const_iterator end() const;

private:
    std::vector<Record> values_;
};

template <typename RecordIterator>
InMemoryDatabase::InMemoryDatabase(RecordIterator begin, RecordIterator end)
        : values_(begin, end) {
}

} // namespace db

#endif //OKNO_2019_ADVANCED_CPP_INMEMORYDATABASE_H
