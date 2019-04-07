//
// Created by mr on 07.04.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_VALUEFACTORY_H
#define OKNO_2019_ADVANCED_CPP_VALUEFACTORY_H

#include "Value.h"

#include "engine/Token.h"


namespace engine {
namespace expression {

class ValueFactory {
public:
    ValueFactory() = delete;

    static Value fromConstantToken(Token const& token);
    static Value fromStringToken(Token const& token);
    static Value fromNumberToken(Token const& token);
};

} // namespace expression
} // namespace engine

#endif //OKNO_2019_ADVANCED_CPP_VALUEFACTORY_H
