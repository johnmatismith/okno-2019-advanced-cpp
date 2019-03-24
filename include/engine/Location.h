//
// Created by mr on 24.03.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_LOCATION_H
#define OKNO_2019_ADVANCED_CPP_LOCATION_H

#include <iterator>

namespace engine {

class Location {

public:
    explicit Location(long offset);

    template <typename InputIterator>
    static Location fromIterator(InputIterator begin, InputIterator current);

    long getOffset() const;

private:
    long offset_;

};

template<typename InputIterator>
Location Location::fromIterator(InputIterator begin, InputIterator current) {
    return Location(std::distance(begin, current));
}

} // namespace engine

#endif //OKNO_2019_ADVANCED_CPP_LOCATION_H
