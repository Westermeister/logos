/**
 * Logic gate implementations.
 * Copyright (C) 2021 Westermeister. All rights reserved.
 */

#include <string>

#include "logic.hpp"

namespace logic {

std::string AND(std::string input) {
  if (input == "11") {
    return "1";
  }
  return "0";
}

std::string OR(std::string input) {
  if (input == "01" || input == "10" || input == "11") {
    return "1";
  }
  return "0";
}

std::string XOR(std::string input) {
  if (input == "01" || input == "10") {
    return "1";
  }
  return "0";
}

std::string NOT(std::string input) {
  if (input == "0") {
    return "1";
  }
  return "0";
}

std::string NAND(std::string input) {
  if (input == "11") {
    return "0";
  }
  return "1";
}

std::string NOR(std::string input) {
  if (input == "01" || input == "10" || input == "11") {
    return "0";
  }
  return "1";
}

std::string XNOR(std::string input) {
  if (input == "01" || input == "10") {
    return "0";
  }
  return "1";
}

} // namespace logic
