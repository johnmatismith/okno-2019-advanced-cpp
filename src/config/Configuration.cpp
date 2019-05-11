//
// Created by mr on 24.02.19.
//

#include "config/Configuration.h"

#include <stdexcept>
#include <sstream>


namespace config {

Configuration Configuration::parse(int argc, char **argv) {

    if (argc != 3) {
        std::ostringstream oss("Usage: ", std::ios::ate);
        oss << argv[0] << " <db path> <expression>";
        throw std::runtime_error(oss.str());
    }

    auto const databasePath = std::string(argv[1]);
    auto const expression = std::string(argv[2]);

    return Configuration(databasePath, expression);
}

Configuration::Configuration(std::string databasePath, std::string expression)
        : databasePath_(std::move(databasePath)),
          expression_(std::move(expression)) {
}

std::string const& Configuration::getDatabasePath() const {
    return databasePath_;
}

std::string const& Configuration::getExpression() const {
    return expression_;
}

} // namespace config
