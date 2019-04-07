//
// Created by mr on 07.04.19.
//

#include "engine/expression/EqualExpression.h"
#include "engine/expression/ExpressionVisitor.h"


namespace engine {
namespace expression {

EqualExpression::EqualExpression(std::unique_ptr<Expression>&& left, std::unique_ptr<Expression>&& right)
        : BinaryExpression("==", std::move(left), std::move(right)) {
}

Value EqualExpression::evaluate(Expression::Record const& record) const {
    auto const left = left_->evaluate(record);
    auto const right = right_->evaluate(record);

    return left == right;
}

void EqualExpression::visit(ExpressionVisitor& visitor) const {
    visitor.accept(*this);
}

} // namespace expression
} // namespace engine
