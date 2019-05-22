//
// Created by mr on 25.03.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_PARSER_H
#define OKNO_2019_ADVANCED_CPP_PARSER_H

#include <memory>

#include "engine/ParseException.h"
#include "engine/TokenType.h"
#include "engine/expression/AndExpression.h"
#include "engine/expression/ConstantExpression.h"
#include "engine/expression/EqualExpression.h"
#include "engine/expression/Expression.h"
#include "engine/expression/GreaterExpression.h"
#include "engine/expression/GreaterEqualExpression.h"
#include "engine/expression/LessExpression.h"
#include "engine/expression/LessEqualExpression.h"
#include "engine/expression/NotEqualExpression.h"
#include "engine/expression/OrExpression.h"
#include "engine/expression/Value.h"
#include "engine/expression/ValueFactory.h"
#include "engine/expression/VariableExpression.h"


namespace engine {
namespace parser {

namespace internal {

bool isComparision(TokenType tokenType) {

    switch (tokenType) {
        case EQUAL:
        case NOT_EQUAL:
        case LESS:
        case LESS_EQUAL:
        case GREATER:
        case GREATER_EQUAL:
            return true;

        case AND:
        case OR:
        case STRING:
        case NUMBER:
        case PARENTHESIS_OPEN:
        case PARENTHESIS_CLOSE:
        case IDENTIFIER:
        case WHITESPACE:
            return false;
    }
}

} // namespace internal

/**
 * Parser Recursive descent (przeszukiwanie wgłąb).
 * Zamienia listę leksemów na wyrażenie (Expression).
 * Dba o kolejność wykonywania działań.
 *
 * Źródło: http://www.craftinginterpreters.com/
 *
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
    auto result = parseOr(begin, end);

    if (begin != end) {
        throw ParseException("Unexpected token", begin->getLocation());
    }

    return result;
}

template<typename InputIterator>
std::unique_ptr<expression::Expression> Parser::parseOr(InputIterator& begin, InputIterator end) {

    auto result = parseAnd(begin, end);
    auto operatorr = begin;

    while (operatorr != end && begin->getType() == TokenType::OR) {

        auto right = parseAnd(++begin, end);

        if (!right) {
            throw ParseException("Missing right operand for || operation", operatorr->getLocation());
        }

        result = std::make_unique<expression::OrExpression>(std::move(result), std::move(right));

        operatorr = begin;
    }

    return std::move(result);

}

template<typename InputIterator>
std::unique_ptr<expression::Expression> Parser::parseAnd(InputIterator& begin, InputIterator end) {

    auto result = parseComparision(begin, end);
    auto operatorr = begin;

    while (operatorr != end && begin->getType() == TokenType::AND) {

        auto right = parseComparision(++begin, end);

        if (!right) {
            throw ParseException("Missing right operand for && operation", operatorr->getLocation());
        }

        result = std::make_unique<expression::AndExpression>(std::move(result), std::move(right));

        operatorr = begin;
    }

    return std::move(result);
}

template<typename InputIterator>
std::unique_ptr<expression::Expression> Parser::parseComparision(InputIterator& begin, InputIterator end) {

    auto left = parseGrouping(begin, end);
    auto const operatorr = begin;

    if (operatorr == end || !internal::isComparision(begin->getType())) {
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

        case TokenType::LESS:
            return std::make_unique<expression::LessExpression>(std::move(left), std::move(right));

        case TokenType::LESS_EQUAL:
            return std::make_unique<expression::LessEqualExpression>(std::move(left), std::move(right));

        case TokenType::GREATER:
            return std::make_unique<expression::GreaterExpression>(std::move(left), std::move(right));

        case TokenType::GREATER_EQUAL:
            return std::make_unique<expression::GreaterEqualExpression>(std::move(left), std::move(right));
    }
}

template<typename InputIterator>
std::unique_ptr<expression::Expression> Parser::parseGrouping(InputIterator& begin, InputIterator end) {

    if (begin == end || begin->getType() != TokenType::PARENTHESIS_OPEN) {
        return parsePrimary(begin, end);
    }

    auto const open = begin;

    auto result = parseOr(++begin, end);

    if (begin == end) {
        throw ParseException("No matching ')'", open->getLocation());
    }

    if (begin->getType() != TokenType::PARENTHESIS_CLOSE) {
        throw ParseException("Unexpected token - ')' was expected", begin->getLocation());
    }

    ++begin;

    return std::move(result);
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
