/**
 * Logic gate implementations.
 * Copyright (C) 2021 Westermeister. All rights reserved.
 */

#include <string>

#include "logic.hpp"

namespace logic {

std::string AND(std::string a, std::string b) {
  if (a == "1" && b == "1") {
    return "1";
  }
  return "0";
}

std::string OR(std::string a, std::string b) {
  if (a == "1" || b == "1") {
    return "1";
  }
  return "0";
}

std::string XOR(std::string a, std::string b) {
  if (a == "1" && b == "0") {
    return "1";
  }
  if (a == "0" && b == "1") {
    return "1";
  }
  return "0";
}

std::string NOT(std::string a) {
  if (a == "0") {
    return "1";
  }
  return "0";
}

std::string NAND(std::string a, std::string b) {
  if (a == "1" && b == "1") {
    return "0";
  }
  return "1";
}

std::string NOR(std::string a, std::string b) {
  if (a == "1" || b == "1") {
    return "0";
  }
  return "1";
}

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
