//
// Created by mr on 24.02.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_FIELDEQUALEXPRESSION_H
#define OKNO_2019_ADVANCED_CPP_FIELDEQUALEXPRESSION_H

#include "engine/Expression.h"


namespace engine {

class FieldEqualExpression : public Expression {

public:
    FieldEqualExpression(std::string const& key, std::string const& value);

    bool evaluate(Record const& record) const override;

private:
    std::string key_;
    std::string value_;
};

} // namespace engine


#endif //OKNO_2019_ADVANCED_CPP_FIELDEQUALEXPRESSION_H
