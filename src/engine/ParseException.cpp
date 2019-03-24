//
// Created by mr on 24.03.19.
//

#include <sstream>

#include "engine/ParseException.h"


namespace engine {

ParseException::ParseException(std::string const& message, Location const& location)
        : message_(message),
          location_(location) {
    std::ostringstream oss(message, std::ios_base::ate);
    oss << " at offset "
        << location.getOffset();

    what_ = oss.str();
}

std::string const& ParseException::getMessage() const {
    return message_;
}

Location const& ParseException::getLocation() const {
    return location_;
}

char const* ParseException::what() const noexcept {
    return what_.c_str();
}

} // namespace engine
