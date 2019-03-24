//
// Created by mr on 24.02.19.
//

#include "config/Configuration.h"

#include <stdexcept>


namespace config {

Configuration Configuration::parse(int argc, char **argv) {

    if (argc != 3) {
        throw std::runtime_error("Wrong parameters");
    }

    auto const databaseSize = std::atoi(argv[1]);
    auto const expression = std::string(argv[2]);

    return Configuration(databaseSize, expression);
}

Configuration::Configuration(int databaseSize, std::string const& expression)
        : databaseSize_(databaseSize),
          expression_(expression) {
}

int Configuration::getDatabaseSize() const {
    return databaseSize_;
}

std::string const& Configuration::getExpression() const {
    return expression_;
}

} // namespace config
