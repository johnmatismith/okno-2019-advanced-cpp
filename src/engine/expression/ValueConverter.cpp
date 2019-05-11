//
// Created by mr on 11.05.19.
//

#include "engine/expression/ValueConverter.h"


namespace engine {
namespace expression {

std::optional<long> ValueConverter::toNumber(Value const &value) {

    if (std::holds_alternative<long>(value)) {
        return std::get<long>(value);
    }

    if (std::holds_alternative<std::string>(value)) {
        try {
            return std::stol(std::get<std::string>(value));
        } catch (std::invalid_argument const& e) {
            // conversion failed
            return std::optional<long>();
        }
    }

    return std::optional<long>();
}

} // namespace expression
} // namespace engine
