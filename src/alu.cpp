/**
 * Arithmetic logic unit implementation.
 * Copyright (C) 2021 Westermeister. All rights reserved.
 */

#include <string>

#include "alu.hpp"
#include "logic.hpp"
#include "mux.hpp"

std::string ALU::half_adder(std::string input) {
  std::string sum = logic::XOR(input);
  std::string cout = logic::AND(input);
  return sum + cout;
}

std::string ALU::full_adder(std::string input, std::string cin) {
  // Compute sum of 2 bits.
  std::string first_pass = half_adder(input);
  // Add that sum to the input's carry-in bit.
  std::string second_pass = half_adder(first_pass.substr(0, 1) + cin);
  // Get the final sum.
  std::string sum = second_pass.substr(0, 1);
  // Get the final cout. If either pass resulted in a carry-out bit, we have one. Otherwise, we don't.
  std::string cout = logic::OR(first_pass.substr(1, 1) + second_pass.substr(1, 1));
  return sum + cout;
}

std::string ALU::alu_basic(std::string input, std::string cin, std::string a_invert, std::string b_invert,
                           std::string less, std::string opcode) {
  // Preprocess the operands.
  std::string a_invert_mux = mux::mux21(input.substr(0, 1) + logic::NOT(input.substr(0, 1)), a_invert);
  std::string b_invert_mux = mux::mux21(input.substr(1, 1) + logic::NOT(input.substr(1, 1)), b_invert);
  // Compute AND, OR, and ADD.
  std::string and_output = logic::AND(a_invert_mux + b_invert_mux);
  std::string or_output = logic::OR(a_invert_mux + b_invert_mux);
  std::string adder_output = full_adder(a_invert_mux + b_invert_mux, cin);
  // Select from AND, OR, ADD, and LESS output.
  std::string operation_output = mux::mux41(and_output + or_output + adder_output.substr(0, 1) + less, opcode);
  // Retrieve COUT output.
  std::string cout = adder_output.substr(1, 1);
  // Return the 2-bit bus resulting from the above two outputs.
  return operation_output + cout;
}

std::string ALU::alu_msb(std::string input, std::string cin, std::string a_invert, std::string b_invert,
                         std::string less, std::string opcode) {
  // Proceed almost exactly as the basic ALU shown above.
  std::string a_invert_mux = mux::mux21(input.substr(0, 1) + logic::NOT(input.substr(0, 1)), a_invert);
  std::string b_invert_mux = mux::mux21(input.substr(1, 1) + logic::NOT(input.substr(1, 1)), b_invert);
  std::string and_output = logic::AND(a_invert_mux + b_invert_mux);
  std::string or_output = logic::OR(a_invert_mux + b_invert_mux);
  std::string adder_output = full_adder(a_invert_mux + b_invert_mux, cin);
  std::string operation_output = mux::mux41(and_output + or_output + adder_output.substr(0, 1) + less, opcode);
  // ...except for here. Instead of a cout, we want an overflow detection bit.
  // We can get that via an XOR of the cin and the adder's cout.
  std::string overflow = logic::XOR(cin + adder_output.substr(1, 1));
  // Also different from the basic ALU is that we siphon off the adder's sum as the set-less-than bit.
  std::string set_less_than = adder_output.substr(0, 1);
  return operation_output + overflow + set_less_than;
}
