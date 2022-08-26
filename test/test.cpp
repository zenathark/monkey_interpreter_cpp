#include <catch2/catch_test_macros.hpp>
#include <cstdio>
#include <string>
#include <boost/range/adaptor/indexed.hpp>

#include "token.hpp"
#include "lexer.hpp"


using namespace monkeycpp;

const std::string TOKEN_TEST_INPUT = R"(
let five = 5;
let ten = 10;

let add = fn(x, y) {
  x + y;
};

let result = add(five, ten);
)";

TEST_CASE("READS ALL BASIC TOKENS") {
  std::string input = "=+(){},;";

  struct {
    token::token_type expected_type;
    std::string expected_literal;
  } tests[] = {
    { token::ASSIGN, "=" },
    { token::PLUS, "+" },
    { token::LPAREN, "(" },
    { token::RPAREN, ")" },
    { token::LBRACE, "{" },
    { token::RBRACE, "}" },
    { token::COMMA, "," },
    { token::SEMICOLON, ";" },
    { token::_EOF, "" }
  };

  auto lexer = lexer::Lexer(input);

  for (const auto& [i, expected_token_pair] : tests | boost::adaptors::indexed(0)) {
    auto token = lexer.next_token();
    REQUIRE(token.type == expected_token_pair.expected_type);
    REQUIRE(token.literal == expected_token_pair.expected_literal);
  }
}

TEST_CASE("READ SMALL PROGRAM") {
  struct {
    token::token_type expected_type;
    std::string expected_literal;
  } tests[] = {
    { token::LET, "let" },
    { token::IDENT, "five" },
    { token::ASSIGN, "=" },
    { token::INT, "5" },
    { token::SEMICOLON, ";" },
    { token::LET, "let" },
    { token::IDENT, "ten" },
    { token::ASSIGN, "=" },
    { token::INT, "10" },
    { token::SEMICOLON, ";" },
    { token::LET, "let" },
    { token::IDENT, "add" },
    { token::ASSIGN, "=" },
    { token::FUNCTION, "fn" },
    { token::LPAREN, "(" },
    { token::IDENT, "x" },
    { token::COMMA, "," },
    { token::IDENT, "y" },
    { token::RPAREN, ")" },
    { token::LBRACE, "{" },
    { token::IDENT, "x" },
    { token::PLUS, "+" },
    { token::IDENT, "y" },
    { token::SEMICOLON, ";" },
    { token::RBRACE, "}" },
    { token::SEMICOLON, ";" },
    { token::LET, "let" },
    { token::IDENT, "result" },
    { token::ASSIGN, "=" },
    { token::IDENT, "add" },
    { token::LPAREN, "let" },
    { token::IDENT, "five" },
    { token::COMMA, "," },
    { token::IDENT, "ten" },
    { token::RPAREN, ")" },
    { token::SEMICOLON, ";" },
    { token::_EOF, "" }
  };

  auto lexer = lexer::Lexer(TOKEN_TEST_INPUT);

  for (const auto& [i, expected_token_pair] : tests | boost::adaptors::indexed(0)) {
    auto token = lexer.next_token();
    REQUIRE(token.type == expected_token_pair.expected_type);
    REQUIRE(token.literal == expected_token_pair.expected_literal);
  }
}
