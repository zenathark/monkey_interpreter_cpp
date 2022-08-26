#include <cstdio>
#include <stdexcept>

#include "../include/token.hpp"
#include "../include/lexer.hpp"

using namespace monkeycpp;
using namespace monkeycpp::lexer;

Lexer::Lexer(const std::string& input) : input(input), position(0), read_position(0) {
  read_char();
}

void Lexer::read_char() {
  if (read_position >= input.length()) {
    ch = 0;
  } else {
    ch = input[read_position];
  }

  position = read_position;
  ++read_position;
}

token::Token Lexer::next_token() {
  token::Token tok;
  switch (ch) {
    case '=':
      tok = token::Token(token::ASSIGN, std::string(1, ch));
      break;
    case ';':
      tok = token::Token(token::SEMICOLON, std::string(1, ch));
      break;
    case '(':
      tok = token::Token(token::LPAREN, std::string(1, ch));
      break;
    case ')':
      tok = token::Token(token::RPAREN, std::string(1, ch));
      break;
    case ',':
      tok = token::Token(token::COMMA, std::string(1, ch));
      break;
    case '+':
      tok = token::Token(token::PLUS, std::string(1, ch));
      break;
    case '}':
      tok = token::Token(token::RBRACE, std::string(1, ch));
      break;
    case '{':
      tok = token::Token(token::LBRACE, std::string(1, ch));
      break;
    case 0:
      tok = token::Token(token::_EOF, "");
      break;
    default:
      throw std::logic_error("Unknown token token:" + std::string(1, ch));
      break;
  }
  read_char();
  return tok;
}
