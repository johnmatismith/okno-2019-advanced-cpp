//
// Created by mr on 07.04.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_VARIABLEEXPRESSION_H
#define OKNO_2019_ADVANCED_CPP_VARIABLEEXPRESSION_H


#include "engine/expression/Expression.h"


namespace engine {
namespace expression {

class VariableExpression : public Expression {
public:
    explicit VariableExpression(std::string const& identifier);
    ~VariableExpression() override = default;

    Value evaluate(Record const& record) const override;
    void visit(ExpressionVisitor& visitor) const override;

    std::string const& getIdentifier() const;

private:
    std::string identifier_;
};

} // namespace expression
} // namespace engine

#endif //OKNO_2019_ADVANCED_CPP_VARIABLEEXPRESSION_H
