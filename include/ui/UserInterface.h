//
// Created by mr on 24.02.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_USERINTERFACE_H
#define OKNO_2019_ADVANCED_CPP_USERINTERFACE_H


#include <string>
#include <iostream>

namespace ui {

class UserInterface {

public:
    explicit UserInterface(std::ostream& out);

    template <typename RecordIterator>
    void presentRecordSet(RecordIterator begin, RecordIterator end, std::string const& title);

private:
    void printRecord(std::map<std::string, std::string> const& record);

    std::ostream& out_;

};


UserInterface::UserInterface(std::ostream& out)
        : out_(out) {
}

template<typename RecordIterator>
void UserInterface::presentRecordSet(RecordIterator begin, RecordIterator end, std::string const& title) {

    out_ << title << '\n';

    for(auto it = begin; it != end; ++it) {
        printRecord(*it);
        out_ << '\n';
    }

}

void UserInterface::printRecord(std::map<std::string, std::string> const& record) {
    out_ << "\tRecord[ ";

    bool first = true;

    for(auto const& it : record) {

        if (!first) {
            out_ << ", ";
        }
        first = false;

        out_ << it.first << " -> " << it.second;
    }

    out_ << "]";
}

} // namespace ui


#endif //OKNO_2019_ADVANCED_CPP_USERINTERFACE_H
