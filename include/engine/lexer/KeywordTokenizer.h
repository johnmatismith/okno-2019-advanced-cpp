//
// Created by mr on 24.03.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_KEYWORDTOKENIZER_H
#define OKNO_2019_ADVANCED_CPP_KEYWORDTOKENIZER_H

namespace engine {
namespace lexer {

template <typename InputIterator>
class KeywordTokenizer : public Tokenizer<InputIterator> {

public:
    KeywordTokenizer(TokenType tokenType, std::string keyword);
    KeywordTokenizer(TokenType tokenType, char const* keyword);

    std::optional<Token> parse(InputIterator begin, InputIterator current, InputIterator end) override;

private:
    TokenType tokenType_;
    std::string keyword_;

};

template <typename InputIterator>
KeywordTokenizer<InputIterator>::KeywordTokenizer(TokenType tokenType, std::string keyword)
        : tokenType_(tokenType),
          keyword_(std::move(keyword)) {
}

template <typename InputIterator>
KeywordTokenizer<InputIterator>::KeywordTokenizer(TokenType tokenType, char const* keyword)
        : tokenType_(tokenType),
          keyword_(keyword) {
}

template <typename InputIterator>
std::optional<Token> KeywordTokenizer<InputIterator>::parse(InputIterator begin, InputIterator current, InputIterator end) {
    if (std::distance(current, end) < keyword_.size()) {
        return std::optional<Token>();
    }

    if (!std::equal(keyword_.begin(), keyword_.end(), current)) {
        return std::optional<Token>();
    }

    return std::make_optional<Token>(tokenType_, Location::fromIterator(begin, current), keyword_);
}

} // namespace lexer
} // namespace engine


#endif //OKNO_2019_ADVANCED_CPP_KEYWORDTOKENIZER_H
