/**
 * Logic gate declarations.
 * Copyright (C) 2021 Westermeister. All rights reserved.
 */

#ifndef LOGIC_HPP
#define LOGIC_HPP

#include <string>

namespace logic {

/**
 * Compute logical AND.
 * @param input - 2-bit bus. Can only contain the chars "0" and "1".
 * @returns A string of length 1, either "0" or "1".
 */
std::string AND(std::string input);

/**
 * Compute logical OR.
 * @param input - 2-bit bus. Can only contain the chars "0" and "1".
 * @returns A string of length 1, either "0" or "1".
 */
std::string OR(std::string input);

/**
 * Compute logical XOR.
 * @param input - 2-bit bus. Can only contain the chars "0" and "1".
 * @returns A string of length 1, either "0" or "1".
 */
std::string XOR(std::string input);

/**
 * Compute logical NOT.
 * @param input - A single bit. Should be either "0" or "1".
 * @returns A string of length 1, either "0" or "1".
 */
std::string NOT(std::string input);

/**
 * Compute logical NAND.
 * @param input - 2-bit bus. Can only contain the chars "0" and "1".
 * @returns A string of length 1, either "0" or "1".
 */
std::string NAND(std::string input);

/**
 * Compute logical NOR.
 * @param input - 2-bit bus. Can only contain the chars "0" and "1".
 * @returns A string of length 1, either "0" or "1".
 */
std::string NOR(std::string input);

/**
 * Compute logical XNOR.
 * @param input - 2-bit bus. Can only contain the chars "0" and "1".
 * @returns A string of length 1, either "0" or "1".
 */
std::string XNOR(std::string input);

} // namespace logic

#endif
