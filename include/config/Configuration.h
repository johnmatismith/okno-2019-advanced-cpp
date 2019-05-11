//
// Created by mr on 24.02.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_CONFIGURATION_H
#define OKNO_2019_ADVANCED_CPP_CONFIGURATION_H

#include <string>


namespace config {

class Configuration {

public:
    static Configuration parse(int argc, char* argv[]);

    std::string const& getDatabasePath() const;
    std::string const& getExpression() const;

private:
    Configuration(std::string databasePath_, std::string expression);

    std::string databasePath_;
    std::string expression_;
};

} // namespace config

#endif //OKNO_2019_ADVANCED_CPP_CONFIGURATION_H
