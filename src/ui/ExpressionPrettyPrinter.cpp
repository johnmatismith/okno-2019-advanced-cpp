//
// Created by mr on 07.04.19.
//

#include <ui/ExpressionPrettyPrinter.h>

#include "ui/ExpressionPrettyPrinter.h"


namespace ui {

ExpressionPrettyPrinter::ExpressionPrettyPrinter(std::ostream &out, unsigned long indent)
        : out_(out),
          indent_(indent) {
}

void ExpressionPrettyPrinter::accept(engine::expression::ConstantExpression const& expression) {

    out_ << std::string(indent_, '\t') << "ConstantExpression [";

    auto const& value = expression.getValue();

    if (std::holds_alternative<std::monostate>(value)) {
        out_ << "nil";
    } else if (std::holds_alternative<std::string>(value)) {
        out_ << "\"" << std::get<std::string>(value) << "\"";
    } else if (std::holds_alternative<long>(value)) {
        out_ << std::get<long>(value);
    } else if (std::holds_alternative<bool>(value)) {
        out_ << std::get<bool>(value);
    } else {
        out_ << "UNSUPPORTED VALUE TYPE";
    }

    out_ << "]\n";
}

void ExpressionPrettyPrinter::accept(engine::expression::BinaryExpression const& expression) {

    out_ << std::string(indent_++, '\t') << "BinaryExpression [" << expression.getOperator() << "]\n";

    expression.getLeft().visit(*this);
    expression.getRight().visit(*this);

    --indent_;
}

void ExpressionPrettyPrinter::accept(engine::expression::VariableExpression const& expression) {
    out_ << std::string(indent_, '\t') << "VariableExpression [" << expression.getIdentifier() << "]\n";
}

} // namespace ui
