//
// Created by mr on 07.04.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_EXPRESSIONVISITOR_H
#define OKNO_2019_ADVANCED_CPP_EXPRESSIONVISITOR_H

#include "AndExpression.h"
#include "BinaryExpression.h"
#include "ConstantExpression.h"
#include "EqualExpression.h"
#include "VariableExpression.h"


namespace engine {
namespace expression {

/**
 * Wzorzec "odwiedzający" dla klasy Expression
 */
class ExpressionVisitor {
public:
    virtual void accept(ConstantExpression const& expression) = 0;
    virtual void accept(BinaryExpression const& expression) = 0;
    virtual void accept(VariableExpression const& expression) = 0;
};

} // namespace expression
} // namespace engine

#endif //OKNO_2019_ADVANCED_CPP_EXPRESSIONVISITOR_H
