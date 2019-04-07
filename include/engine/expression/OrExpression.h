//
// Created by mr on 07.04.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_OREXPRESSION_H
#define OKNO_2019_ADVANCED_CPP_OREXPRESSION_H

#include "BinaryExpression.h"


namespace engine {
namespace expression {

class OrExpression : public BinaryExpression {
public:
    OrExpression(std::unique_ptr<Expression>&& left, std::unique_ptr<Expression>&& right);
    ~OrExpression() override = default;

    Value evaluate(Record const& record) const override;
    void visit(ExpressionVisitor& visitor) const override;
};

} // namespace expression
} // namespace engine

#endif //OKNO_2019_ADVANCED_CPP_OREXPRESSION_H
