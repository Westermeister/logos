/**
 * Tests for the ALU.
 * Copyright (c) 2021 Westermeister.
 */

#include <string>

#include "catch.hpp"

#include "../src/alu.hpp"

ALU alu;

// Some helpful constants to use during testing for readability.

// Operands.
const std::string VALUE_0(64, '0');
const std::string VALUE_1(64, '1');
const std::string VALUE_0_HALF =
    "0000000000000000000000000000000011111111111111111111111111111111";
const std::string VALUE_1_HALF =
    "1111111111111111111111111111111100000000000000000000000000000000";
const std::string VALUE_01 =
    "0101010101010101010101010101010101010101010101010101010101010101";
const std::string VALUE_10 =
    "1010101010101010101010101010101010101010101010101010101010101010";
const std::string VALUE_SINGLE =
    "0000000000000000000000000000000000000000000000000000000000000001";

// Carry-in bits.
const std::string CIN_0 = "0";
const std::string CIN_1 = "1";

// Invert bits.
const std::string INVERT_A = "1";
const std::string NO_INVERT_A = "0";
const std::string INVERT_B = "1";
const std::string NO_INVERT_B = "0";

// Opcodes.
const std::string OPCODE_AND = "000";
const std::string OPCODE_OR = "001";
const std::string OPCODE_XOR = "010";
const std::string OPCODE_ADD = "011";
const std::string OPCODE_LESS_THAN = "100";

// Test logic gate operations.

TEST_CASE("Test AND operation") {
  std::string TEST_1 =
      alu.run(VALUE_0 + VALUE_1, CIN_0, NO_INVERT_A, NO_INVERT_B, OPCODE_AND)
          .substr(0, 64);
  std::string TEST_2 = alu.run(VALUE_0_HALF + VALUE_1_HALF, CIN_0, NO_INVERT_A,
                               NO_INVERT_B, OPCODE_AND)
                           .substr(0, 64);
  std::string TEST_3 =
      alu.run(VALUE_01 + VALUE_10, CIN_0, NO_INVERT_A, NO_INVERT_B, OPCODE_AND)
          .substr(0, 64);
  REQUIRE(TEST_1 == VALUE_0);
  REQUIRE(TEST_2 == VALUE_0);
  REQUIRE(TEST_3 == VALUE_0);
}

TEST_CASE("Test OR operation") {
  std::string TEST_1 =
      alu.run(VALUE_0 + VALUE_1, CIN_0, NO_INVERT_A, NO_INVERT_B, OPCODE_OR)
          .substr(0, 64);
  std::string TEST_2 = alu.run(VALUE_0_HALF + VALUE_1_HALF, CIN_0, NO_INVERT_A,
                               NO_INVERT_B, OPCODE_OR)
                           .substr(0, 64);
  std::string TEST_3 =
      alu.run(VALUE_01 + VALUE_10, CIN_0, NO_INVERT_A, NO_INVERT_B, OPCODE_OR)
          .substr(0, 64);
  REQUIRE(TEST_1 == VALUE_1);
  REQUIRE(TEST_2 == VALUE_1);
  REQUIRE(TEST_3 == VALUE_1);
}

TEST_CASE("Test XOR operation") {
  std::string TEST_1 =
      alu.run(VALUE_0 + VALUE_1, CIN_0, NO_INVERT_A, NO_INVERT_B, OPCODE_XOR)
          .substr(0, 64);
  std::string TEST_2 = alu.run(VALUE_0_HALF + VALUE_1_HALF, CIN_0, NO_INVERT_A,
                               NO_INVERT_B, OPCODE_XOR)
                           .substr(0, 64);
  std::string TEST_3 =
      alu.run(VALUE_01 + VALUE_10, CIN_0, NO_INVERT_A, NO_INVERT_B, OPCODE_XOR)
          .substr(0, 64);
  REQUIRE(TEST_1 == VALUE_1);
  REQUIRE(TEST_2 == VALUE_1);
  REQUIRE(TEST_3 == VALUE_1);
}

TEST_CASE("Test NOT operation") {
  std::string TEST_1 =
      alu.run(VALUE_0 + VALUE_1, CIN_0, INVERT_A, NO_INVERT_B, OPCODE_AND)
          .substr(0, 64);
  std::string TEST_2 =
      alu.run(VALUE_1 + VALUE_1, CIN_0, INVERT_A, NO_INVERT_B, OPCODE_AND)
          .substr(0, 64);
  REQUIRE(TEST_1 == VALUE_1);
  REQUIRE(TEST_2 == VALUE_0);
}

TEST_CASE("Test NAND operation") {
  std::string TEST_1 =
      alu.run(VALUE_0 + VALUE_1, CIN_0, INVERT_A, INVERT_B, OPCODE_OR)
          .substr(0, 64);
  std::string TEST_2 = alu.run(VALUE_0_HALF + VALUE_1_HALF, CIN_0, NO_INVERT_A,
                               NO_INVERT_B, OPCODE_OR)
                           .substr(0, 64);
  std::string TEST_3 =
      alu.run(VALUE_01 + VALUE_10, CIN_0, INVERT_A, INVERT_B, OPCODE_OR)
          .substr(0, 64);
  REQUIRE(TEST_1 == VALUE_1);
  REQUIRE(TEST_2 == VALUE_1);
  REQUIRE(TEST_3 == VALUE_1);
}

TEST_CASE("Test NOR operation") {
  std::string TEST_1 =
      alu.run(VALUE_0 + VALUE_1, CIN_0, INVERT_A, INVERT_B, OPCODE_AND)
          .substr(0, 64);
  std::string TEST_2 = alu.run(VALUE_0_HALF + VALUE_1_HALF, CIN_0, NO_INVERT_A,
                               NO_INVERT_B, OPCODE_AND)
                           .substr(0, 64);
  std::string TEST_3 =
      alu.run(VALUE_01 + VALUE_10, CIN_0, INVERT_A, INVERT_B, OPCODE_AND)
          .substr(0, 64);
  REQUIRE(TEST_1 == VALUE_0);
  REQUIRE(TEST_2 == VALUE_0);
  REQUIRE(TEST_3 == VALUE_0);
}

TEST_CASE("Test XNOR operation") {
  std::string TEST_1 =
      alu.run(VALUE_0 + VALUE_1, CIN_0, INVERT_A, NO_INVERT_B, OPCODE_XOR)
          .substr(0, 64);
  std::string TEST_2 = alu.run(VALUE_0_HALF + VALUE_1_HALF, CIN_0, NO_INVERT_A,
                               NO_INVERT_B, OPCODE_XOR)
                           .substr(0, 64);
  std::string TEST_3 =
      alu.run(VALUE_01 + VALUE_10, CIN_0, INVERT_A, NO_INVERT_B, OPCODE_XOR)
          .substr(0, 64);
  REQUIRE(TEST_1 == VALUE_0);
  REQUIRE(TEST_2 == VALUE_1);
  REQUIRE(TEST_3 == VALUE_0);
}

// Test other operations.

TEST_CASE("Test less-than operation") {
  std::string TEST_1 =
      alu.run(VALUE_1 + VALUE_0, CIN_1, NO_INVERT_A, INVERT_B, OPCODE_LESS_THAN)
          .substr(0, 64);
  std::string TEST_2 =
      alu.run(VALUE_0 + VALUE_1, CIN_1, NO_INVERT_A, INVERT_B, OPCODE_LESS_THAN)
          .substr(0, 64);
  REQUIRE(TEST_1 == VALUE_SINGLE);
  REQUIRE(TEST_2 == VALUE_0);
}

TEST_CASE("Test addition") {
  std::string TEST_1 =
      alu.run(VALUE_0 + VALUE_1, CIN_0, NO_INVERT_A, NO_INVERT_B, OPCODE_ADD)
          .substr(0, 64);
  std::string TEST_2 = alu.run(VALUE_0_HALF + VALUE_1_HALF, CIN_0, NO_INVERT_A,
                               NO_INVERT_B, OPCODE_ADD)
                           .substr(0, 64);
  std::string TEST_3 = alu.run(VALUE_0 + VALUE_0_HALF, CIN_0, NO_INVERT_A,
                               NO_INVERT_B, OPCODE_ADD)
                           .substr(0, 64);
  REQUIRE(TEST_1 == VALUE_1);
  REQUIRE(TEST_2 == VALUE_1);
  REQUIRE(TEST_3 == VALUE_0_HALF);
}
