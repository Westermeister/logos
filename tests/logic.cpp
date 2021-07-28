#include "catch.hpp"

#include "../src/logic.hpp"

TEST_CASE("Test logic::AND") {
  REQUIRE(logic::AND("0", "0") == "0");
  REQUIRE(logic::AND("0", "1") == "0");
  REQUIRE(logic::AND("1", "0") == "0");
  REQUIRE(logic::AND("1", "1") == "1");
}

TEST_CASE("Test logic::OR") {
  REQUIRE(logic::OR("0", "0") == "0");
  REQUIRE(logic::OR("0", "1") == "1");
  REQUIRE(logic::OR("1", "0") == "1");
  REQUIRE(logic::OR("1", "1") == "1");
}

TEST_CASE("Test logic::XOR") {
  REQUIRE(logic::XOR("0", "0") == "0");
  REQUIRE(logic::XOR("0", "1") == "1");
  REQUIRE(logic::XOR("1", "0") == "1");
  REQUIRE(logic::XOR("1", "1") == "0");
}

TEST_CASE("Test logic::NOT") {
  REQUIRE(logic::NOT("0") == "1");
  REQUIRE(logic::NOT("1") == "0");
}

TEST_CASE("Test logic::NAND") {
  REQUIRE(logic::NAND("0", "0") == "1");
  REQUIRE(logic::NAND("0", "1") == "1");
  REQUIRE(logic::NAND("1", "0") == "1");
  REQUIRE(logic::NAND("1", "1") == "0");
}

TEST_CASE("Test logic::NOR") {
  REQUIRE(logic::NOR("0", "0") == "1");
  REQUIRE(logic::NOR("0", "1") == "0");
  REQUIRE(logic::NOR("1", "0") == "0");
  REQUIRE(logic::NOR("1", "1") == "0");
}

TEST_CASE("Test logic::XNOR") {
  REQUIRE(logic::XNOR("0", "0") == "1");
  REQUIRE(logic::XNOR("0", "1") == "0");
  REQUIRE(logic::XNOR("1", "0") == "0");
  REQUIRE(logic::XNOR("1", "1") == "1");
}
