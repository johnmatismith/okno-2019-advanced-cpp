//
// Created by mr on 24.02.19.
//

#include "engine/expression/ConstantExpression.h"
#include "engine/expression/ExpressionVisitor.h"


namespace engine {
namespace expression {

ConstantExpression::ConstantExpression(Value const& value)
        : value_(value) {
}

Value ConstantExpression::evaluate(Expression::Record const& record) const {
    return value_;
}

void ConstantExpression::visit(ExpressionVisitor& visitor) const {
    visitor.accept(*this);
}

Value const& ConstantExpression::getValue() const {
    return value_;
}

} // namespace expression
} // namespace engine
