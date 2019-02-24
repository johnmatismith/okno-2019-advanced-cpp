//
// Created by mr on 24.02.19.
//

#include "config/Configuration.h"

#include <stdexcept>


namespace config {

Configuration Configuration::parse(int argc, char **argv) {

    // TODO (MR): parse expression

    if (argc != 2) {
        throw std::runtime_error("Database size not provided");
    }

    auto const databaseSize = std::atoi(argv[1]);

    return Configuration(databaseSize);
}

Configuration::Configuration(int databaseSize)
        : databaseSize_(databaseSize) {
}

int Configuration::getDatabaseSize() const {
    return databaseSize_;
}

std::string const& Configuration::getExpression() const {
    static const std::string EMPTY_STRING;
    return EMPTY_STRING;
}

} // namespace config
