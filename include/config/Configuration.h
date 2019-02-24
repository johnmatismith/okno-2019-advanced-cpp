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

    int getDatabaseSize() const;
    std::string const& getExpression() const;

private:
    explicit Configuration(int databaseSize_);

    int databaseSize_;
};

} // namespace config

#endif //OKNO_2019_ADVANCED_CPP_CONFIGURATION_H
