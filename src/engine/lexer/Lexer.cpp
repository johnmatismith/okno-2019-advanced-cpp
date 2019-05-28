//
// Created by mr on 24.03.19.
//

#include "engine/lexer/Lexer.h"

#include "engine/lexer/BlockTokenizer.h"
#include "engine/lexer/KeywordTokenizer.h"
#include "engine/lexer/CharacterSetTokenizer.h"


namespace engine {
namespace lexer {

namespace {

std::set<char> getIdentifiersBeginCharacterSet() {
    static char const characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_";
    return std::set<char>(&characters[0], &characters[sizeof(characters) - 1]);
}

std::set<char> getNumberCharacterSet() {
    static char const characters[] = "1234567890";
    return std::set<char>(&characters[0], &characters[sizeof(characters) - 1]);
}

std::set<char> getIdentifiersCharacterSet() {
    static char const additionalCharacters[] = "1234567890";

    auto set = getIdentifiersBeginCharacterSet();
    set.insert(&additionalCharacters[0], &additionalCharacters[sizeof(additionalCharacters) - 1]);

    return set;
}

std::set<char> getWhitespaceCharacterSet() {
    static char const characters[] = " \r\n\t";
    return std::set<char>(&characters[0], &characters[sizeof(characters) - 1]);
}

} // namespace

Lexer::Lexer() {

    // NOTE (MR): order matters, especially for LESS_EQUAL + LESS and GREATER_EQUAL + GREATER

    tokenizers_.push_back(std::make_unique<KeywordTokenizer<std::string::const_iterator>>(TokenType::LESS_EQUAL, "<="));
    tokenizers_.push_back(std::make_unique<KeywordTokenizer<std::string::const_iterator>>(TokenType::GREATER_EQUAL, ">="));
    tokenizers_.push_back(std::make_unique<KeywordTokenizer<std::string::const_iterator>>(TokenType::LESS, "<"));
    tokenizers_.push_back(std::make_unique<KeywordTokenizer<std::string::const_iterator>>(TokenType::GREATER, ">"));
    tokenizers_.push_back(std::make_unique<KeywordTokenizer<std::string::const_iterator>>(TokenType::EQUAL, "=="));
    tokenizers_.push_back(std::make_unique<KeywordTokenizer<std::string::const_iterator>>(TokenType::NOT_EQUAL, "!="));
    tokenizers_.push_back(std::make_unique<KeywordTokenizer<std::string::const_iterator>>(TokenType::AND, "&&"));
    tokenizers_.push_back(std::make_unique<KeywordTokenizer<std::string::const_iterator>>(TokenType::OR, "||"));
    tokenizers_.push_back(std::make_unique<KeywordTokenizer<std::string::const_iterator>>(TokenType::NOR, "~|"));
    tokenizers_.push_back(std::make_unique<BlockTokenizer<std::string::const_iterator>>(TokenType::STRING, '"'));
    tokenizers_.push_back(std::make_unique<BlockTokenizer<std::string::const_iterator>>(TokenType::STRING, '\''));
    tokenizers_.push_back(
            std::make_unique<CharacterSetTokenizer<std::string::const_iterator>>(TokenType::NUMBER,
                                                                                 getNumberCharacterSet()));
    tokenizers_.push_back(
            std::make_unique<KeywordTokenizer<std::string::const_iterator>>(TokenType::PARENTHESIS_OPEN, "("));
    tokenizers_.push_back(
            std::make_unique<KeywordTokenizer<std::string::const_iterator>>(TokenType::PARENTHESIS_CLOSE, ")"));
    tokenizers_.push_back(
            std::make_unique<CharacterSetTokenizer<std::string::const_iterator>>(TokenType::IDENTIFIER,
                                                                                 getIdentifiersBeginCharacterSet(),
                                                                                 getIdentifiersCharacterSet()));
    tokenizers_.push_back(
            std::make_unique<CharacterSetTokenizer<std::string::const_iterator>>(TokenType::WHITESPACE,
                                                                                 getWhitespaceCharacterSet()));
}

} // namespace lexer
} // namespace engine
