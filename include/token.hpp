#ifndef TOKEN_H_
#define TOKEN_H_

#include <string>

namespace monkeycpp::token {

  typedef std::string token_type;

  const std::string ILLEGAL = "ILLEGAL";
  const std::string _EOF = "EOF";

  // Identifiers + literals
  const std::string IDENT = "IDENT";
  const std::string INT = "INT";

  // Operators
  const std::string ASSIGN = "=";
  const std::string PLUS = "+";

  // Delimiters
  const std::string COMMA = ",";
  const std::string SEMICOLON = ";";

  const std::string LPAREN = "(";
  const std::string RPAREN = ")";
  const std::string LBRACE = "{";
  const std::string RBRACE = "}";

  // Keywords
  const std::string FUNCTION = "FUNCTION";
  const std::string LET = "LET";

  struct Token {
    token_type type;
    std::string literal;

    Token(const std::string& input);
    Token(token_type type, std::string literal) : type(type), literal(literal) {}
    Token() : type(_EOF), literal("") {}

    Token(const Token& other) = default;

    Token(Token&& other) = default;

    Token& operator=(const Token& other) {
      if (&other != this) {
        type = other.type;
        literal = other.literal;
      }
      return *this;
    };

    ~Token() = default;

  };


}


#endif // TOKEN_H_
