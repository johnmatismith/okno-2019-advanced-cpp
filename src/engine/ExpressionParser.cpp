//
// Created by mr on 24.02.19.
//

#include "engine/ExpressionParser.h"

#include "engine/FieldEqualExpression.h"


namespace engine {

std::unique_ptr<Expression> ExpressionParser::parse(std::string const &expression) {
    return std::unique_ptr<Expression>(new FieldEqualExpression("key", "value 1"));
}

} // namespace engine
