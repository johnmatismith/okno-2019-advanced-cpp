//
// Created by mr on 07.04.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_EQUALEXPRESSION_H
#define OKNO_2019_ADVANCED_CPP_EQUALEXPRESSION_H

#include "Expression.h"

#include <memory>


namespace engine {
namespace expression {

class EqualExpression : public Expression {

public:
    EqualExpression(std::unique_ptr<Expression>&& left, std::unique_ptr<Expression>&& right);

    Value evaluate(Record const& record) const override;
    void visit(ExpressionVisitor& visitor) const override;

    Expression const& getLeft() const;
    Expression const& getRight() const;

private:
    std::unique_ptr<Expression> left_;
    std::unique_ptr<Expression> right_;
};

} // namespace expression
} // namespace engine


#endif //OKNO_2019_ADVANCED_CPP_EQUALEXPRESSION_H
