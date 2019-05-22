//
// Created by mr on 07.04.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_EQUALEXPRESSION_H
#define OKNO_2019_ADVANCED_CPP_EQUALEXPRESSION_H

#include "BinaryExpression.h"


namespace engine {
namespace expression {

/**
 * Klasa modelująca wyrażenie porównania: równe
 */
class EqualExpression : public BinaryExpression {
public:
    EqualExpression(std::unique_ptr<Expression>&& left, std::unique_ptr<Expression>&& right);
    ~EqualExpression() override = default;

    Value evaluate(Record const& record) const override;
    void visit(ExpressionVisitor& visitor) const override;
};

} // namespace expression
} // namespace engine


#endif //OKNO_2019_ADVANCED_CPP_EQUALEXPRESSION_H
