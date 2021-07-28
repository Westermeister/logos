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
 * @param a - First bit. Should be either "0" or "1".
 * @param b - Second bit. Should be either "0" or "1".
 * @returns a && b
 */
std::string AND(std::string a, std::string b);

/**
 * Compute logical OR.
 * @param a - First bit. Should be either "0" or "1".
 * @param b - Second bit. Should be either "0" or "1".
 * @returns a || b
 */
std::string OR(std::string a, std::string b);

/**
 * Compute logical XOR.
 * @param a - First bit. Should be either "0" or "1".
 * @param b - Second bit. Should be either "0" or "1".
 * @returns a ^ b
 */
std::string XOR(std::string a, std::string b);

/**
 * Compute logical NOT.
 * @param a - Should be either "0" or "1".
 * @returns !a
 */
std::string NOT(std::string a);

/**
 * Compute logical NAND.
 * @param a - First bit. Should be either "0" or "1".
 * @param b - Second bit. Should be either "0" or "1".
 * @returns !(a && b)
 */
std::string NAND(std::string a, std::string b);

/**
 * Compute logical NOR.
 * @param a - First bit. Should be either "0" or "1".
 * @param b - Second bit. Should be either "0" or "1".
 * @returns !(a || b)
 */
std::string NOR(std::string a, std::string b);

/**
 * Compute logical XNOR.
 * @param a - First bit. Should be either "0" or "1".
 * @param b - Second bit. Should be either "0" or "1".
 * @returns !(a ^ b)
 */
std::string XNOR(std::string a, std::string b);

} // namespace logic

#endif
