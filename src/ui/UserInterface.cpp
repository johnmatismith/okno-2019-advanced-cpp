//
// Created by mr on 22.05.19.
//

#include "ui/UserInterface.h"

#include "config/Configuration.h"
#include "ui/ExpressionPrettyPrinter.h"

namespace ui {

UserInterface::UserInterface(std::ostream& out)
        : out_(out) {
}

void UserInterface::printRecord(std::map<std::string, std::string> const& record) {
    out_ << "\tRecord[ ";

    bool first = true;

    for (auto const &it : record) {

        if (!first) {
            out_ << ", ";
        }
        first = false;

        out_ << it.first << " -> " << it.second;
    }

    out_ << "]";
}

void UserInterface::presentExpression(engine::expression::Expression const& expression, std::string const& title) {
    out_ << title << '\n';

    ExpressionPrettyPrinter printer(out_, 1);
    expression.visit(printer);

    out_ << '\n';
}

void UserInterface::presentException(config::Configuration const& configuration,
                                            engine::ParseException const& exception) {

    out_ << "Expression parsing failed:\n\n\t"
         << configuration.getExpression() << "\n\t"
         << std::string(static_cast<unsigned long>(exception.getLocation().getOffset()), ' ')
         << "^--- " << exception.getMessage() << "\n\n";
}

} // namespace ui
