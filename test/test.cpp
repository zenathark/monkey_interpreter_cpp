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
)";

TEST_CASE("READS ALL TOKENS") {
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
