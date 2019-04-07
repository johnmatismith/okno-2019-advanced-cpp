//
// Created by mr on 07.04.19.
//

#include "engine/expression/BinaryExpression.h"
#include "engine/expression/ExpressionVisitor.h"


namespace engine {
namespace expression {

BinaryExpression::BinaryExpression(std::string const& operatorr, std::unique_ptr<Expression>&& left,
        std::unique_ptr<Expression>&& right)
        : operator_(operatorr),
          left_(std::move(left)),
          right_(std::move(right)) {
}

void BinaryExpression::visit(ExpressionVisitor& visitor) const {
    visitor.accept(*this);
}

std::string const& BinaryExpression::getOperator() const {
    return operator_;
}

Expression const& BinaryExpression::getLeft() const {
    return *left_;
}

Expression const& BinaryExpression::getRight() const {
    return *right_;
}

} // namespace expression
} // namespace engine
