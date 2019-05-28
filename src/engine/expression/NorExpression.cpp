//
// Created by mr on 28.05.19.
//

#include "engine/expression/NorExpression.h"
#include "engine/expression/ExpressionVisitor.h"

namespace engine {
namespace expression {

NorExpression::NorExpression(std::unique_ptr<engine::expression::Expression>&& left,
                             std::unique_ptr<engine::expression::Expression>&& right)
        : BinaryExpression("~|", std::move(left), std::move(right)) {
}

Value NorExpression::evaluate(Expression::Record const& record) const {

    auto const left = left_->evaluate(record);

    if (std::holds_alternative<std::monostate>(left) || left == Value(true)) {
        return false;
    }

    auto const right = right_->evaluate(record);

    if (std::holds_alternative<std::monostate>(right) || right == Value(true)) {
        return false;
    }

    return true;
}

void NorExpression::visit(ExpressionVisitor& visitor) const {
    visitor.accept(*this);
}

} // namespace expression
} // namespace engine