//
// Created by mr on 07.04.19.
//

#include "engine/expression/EqualExpression.h"
#include "engine/expression/ExpressionVisitor.h"


namespace engine {
namespace expression {

EqualExpression::EqualExpression(std::unique_ptr<Expression>&& left, std::unique_ptr<Expression>&& right)
        : left_(std::move(left)),
          right_(std::move(right)) {
}

Value EqualExpression::evaluate(Expression::Record const& record) const {
    auto const left = left_->evaluate(record);
    auto const right = right_->evaluate(record);

    return left == right;
}

void EqualExpression::visit(ExpressionVisitor& visitor) const {
    visitor.accept(*this);
}

Expression const& EqualExpression::getLeft() const {
    return *left_;
}

Expression const& EqualExpression::getRight() const {
    return *right_;
}

} // namespace expression
} // namespace engine
