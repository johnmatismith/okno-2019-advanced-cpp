//
// Created by mr on 07.04.19.
//

#include "engine/expression/AndExpression.h"
#include "engine/expression/ExpressionVisitor.h"


namespace engine {
namespace expression {

AndExpression::AndExpression(std::unique_ptr<Expression>&& left, std::unique_ptr<Expression>&& right)
        : BinaryExpression("&&", std::move(left), std::move(right)) {
}

Value AndExpression::evaluate(Expression::Record const& record) const {

    auto const left = left_->evaluate(record);

    if (std::holds_alternative<std::monostate>(left)) {
        return left;
    }

    if (std::holds_alternative<bool>(left) && left == Value(false)) {
        return left;
    }

    return right_->evaluate(record);
}

void AndExpression::visit(ExpressionVisitor& visitor) const {
    visitor.accept(*this);
}

} // namespace expression
} // namespace engine
