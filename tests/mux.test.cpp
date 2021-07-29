/**
 * Tests for multiplexers.
 * Copyright (C) 2021 Westermeister.
 */

#include "catch.hpp"

#include "../src/mux.hpp"

TEST_CASE("Test mux::mux21") {
  REQUIRE(mux::mux21("01", "0") == "0");
  REQUIRE(mux::mux21("01", "1") == "1");
}

TEST_CASE("Test mux::mux41") {
  REQUIRE(mux::mux41("0101", "00") == "0");
  REQUIRE(mux::mux41("0101", "01") == "1");
  REQUIRE(mux::mux41("0101", "10") == "0");
  REQUIRE(mux::mux41("0101", "11") == "1");
}

TEST_CASE("Test mux::mux81") {
  REQUIRE(mux::mux81("01010101", "000") == "0");
  REQUIRE(mux::mux81("01010101", "001") == "1");
  REQUIRE(mux::mux81("01010101", "010") == "0");
  REQUIRE(mux::mux81("01010101", "011") == "1");
  REQUIRE(mux::mux81("01010101", "100") == "0");
  REQUIRE(mux::mux81("01010101", "101") == "1");
  REQUIRE(mux::mux81("01010101", "110") == "0");
  REQUIRE(mux::mux81("01010101", "111") == "1");
}
