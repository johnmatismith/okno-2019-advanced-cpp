//
// Created by mr on 24.02.19.
//

#include <engine/expression/FieldEqualExpression.h>

#include "engine/expression/FieldEqualExpression.h"

namespace engine {
namespace expression {

FieldEqualExpression::FieldEqualExpression(std::string const& key, std::string const& value)
        : key_(key),
          value_(value) {
}

bool FieldEqualExpression::evaluate(Expression::Record const& record) const {
    auto it = record.find(key_);

    if (it == record.end()) {
        return false;
    }

    return value_ == it->second;
}

} // namespace expression
} // namespace engine
