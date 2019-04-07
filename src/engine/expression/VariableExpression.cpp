//
// Created by mr on 07.04.19.
//

#include "engine/expression/VariableExpression.h"
#include "engine/expression/ExpressionVisitor.h"


namespace engine {
namespace expression {

VariableExpression::VariableExpression(std::string const& identifier)
        : identifier_(identifier) {
}

Value VariableExpression::evaluate(Expression::Record const& record) const {

    auto it = record.find(identifier_);
    if (it == record.end()) {
        return Value();
    }

    return Value(it->second);
}

void VariableExpression::visit(ExpressionVisitor& visitor) const {
    visitor.accept(*this);
}

std::string const& VariableExpression::getIdentifier() const {
    return identifier_;
}

} // namespace expression
} // namespace engine
