//
// Created by mr on 24.02.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_EXPRESSION_H
#define OKNO_2019_ADVANCED_CPP_EXPRESSION_H


#include <string>
#include <map>

#include "Value.h"

namespace engine {
namespace expression {

class ExpressionVisitor;

/**
 * Klasa modelująca dowolnie złożone wyrażenie które da się obliczyć w kontekście zadanego rekordu
 */
class Expression {

public:
    typedef std::map<std::string, std::string> Record;

    virtual ~Expression() = default;

    virtual Value evaluate(Record const& record) const = 0;
    virtual void visit(ExpressionVisitor& visitor) const = 0;
};

} // namespace expression
} // namespace engine


#endif //OKNO_2019_ADVANCED_CPP_EXPRESSION_H
