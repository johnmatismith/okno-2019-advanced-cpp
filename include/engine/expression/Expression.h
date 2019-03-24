//
// Created by mr on 24.02.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_EXPRESSION_H
#define OKNO_2019_ADVANCED_CPP_EXPRESSION_H


#include <string>
#include <map>

namespace engine {
namespace expression {

class Expression {

public:
    typedef std::map<std::string, std::string> Record;

    virtual bool evaluate(Record const& record) const = 0;
};

} // namespace expression
} // namespace engine


#endif //OKNO_2019_ADVANCED_CPP_EXPRESSION_H
