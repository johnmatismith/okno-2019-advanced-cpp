//
// Created by mr on 24.02.19.
//

#include <engine/FieldEqualExpression.h>

#include "engine/FieldEqualExpression.h"

namespace engine {

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

} // namespace engine
