//
// Created by mr on 28.05.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_NOREXPRESSION_H
#define OKNO_2019_ADVANCED_CPP_NOREXPRESSION_H


#include "BinaryExpression.h"

namespace engine {
namespace expression {

/**
 * Klasa modelująca wyrażenie NOR
 */
class NorExpression : public BinaryExpression {
public:
    NorExpression(std::unique_ptr<Expression>&& left, std::unique_ptr<Expression>&& right);
    ~NorExpression() override = default;

    Value evaluate(Record const& record) const override;
    void visit(ExpressionVisitor& visitor) const override;
};

} // namespace expression
} // namespace engine


#endif //OKNO_2019_ADVANCED_CPP_NOREXPRESSION_H
