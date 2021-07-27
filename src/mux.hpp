/**
 * Multiplexers of varying widths, with a single output.
 * Copyright (C) 2021 Westermeister. All rights reserved.
 */

#ifndef MUX_HPP
#define MUX_HPP

#include <string>

#include "logic.hpp"

namespace mux {

/**
 * 2:1 multiplexer.
 * @param i - 2-bit bus input.
 * @param sel - 1-bit selector. Represents an integer index.
 * @returns The selected bit.
 */
std::string mux21(std::string i, std::string s) {
  std::string and_1 = logic::AND(i.substr(0, 1), logic::NOT(s));
  std::string and_2 = logic::AND(i.substr(1, 1), s);
  return logic::OR(and_1, and_2);
}

/**
 * 4:1 multiplexer.
 * @param i - 4-bit bus input.
 * @param sel - 2-bit selector. Represents an integer index.
 * @returns The selected bit.
 */
std::string mux41(std::string i, std::string s) {
  std::string mux_1 = mux21(i.substr(0, 2), s.substr(1, 1));
  std::string mux_2 = mux21(i.substr(2, 2), s.substr(1, 1));
  return mux21(mux_1 + mux_2, s.substr(0, 1));
}

/**
 * 8:1 multiplexer.
 * @param i - 8-bit bus input.
 * @param sel - 3-bit selector. Represents an integer index.
 * @returns The selected bit.
 */
std::string mux81(std::string i, std::string s) {
  std::string mux_1 = mux41(i.substr(0, 4), s.substr(1, 2));
  std::string mux_2 = mux21(i.substr(4, 4), s.substr(1, 2));
  return mux21(mux_1 + mux_2, s.substr(0, 1));
}

} // namespace mux

#endif
