//
// Created by mr on 11.05.19.
//

#include "db/JsonFileDatabase.h"

#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/reader.h"

namespace db {

namespace {

class MapInserter : public rapidjson::BaseReaderHandler<rapidjson::UTF8<>, MapInserter> {
public:
    MapInserter(std::map<std::string, std::string>& map, std::string key)
            : map_(map), key_(std::move(key)) {}

    bool Default() { return false; }

    bool String(const Ch *string, rapidjson::SizeType length, bool) {
        map_[key_] = std::string(string, length);
        return true;
    }

private:
    std::map<std::string, std::string>& map_;
    std::string key_;
};

std::unique_ptr<std::FILE, int (*)(FILE*)> fopen(std::experimental::filesystem::path const& path);

template <typename OutputIterator>
void parse(std::experimental::filesystem::path const& path, OutputIterator out);

} // namespace

JsonFileDatabase::JsonFileDatabase(std::experimental::filesystem::path const& path) {
    parse(path, std::back_inserter(values_));
}

std::vector<JsonFileDatabase::Record>::const_iterator JsonFileDatabase::begin() const {
    return values_.begin();
}

std::vector<JsonFileDatabase::Record>::const_iterator JsonFileDatabase::end() const {
    return values_.end();
}

namespace {

std::unique_ptr<std::FILE, int (*)(FILE*)> fopen(std::experimental::filesystem::path const& path) {
    return std::unique_ptr<std::FILE, int (*)(FILE*)>(std::fopen(path.generic_string().c_str(), "rb"), std::fclose);
}

template <typename OutputIterator>
void parse(std::experimental::filesystem::path const& path, OutputIterator out) {

    char buffer[512];

    auto file = fopen(path);
    rapidjson::FileReadStream is(file.get(), buffer, sizeof(buffer));

    rapidjson::Document document;

    document.ParseStream<rapidjson::kParseNumbersAsStringsFlag>(is);

    if (!document.IsArray()) {
        throw std::runtime_error("Database file corrupted - root object is not an Array");
    }

    for (auto const& maybeObject : document.GetArray()) {

        if (!maybeObject.IsObject()) {
            throw std::runtime_error("Database file corrupted - root Array contains something different than Objects");
        }

        auto object = maybeObject.GetObject();

        std::map<std::string, std::string> map;

        for (auto const& kv : object) {
            MapInserter builder(map, kv.name.GetString());
            if (!kv.value.Accept(builder)) {
                throw std::runtime_error(std::string("Failed to parse database file around ") + kv.name.GetString() + " field");
            }
        }

        *out = std::move(map);
    }

}

} // namespace

} // namespace db
