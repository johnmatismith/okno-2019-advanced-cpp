//
// Created by mr on 07.04.19.
//

#include "engine/expression/ValueFactory.h"


namespace engine {
namespace expression {

Value ValueFactory::fromConstantToken(Token const& token) {
    switch (token.getType()) {
        case TokenType::STRING:
            return fromStringToken(token);

        case TokenType::NUMBER:
            return fromNumberToken(token);

        default:
            throw std::invalid_argument("ValueFactory::fromConstantToken: unhandled token type");
    }
}

Value ValueFactory::fromStringToken(Token const& token) {

    if (token.getType() != TokenType::STRING) {
        throw std::invalid_argument("ValueFactory::fromStringToken: non STRING token");
    }

    auto const& tokenValue = token.getValue();

    if (tokenValue[0] != '"' && tokenValue[0] != '\'') {
        throw std::invalid_argument("ValueFactory::fromStringToken: token does not start with ' or \"");
    }

    if (tokenValue[0] != tokenValue[tokenValue.length() - 1]) {
        throw std::invalid_argument("ValueFactory::fromStringToken: mismatching string terminators");
    }

    return Value(tokenValue.substr(1, tokenValue.length() - 2));
}

Value ValueFactory::fromNumberToken(Token const& token) {

    if (token.getType() != TokenType::NUMBER) {
        throw std::invalid_argument("ValueFactory::fromNumberToken: non NUMBER token");
    }

    return Value(std::stod(token.getValue()));
}

} // namespace expression
} // namespace engine
