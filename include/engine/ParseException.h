//
// Created by mr on 24.03.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_PARSEEXCEPTION_H
#define OKNO_2019_ADVANCED_CPP_PARSEEXCEPTION_H

#include <exception>
#include <string>

#include "Location.h"


namespace engine {

class ParseException : public std::exception {

public:
    ParseException(std::string const& message, Location const& location);

    std::string const& getMessage() const;
    Location const& getLocation() const;

    char const* what() const noexcept override;

private:
    std::string message_;
    Location location_;

    std::string what_;

};

} // namespace engine

#endif //OKNO_2019_ADVANCED_CPP_PARSEEXCEPTION_H
