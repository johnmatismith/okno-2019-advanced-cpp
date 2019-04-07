//
// Created by mr on 25.03.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_PRIMARYEXPRESSION_H
#define OKNO_2019_ADVANCED_CPP_PRIMARYEXPRESSION_H

#include "engine/expression/Expression.h"


namespace engine {
namespace expression {

class ConstantExpression : public Expression {
public:
    explicit ConstantExpression(Value const& value);

    Value evaluate(Record const& record) const override;
    void visit(ExpressionVisitor& visitor) const override;

    Value const& getValue() const;

private:
    Value value_;
};

} // namespace expression
} // namespace engine


#endif //OKNO_2019_ADVANCED_CPP_PRIMARYEXPRESSION_H
