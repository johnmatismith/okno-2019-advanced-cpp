//
// Created by mr on 25.03.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_PARSER_H
#define OKNO_2019_ADVANCED_CPP_PARSER_H

#include <memory>
#include <engine/expression/ValueFactory.h>

#include "engine/ParseException.h"
#include "engine/TokenType.h"
#include "engine/expression/Expression.h"
#include "engine/expression/ConstantExpression.h"
#include "engine/expression/EqualExpression.h"
#include "engine/expression/NotEqualExpression.h"
#include "engine/expression/Value.h"
#include "engine/expression/VariableExpression.h"


namespace engine {
namespace parser {


/**
 * PRIMARY:
 *      STRING & NUMBER & IDENTIFIER
 *
 * GROUPING:
 *      PARENTHESIS_OPEN & PARENTHESIS_CLOSE,
 *
 * COMPARISION:
 *      LESS & GREATER & EQUAL & NOT_EQUAL & LESS_EQUAL & GREATER_EQUAL
 *
 * AND
 *
 * OR
 */
class Parser {

public:
    template <typename InputIterator>
    std::unique_ptr<expression::Expression> parse(InputIterator begin, InputIterator end);

private:
    template <typename InputIterator>
    std::unique_ptr<expression::Expression> parseOr(InputIterator& begin, InputIterator end);

    template <typename InputIterator>
    std::unique_ptr<expression::Expression> parseAnd(InputIterator& begin, InputIterator end);

    template <typename InputIterator>
    std::unique_ptr<expression::Expression> parseComparision(InputIterator& begin, InputIterator end);

    template <typename InputIterator>
    std::unique_ptr<expression::Expression> parseGrouping(InputIterator& begin, InputIterator end);

    template <typename InputIterator>
    std::unique_ptr<expression::Expression> parsePrimary(InputIterator& begin, InputIterator end);

};

template<typename InputIterator>
std::unique_ptr<expression::Expression> Parser::parse(InputIterator begin, InputIterator end) {
    return parseOr(begin, end);
}

template<typename InputIterator>
std::unique_ptr<expression::Expression> Parser::parseOr(InputIterator& begin, InputIterator end) {
    return parseAnd(begin, end);
}

template<typename InputIterator>
std::unique_ptr<expression::Expression> Parser::parseAnd(InputIterator& begin, InputIterator end) {
    return parseComparision(begin, end);
}

template<typename InputIterator>
std::unique_ptr<expression::Expression> Parser::parseComparision(InputIterator& begin, InputIterator end) {
    auto left = parseGrouping(begin, end);

    auto const operatorr = begin;

    if (operatorr == end || (begin->getType() != TokenType::EQUAL && begin->getType() != TokenType::NOT_EQUAL)) {
        return std::move(left);
    }

    auto right = parseGrouping(++begin, end);

    if (!right) {
        throw ParseException("Missing right operand for comparision operation", operatorr->getLocation());
    }

    switch (operatorr->getType()) {
        case TokenType::EQUAL:
            return std::make_unique<expression::EqualExpression>(std::move(left), std::move(right));

        case TokenType::NOT_EQUAL:
            return std::make_unique<expression::NotEqualExpression>(std::move(left), std::move(right));
    }

}

template<typename InputIterator>
std::unique_ptr<expression::Expression> Parser::parseGrouping(InputIterator& begin, InputIterator end) {
    return parsePrimary(begin, end);
}

template<typename InputIterator>
std::unique_ptr<expression::Expression> Parser::parsePrimary(InputIterator& begin, InputIterator end) {

    if (begin == end) {
        return std::unique_ptr<expression::Expression>();
    }

    switch (begin->getType()) {
        case TokenType::STRING:
        case TokenType::NUMBER:
            return std::make_unique<expression::ConstantExpression>(
                    expression::ValueFactory::fromConstantToken(*begin++));

        case TokenType::IDENTIFIER:
            return std::make_unique<expression::VariableExpression>(begin++->getValue());
    }

    throw ParseException("Expected identifier or value", begin->getLocation());
}

} // namespace parser
} // namespace engine

#endif //OKNO_2019_ADVANCED_CPP_PARSER_H
