/**
 * Logic gates implemented with strings.
 * Copyright (C) 2021 Westermeister. All rights reserved.
 */

#ifndef LOGIC_HPP
#define LOGIC_HPP

#include <string>

namespace logic {

/**
 * Compute logical AND.
 * @param a - String with one character: either "0" or "1".
 * @param b - Same as a.
 * @returns a && b
 */
std::string AND(std::string a, std::string b) {
  if (a == "1" && b == "1") {
    return "1";
  }
  return "0";
}

/**
 * Compute logical OR.
 * @param a - String with one character: either "0" or "1".
 * @param b - Same as a.
 * @returns a || b
 */
std::string OR(std::string a, std::string b) {
  if (a == "1" || b == "1") {
    return "1";
  }
  return "0";
}

/**
 * Compute logical XOR.
 * @param a - String with one character: either "0" or "1".
 * @param b - Same as a.
 * @returns a ^ b
 */
std::string XOR(std::string a, std::string b) {
  if (a == "1" && b == "0") {
    return "1";
  }
  if (a == "0" && b == "1") {
    return "1";
  }
  return "0";
}

/**
 * Compute logical NOT.
 * @param a - String with one character: either "0" or "1".
 * @returns !a
 */
std::string NOT(std::string a) {
  if (a == "0") {
    return "1";
  }
  return "0";
}

/**
 * Compute logical NAND.
 * @param a - String with one character: either "0" or "1".
 * @param b - Same as a.
 * @returns !(a && b)
 */
std::string NAND(std::string a, std::string b) {
  if (a == "1" && b == "1") {
    return "0";
  }
  return "1";
}

/**
 * Compute logical NOR.
 * @param a - String with one character: either "0" or "1".
 * @param b - Same as a.
 * @returns !(a || b)
 */
std::string NOR(std::string a, std::string b) {
  if (a == "1" || b == "1") {
    return "0";
  }
  return "1";
}

/**
 * Compute logical XNOR.
 * @param a - String with one character: either "0" or "1".
 * @param b - Same as a.
 * @returns !(a ^ b)
 */
std::string XNOR(std::string a, std::string b) {
  if (a == "1" && b == "0") {
    return "0";
  }
  if (a == "0" && b == "1") {
    return "0";
  }
  return "1";
}

} // namespace logic

#endif
