#include "catch.hpp"

#include "../src/logic.hpp"

TEST_CASE("Test logic::AND") {
  REQUIRE(logic::AND("00") == "0");
  REQUIRE(logic::AND("01") == "0");
  REQUIRE(logic::AND("10") == "0");
  REQUIRE(logic::AND("11") == "1");
}

TEST_CASE("Test logic::OR") {
  REQUIRE(logic::OR("00") == "0");
  REQUIRE(logic::OR("01") == "1");
  REQUIRE(logic::OR("10") == "1");
  REQUIRE(logic::OR("11") == "1");
}

TEST_CASE("Test logic::XOR") {
  REQUIRE(logic::XOR("00") == "0");
  REQUIRE(logic::XOR("01") == "1");
  REQUIRE(logic::XOR("10") == "1");
  REQUIRE(logic::XOR("11") == "0");
}

TEST_CASE("Test logic::NOT") {
  REQUIRE(logic::NOT("0") == "1");
  REQUIRE(logic::NOT("1") == "0");
}

TEST_CASE("Test logic::NAND") {
  REQUIRE(logic::NAND("00") == "1");
  REQUIRE(logic::NAND("01") == "1");
  REQUIRE(logic::NAND("10") == "1");
  REQUIRE(logic::NAND("11") == "0");
}

TEST_CASE("Test logic::NOR") {
  REQUIRE(logic::NOR("00") == "1");
  REQUIRE(logic::NOR("01") == "0");
  REQUIRE(logic::NOR("10") == "0");
  REQUIRE(logic::NOR("11") == "0");
}

TEST_CASE("Test logic::XNOR") {
  REQUIRE(logic::XNOR("00") == "1");
  REQUIRE(logic::XNOR("01") == "0");
  REQUIRE(logic::XNOR("10") == "0");
  REQUIRE(logic::XNOR("11") == "1");
}
