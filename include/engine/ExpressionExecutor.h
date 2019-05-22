//
// Created by mr on 24.02.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_SCANNER_H
#define OKNO_2019_ADVANCED_CPP_SCANNER_H

#include "engine/expression/Expression.h"

#include <algorithm>


namespace engine {

/**
 * Klasa filtrująca bazę danych, poprzez wykonanie na każdym jej rekordzie podanego wyrażenia i sprawdzenia jego wyniku
 */
template <typename Database>
class ExpressionExecutor {
public:
    template <typename OutputIterator>
    void execute(Database const& database, expression::Expression const &expression, OutputIterator iterator) const;
};

template <typename Database>
template <typename OutputIterator>
void ExpressionExecutor<Database>::execute(Database const& database, expression::Expression const& expression,
        OutputIterator iterator) const {

    std::copy_if(database.begin(), database.end(), iterator,
            [&expression] (auto const& record) {

                auto const result = expression.evaluate(record);

                if (std::holds_alternative<std::monostate>(result)) {
                    return false;
                }

                if (std::holds_alternative<bool>(result)) {
                    return std::get<bool>(result);
                }

                return true;
    });
}

} // namespace engine


#endif //OKNO_2019_ADVANCED_CPP_SCANNER_H
