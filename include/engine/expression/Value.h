//
// Created by mr on 07.04.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_VALUE_H
#define OKNO_2019_ADVANCED_CPP_VALUE_H

#include <string>
#include <variant>

namespace engine {
namespace expression {

/**
 * Typ wykorzystywany do przedstawienia wartości wyrażenia
 */
typedef std::variant<std::monostate, std::string, long, bool> Value;

} // namespace expression
} // namespace engine

#endif //OKNO_2019_ADVANCED_CPP_VALUE_H
