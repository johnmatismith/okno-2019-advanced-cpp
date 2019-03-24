//
// Created by mr on 24.03.19.
//

#include "engine/Location.h"


namespace engine {

Location::Location(long offset)
        : offset_(offset) {
}

long Location::getOffset() const {
    return offset_;
}

} // namespace engine
