//
// Created by mr on 24.03.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_LEXER_H
#define OKNO_2019_ADVANCED_CPP_LEXER_H

#include <memory>
#include <string>
#include <vector>
#include <algorithm>

#include "engine/ParseException.h"

#include "Tokenizer.h"


namespace engine {
namespace lexer {

class Lexer {

public:
    Lexer();

    template <typename OutputIterator>
    void tokenize(std::string const& input, OutputIterator output) const;

private:
    std::vector<std::unique_ptr<lexer::Tokenizer<std::string::const_iterator>>> tokenizers_;

};

namespace {

std::optional<Token> tryTokenize(std::string::const_iterator begin, std::string::const_iterator current,
        std::string::const_iterator end,
        std::vector<std::unique_ptr<lexer::Tokenizer<std::string::const_iterator>>> const& tokenizers) {
    
    for (auto& tokenizer : tokenizers) {

        auto maybeToken = tokenizer->parse(begin, current, end);

        if (maybeToken.has_value()) {
            return maybeToken;
        }
    }

    return std::optional<Token>();
}
    
} // namespace

template<typename OutputIterator>
void Lexer::tokenize(std::string const& input, OutputIterator output) const {

    auto begin = input.begin();
    auto it = begin;
    auto end = input.end();

    while (it != end) {

        auto maybeToken = tryTokenize(begin, it, end, tokenizers_);

        if (!maybeToken.has_value()) {
            throw ParseException("Unrecognized token", Location::fromIterator(begin, it));
        }

        if (maybeToken->getType() != TokenType::WHITESPACE) {
            *output = *maybeToken;
        }

        std::advance(it, maybeToken->getValue().size());
    }

}

} // namespace lexer
} // namespace engine

#endif //OKNO_2019_ADVANCED_CPP_LEXER_H
