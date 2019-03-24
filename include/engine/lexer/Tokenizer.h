//
// Created by mr on 24.03.19.
//

#ifndef OKNO_2019_ADVANCED_CPP_TOKENIZER_H
#define OKNO_2019_ADVANCED_CPP_TOKENIZER_H

#include <optional>

#include "engine/Token.h"


namespace engine {
namespace lexer {

template <typename InputIterator>
class Tokenizer {

public:
    virtual std::optional<Token> parse(InputIterator begin, InputIterator current, InputIterator end) = 0;

};

} // namespace lexer
} // namespace engine

#endif //OKNO_2019_ADVANCED_CPP_TOKENIZER_H
