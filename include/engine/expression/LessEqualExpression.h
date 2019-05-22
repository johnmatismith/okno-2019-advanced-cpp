//
// Created by mr on 07.04.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_LESSEQUALEXPRESSION_H
#define OKNO_2019_ADVANCED_CPP_LESSEQUALEXPRESSION_H

#include "BinaryExpression.h"


namespace engine {
namespace expression {

/**
 * Klasa modelująca wyrażenie porównania: mniejsze lub równe
 */
class LessEqualExpression : public BinaryExpression {
public:
    LessEqualExpression(std::unique_ptr<Expression>&& left, std::unique_ptr<Expression>&& right);
    ~LessEqualExpression() override = default;

    Value evaluate(Record const& record) const override;
    void visit(ExpressionVisitor& visitor) const override;
};

} // namespace expression
} // namespace engine


#endif //OKNO_2019_ADVANCED_CPP_LESSEQUALEXPRESSION_H
