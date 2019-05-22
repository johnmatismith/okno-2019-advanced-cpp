//
// Created by mr on 11.05.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_JSONFILEDATABASE_H
#define OKNO_2019_ADVANCED_CPP_JSONFILEDATABASE_H


#include <experimental/filesystem>
#include <iterator>
#include <map>

namespace db {

/**
 * Klasa odpowiedzialna za przetransformowanie pliku bazy danych w formacie JSON do iterowalnych rekordów
 */
class JsonFileDatabase {

public:
    typedef std::map<std::string, std::string> Record;

    explicit JsonFileDatabase(std::experimental::filesystem::path const& path);

    std::vector<Record>::const_iterator begin() const;
    std::vector<Record>::const_iterator end() const;

private:
    std::vector<Record> values_;
};

} // namespace db


#endif //OKNO_2019_ADVANCED_CPP_JSONFILEDATABASE_H
