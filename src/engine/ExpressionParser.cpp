//
// Created by mr on 24.02.19.
//

#include "engine/ExpressionParser.h"

#include "engine/expression/FieldEqualExpression.h"


namespace engine {

std::unique_ptr<expression::Expression> ExpressionParser::parse(std::string const &expression) {
    return std::unique_ptr<expression::Expression>(new expression::FieldEqualExpression("key", "value 1"));
}

} // namespace engine
