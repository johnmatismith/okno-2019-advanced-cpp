//
// Created by mr on 11.05.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_VALUECONVERTER_H
#define OKNO_2019_ADVANCED_CPP_VALUECONVERTER_H

#include <optional>

#include "Value.h"


namespace engine {
namespace expression {

/**
 * Klasa pomocnicza transformująca typ Value do long (jeżeli możliwe)
 */
class ValueConverter {
public:
    ValueConverter() = delete;

    static std::optional<long> toNumber(Value const &value);
};

} // namespace expression
} // namespace engine




#endif //OKNO_2019_ADVANCED_CPP_VALUECONVERTER_H
