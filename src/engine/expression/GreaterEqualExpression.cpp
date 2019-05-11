//
// Created by mr on 07.04.19.
//

#include "engine/expression/GreaterEqualExpression.h"

#include "engine/expression/ExpressionVisitor.h"
#include "engine/expression/ValueConverter.h"


namespace engine {
namespace expression {

GreaterEqualExpression::GreaterEqualExpression(std::unique_ptr<Expression>&& left, std::unique_ptr<Expression>&& right)
        : BinaryExpression(">=", std::move(left), std::move(right)) {
}

Value GreaterEqualExpression::evaluate(Expression::Record const& record) const {
    auto const left = left_->evaluate(record);
    auto const right = right_->evaluate(record);

    auto const leftAsNumber = ValueConverter::toNumber(left);
    auto const rightAsNumber = ValueConverter::toNumber(right);

    if (!leftAsNumber.has_value() || !rightAsNumber.has_value()) {
        return false;
    }

    return leftAsNumber >= rightAsNumber;
}

void GreaterEqualExpression::visit(ExpressionVisitor& visitor) const {
    visitor.accept(*this);
}

} // namespace expression
} // namespace engine
