//
// Created by mr on 07.04.19.
//

#include "engine/expression/OrExpression.h"
#include "engine/expression/ExpressionVisitor.h"


namespace engine {
namespace expression {

OrExpression::OrExpression(std::unique_ptr<Expression>&& left, std::unique_ptr<Expression>&& right)
        : BinaryExpression("||", std::move(left), std::move(right)) {
}

Value OrExpression::evaluate(Expression::Record const& record) const {

    auto const left = left_->evaluate(record);

    if (std::holds_alternative<std::monostate>(left) || left == Value(false)) {
        return right_->evaluate(record);
    }

    return left;
}

void OrExpression::visit(ExpressionVisitor& visitor) const {
    visitor.accept(*this);
}

} // namespace expression
} // namespace engine
