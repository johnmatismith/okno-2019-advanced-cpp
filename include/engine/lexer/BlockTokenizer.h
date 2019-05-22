//
// Created by mr on 24.03.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_STRINGTOKENIZER_H
#define OKNO_2019_ADVANCED_CPP_STRINGTOKENIZER_H

#include "Tokenizer.h"

#include <sstream>

#include "engine/ParseException.h"


namespace engine {
namespace lexer {

/**
 * Implementacja Tokenizer wyszukująca leksemy w postaci bloku nie parsowanych zamkniętego podanymi ogranicznikami,
 * np. cudzysłowami
 */
template <typename InputIterator>
class BlockTokenizer : public Tokenizer<InputIterator> {

public:
    BlockTokenizer(TokenType tokenType, char terminator);

    std::optional<Token> parse(InputIterator begin, InputIterator current, InputIterator end) override;

private:
    TokenType tokenType_;
    char terminator_;

};

namespace {

std::string constructErrorString(TokenType tokenType) {
    std::ostringstream string("Unterminated ", std::ios::ate);
    string << tokenType << " block";
    return string.str();
}

} // namespace

template <typename InputIterator>
BlockTokenizer<InputIterator>::BlockTokenizer(TokenType tokenType, char terminator)
        : tokenType_(tokenType),
          terminator_(terminator) {
}

template <typename InputIterator>
std::optional<Token> BlockTokenizer<InputIterator>::parse(InputIterator begin, InputIterator current,
        InputIterator end) {

    if (*current != terminator_) {
        return std::optional<Token>();
    }

    auto const blockBegin = current;

    // TODO (MR): may support escaping in the future
    auto blockEnd = std::find(++current, end, terminator_);

    if (blockEnd == end) {
        throw ParseException(constructErrorString(tokenType_), Location::fromIterator(begin, blockBegin));
    }

    return std::make_optional<Token>(tokenType_, Location::fromIterator(begin, blockBegin),
                                     std::string(blockBegin, ++blockEnd));
}

} // namespace lexer
} // namespace engine


#endif //OKNO_2019_ADVANCED_CPP_STRINGTOKENIZER_H
