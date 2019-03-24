//
// Created by mr on 24.02.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_EXPRESSIONPARSER_H
#define OKNO_2019_ADVANCED_CPP_EXPRESSIONPARSER_H


#include "engine/expression/Expression.h"

#include <memory>
#include <string>

namespace engine {

class ExpressionParser {

public:
    static std::unique_ptr<expression::Expression> parse(std::string const& expression);

};

} // namespace engine


#endif //OKNO_2019_ADVANCED_CPP_EXPRESSIONPARSER_H
