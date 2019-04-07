//
// Created by mr on 24.03.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_IDENTIFIERTOKENIZER_H
#define OKNO_2019_ADVANCED_CPP_IDENTIFIERTOKENIZER_H

#include <set>

#include "Tokenizer.h"


namespace engine {
namespace lexer {

template <typename InputIterator>
class CharacterSetTokenizer : public Tokenizer<InputIterator> {

public:
    CharacterSetTokenizer(TokenType tokenType, std::set<char> characters);
    CharacterSetTokenizer(TokenType tokenType, std::set<char> startCharacters, std::set<char> characters);

    std::optional<Token> parse(InputIterator begin, InputIterator current, InputIterator end) override;

private:
    std::set<char> const& getStartCharacterSet() const;

    TokenType tokenType_;
    std::set<char> startCharacters_;
    std::set<char> characters_;

};

template <typename InputIterator>
CharacterSetTokenizer<InputIterator>::CharacterSetTokenizer(TokenType tokenType, std::set<char> characters)
        : tokenType_(tokenType),
          characters_(std::move(characters)) {
}

template <typename InputIterator>
CharacterSetTokenizer<InputIterator>::CharacterSetTokenizer(TokenType tokenType, std::set<char> startCharacters,
                                                            std::set<char> characters)
        : tokenType_(tokenType),
          startCharacters_(std::move(startCharacters)),
          characters_(std::move(characters)) {
}

template <typename InputIterator>
std::optional<Token> CharacterSetTokenizer<InputIterator>::parse(InputIterator begin, InputIterator current,
                                                                 InputIterator end) {

    if (getStartCharacterSet().count(*current) == 0) {
        return std::optional<Token>();
    }

    auto identifierBegin = current;

    while (++current != end && characters_.count(*current)) {
        // do nothing
    }

    return std::make_optional<Token>(tokenType_, Location::fromIterator(begin, identifierBegin),
                                     std::string(identifierBegin, current));
}

template <typename InputIterator>
std::set<char> const& CharacterSetTokenizer<InputIterator>::getStartCharacterSet() const {

    if (startCharacters_.empty()) {
        return characters_;
    }

    return startCharacters_;
}

} // namespace lexer
} // namespace engine


#endif //OKNO_2019_ADVANCED_CPP_IDENTIFIERTOKENIZER_H
