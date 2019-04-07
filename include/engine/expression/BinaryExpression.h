//
// Created by mr on 07.04.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_BINARYEXPRESSION_H
#define OKNO_2019_ADVANCED_CPP_BINARYEXPRESSION_H

#include "Expression.h"

#include <memory>


namespace engine {
namespace expression {

class BinaryExpression : public Expression {
public:
    ~BinaryExpression() override = default;

    void visit(ExpressionVisitor& visitor) const override;

    std::string const& getOperator() const;
    Expression const& getLeft() const;
    Expression const& getRight() const;

protected:
    BinaryExpression(std::string const& operatorr, std::unique_ptr<Expression>&& left,
            std::unique_ptr<Expression>&& right);

    std::string operator_;
    std::unique_ptr<Expression> left_;
    std::unique_ptr<Expression> right_;

};

} // namespace expression
} // namespace engine

#endif //OKNO_2019_ADVANCED_CPP_BINARYEXPRESSION_H
