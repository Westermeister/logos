#include "catch.hpp"

#include "../src/mux.hpp"

TEST_CASE("Test mux::mux21") {
  REQUIRE(mux::mux21("01", "0") == "0");
  REQUIRE(mux::mux21("01", "1") == "1");
}
