//
// Created by mr on 24.02.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_SCANNER_H
#define OKNO_2019_ADVANCED_CPP_SCANNER_H

#include "Expression.h"

#include <algorithm>


namespace engine {

template <typename Database>
class Scanner {
public:
    explicit Scanner(Database const& database);

    template <typename OutputIterator>
    void scan(Expression const& expression, OutputIterator iterator) const;

private:
    Database const& database_;
};

template <typename Database>
Scanner<Database>::Scanner(Database const& database)
        : database_(database) {
}

template <typename Database>
template <typename OutputIterator>
void Scanner<Database>::scan(Expression const& expression, OutputIterator iterator) const {
    std::copy_if(database_.begin(), database_.end(), iterator,
            [&expression] (auto const& record) { return expression.evaluate(record); });
}

} // namespace engine


#endif //OKNO_2019_ADVANCED_CPP_SCANNER_H
