//
// Created by mr on 24.02.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_USERINTERFACE_H
#define OKNO_2019_ADVANCED_CPP_USERINTERFACE_H

#include <string>
#include <iostream>

#include "engine/ParseException.h"
#include "ExpressionPrettyPrinter.h"


namespace ui {

class UserInterface {

public:
    explicit UserInterface(std::ostream& out);

    template <typename RecordIterator>
    void presentRecordSet(RecordIterator begin, RecordIterator end, std::string const& title);

    template <typename InputIterator>
    void presentTokens(InputIterator begin, InputIterator end, std::string const& title);

    void presentExpression(engine::expression::Expression const& expression, std::string const& title);

    void presentException(config::Configuration const& configuration, engine::ParseException const& exception);

private:
    void printRecord(std::map<std::string, std::string> const& record);

    std::ostream& out_;

};


UserInterface::UserInterface(std::ostream& out)
        : out_(out) {
}

template <typename RecordIterator>
void UserInterface::presentRecordSet(RecordIterator begin, RecordIterator end, std::string const& title) {

    out_ << title << '\n';

    for (auto it = begin; it != end; ++it) {
        printRecord(*it);
        out_ << '\n';
    }

    out_<< '\n';
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

template <typename InputIterator>
void UserInterface::presentTokens(InputIterator begin, InputIterator end, std::string const& title) {

    out_ << title << '\n';

    for (; begin != end; ++begin) {
        engine::Token token = *begin;

        out_ << "\t" << token.getType() << " [" << token.getValue() << "]\n";
    }

    out_<< '\n';
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


#endif //OKNO_2019_ADVANCED_CPP_USERINTERFACE_H
