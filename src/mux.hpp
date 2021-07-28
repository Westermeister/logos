/**
 * Multiplexer declarations.
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
std::string mux21(std::string i, std::string s);

/**
 * 4:1 multiplexer.
 * @param i - 4-bit bus input.
 * @param sel - 2-bit selector. Represents an integer index.
 * @returns The selected bit.
 */
std::string mux41(std::string i, std::string s);

/**
 * 8:1 multiplexer.
 * @param i - 8-bit bus input.
 * @param sel - 3-bit selector. Represents an integer index.
 * @returns The selected bit.
 */
std::string mux81(std::string i, std::string s);

} // namespace mux

#endif
