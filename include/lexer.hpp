#ifndef LEXER_H_
#define LEXER_H_

#include "token.hpp"
#include <string>

namespace monkeycpp::lexer {
  struct Lexer {
    std::string input;
    size_t position;
    size_t read_position;
    char ch;

    Lexer(const std::string& input);

    void read_char();
    token::Token next_token();
  };
}

#endif // LEXER_H_
