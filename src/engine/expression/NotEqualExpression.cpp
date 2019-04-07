//
// Created by mr on 07.04.19.
//

#include "engine/expression/NotEqualExpression.h"
#include "engine/expression/ExpressionVisitor.h"


namespace engine {
namespace expression {

NotEqualExpression::NotEqualExpression(std::unique_ptr<Expression>&& left, std::unique_ptr<Expression>&& right)
        : BinaryExpression("!=", std::move(left), std::move(right)) {
}

Value NotEqualExpression::evaluate(Expression::Record const& record) const {
    auto const left = left_->evaluate(record);
    auto const right = right_->evaluate(record);

    return left != right;
}

void NotEqualExpression::visit(ExpressionVisitor& visitor) const {
    visitor.accept(*this);
}

} // namespace expression
} // namespace engine
