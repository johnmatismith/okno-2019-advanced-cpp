//
// Created by mr on 24.02.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_USERINTERFACE_H
#define OKNO_2019_ADVANCED_CPP_USERINTERFACE_H

#include <iostream>
#include <map>
#include <string>

#include "engine/ParseException.h"
#include "engine/Token.h"

namespace config { class Configuration; }
namespace engine::expression { class Expression; }

namespace ui {

/**
 * Klasa reprezentująca interfejs użytkownika. Wszystkie interakcje z użytkownikiem powinny być wykonywane
 * za pośrednictwem tej klasy
 */
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


template <typename RecordIterator>
void UserInterface::presentRecordSet(RecordIterator begin, RecordIterator end, std::string const& title) {

    out_ << title << '\n';

    for (auto it = begin; it != end; ++it) {
        printRecord(*it);
        out_ << '\n';
    }

    out_<< '\n';
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

} // namespace ui


#endif //OKNO_2019_ADVANCED_CPP_USERINTERFACE_H
