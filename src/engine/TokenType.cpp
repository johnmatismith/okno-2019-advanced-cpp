//
// Created by mr on 24.03.19.
//

#include "engine/TokenType.h"

#include <ostream>


namespace engine {

std::ostream& operator<<(std::ostream& out, TokenType tokenType) {

    switch (tokenType) {
        case LESS:
            return out << "LESS";

        case GREATER:
            return out << "GREATER";

        case EQUAL:
            return out << "EQUAL";

        case NOT_EQUAL:
            return out << "NOT_EQUAL";

        case LESS_EQUAL:
            return out << "LESS_EQUAL";

        case GREATER_EQUAL:
            return out << "GREATER_EQUAL";

        case AND:
            return out << "AND";

        case OR:
            return out << "OR";

        case STRING:
            return out << "STRING";

        case NUMBER:
            return out << "NUMBER";

        case PARENTHESIS_OPEN:
            return out << "PARENTHESIS_OPEN";

        case PARENTHESIS_CLOSE:
            return out << "PARENTHESIS_CLOSE";

        case IDENTIFIER:
            return out << "IDENTIFIER";

        case WHITESPACE:
            return out << "WHITESPACE";
    }

    return out << "UNKNOWN";
}

} // namespace engine
