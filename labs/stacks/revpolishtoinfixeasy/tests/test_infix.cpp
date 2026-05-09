#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "../src/infix.hpp"

TEST_CASE("Test InfixConverter with simple + expressions")
{
    InfixConverter converter;
    converter.process_token("3");
    converter.process_token("4");
    converter.process_token("+");
    CHECK(converter.get_infix_expression() == "(3+4)");
}

TEST_CASE("Test InfixConverter with mixed operators")
{
    InfixConverter converter;
    converter.process_token("5");
    converter.process_token("2");
    converter.process_token("*");
    converter.process_token("3");
    converter.process_token("+");
    CHECK(converter.get_infix_expression() == "((5*2)+3)");
}

// FIXME: Add more test cases to cover different scenarios, such as multiple operators and nested expressions
