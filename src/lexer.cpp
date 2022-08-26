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

std::string Lexer::read_identifier() {
  size_t position = this->position;
  while (is_letter(ch)) {
    read_char();
  }
  return input.substr(position, this->position - position);
}

bool Lexer::is_letter(char ch) {
  return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ch == '_';
}

token::Token Lexer::next_token() {
  token::Token tok;
  std::printf("Parsing %c", ch);
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
      if (is_letter(ch)) {
        tok.type = token::IDENT;
        tok.literal = read_identifier();
        return tok;
      } else {
        tok.type = token::ILLEGAL;
        tok.literal = ch;
      }
      break;
  }
  read_char();
  return tok;
}
