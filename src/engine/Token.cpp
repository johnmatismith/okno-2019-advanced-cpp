//
// Created by mr on 24.03.19.
//

#include "engine/Token.h"

namespace engine {

Token::Token(TokenType type, Location const& location, std::string const& value)
        : type_(type),
          location_(location),
          value_(value) {
}

TokenType Token::getType() const {
    return type_;
}

Location const& Token::getLocation() const {
    return location_;
}

std::string const& Token::getValue() const {
    return value_;
}

} // namespace engine
