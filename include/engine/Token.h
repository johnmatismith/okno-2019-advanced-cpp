//
// Created by mr on 24.03.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_TOKEN_H
#define OKNO_2019_ADVANCED_CPP_TOKEN_H

#include <string>

#include "engine/Location.h"
#include "engine/TokenType.h"

namespace engine {

/**
 * Klasa reprezentująca leksem, jego typ, wartość oraz lokalizację
 */
class Token {

public:
    Token(TokenType type_, Location const& location_, std::string const& value_);

    TokenType getType() const;
    Location const& getLocation() const;
    std::string const& getValue() const;

private:
    TokenType type_;
    Location location_;

    std::string value_;

};

} // namespace engine

#endif //OKNO_2019_ADVANCED_CPP_TOKEN_H
