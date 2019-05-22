//
// Created by mr on 24.03.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_TOKENTYPE_H
#define OKNO_2019_ADVANCED_CPP_TOKENTYPE_H

#include <iosfwd>


namespace engine {

/**
 * Rodzaje obsługiwanych leksemów
 */
enum TokenType {
    LESS,
    GREATER,
    EQUAL,
    NOT_EQUAL,
    LESS_EQUAL,
    GREATER_EQUAL,
    AND,
    OR,
    STRING,
    NUMBER,
    PARENTHESIS_OPEN,
    PARENTHESIS_CLOSE,
    IDENTIFIER,
    WHITESPACE
};

std::ostream& operator<<(std::ostream& out, TokenType tokenType);

} // namespace engine

#endif //OKNO_2019_ADVANCED_CPP_TOKENTYPE_H
