//
// Created by mr on 24.02.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_SCANNER_H
#define OKNO_2019_ADVANCED_CPP_SCANNER_H

#include "engine/expression/Expression.h"

#include <algorithm>


namespace engine {

template <typename Database>
class ExpressionExecutor {
public:
    explicit ExpressionExecutor(Database const& database);

    template <typename OutputIterator>
    void execute(expression::Expression const &expression, OutputIterator iterator) const;

private:
    Database const& database_;
};

template <typename Database>
ExpressionExecutor<Database>::ExpressionExecutor(Database const& database)
        : database_(database) {
}

template <typename Database>
template <typename OutputIterator>
void ExpressionExecutor<Database>::execute(expression::Expression const& expression, OutputIterator iterator) const {
    std::copy_if(database_.begin(), database_.end(), iterator,
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
