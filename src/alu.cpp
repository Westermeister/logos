/**
 * Arithmetic logic unit implementation.
 * Copyright (c) 2021 Westermeister. All rights reserved.
 */

#include <algorithm>
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

std::string ALU::basic_alu(std::string input, std::string cin, std::string a_invert, std::string b_invert,
                           std::string less_than, std::string opcode) {
  // Preprocess the operands.
  std::string a_invert_mux = mux::mux21(input.substr(0, 1) + logic::NOT(input.substr(0, 1)), a_invert);
  std::string b_invert_mux = mux::mux21(input.substr(1, 1) + logic::NOT(input.substr(1, 1)), b_invert);
  // Compute AND, OR, and ADD.
  std::string and_output = logic::AND(a_invert_mux + b_invert_mux);
  std::string or_output = logic::OR(a_invert_mux + b_invert_mux);
  std::string xor_output = logic::XOR(a_invert_mux + b_invert_mux);
  std::string adder_output = full_adder(a_invert_mux + b_invert_mux, cin);
  // Select from AND, OR, ADD, and LESS output.
  std::string operation_output = mux::mux51(and_output + or_output + xor_output + adder_output.substr(0, 1) + 
                                            less_than, opcode);
  // Retrieve COUT output.
  std::string cout = adder_output.substr(1, 1);
  // Return the 2-bit bus resulting from the above two outputs.
  return operation_output + cout;
}

std::string ALU::msb_alu(std::string input, std::string cin, std::string a_invert, std::string b_invert,
                         std::string less_than, std::string opcode) {
  // Proceed almost exactly as the basic ALU shown above.
  std::string a_invert_mux = mux::mux21(input.substr(0, 1) + logic::NOT(input.substr(0, 1)), a_invert);
  std::string b_invert_mux = mux::mux21(input.substr(1, 1) + logic::NOT(input.substr(1, 1)), b_invert);
  std::string and_output = logic::AND(a_invert_mux + b_invert_mux);
  std::string or_output = logic::OR(a_invert_mux + b_invert_mux);
  std::string xor_output = logic::XOR(a_invert_mux + b_invert_mux);
  std::string adder_output = full_adder(a_invert_mux + b_invert_mux, cin);
  std::string operation_output = mux::mux51(and_output + or_output + xor_output + adder_output.substr(0, 1) + 
                                            less_than, opcode);
  // ...except for here. In addition to the cout, we want an overflow detection bit.
  // We can get that via an XOR of the cin and the adder's cout.
  std::string cout = adder_output.substr(1, 1);
  std::string overflow = logic::XOR(cin + cout);
  // Also different from the basic ALU is that we siphon off the adder's sum as the set-less-than bit.
  std::string set_less_than = adder_output.substr(0, 1);
  return operation_output + cout + overflow + set_less_than;
}

std::string ALU::detect_zero(std::string input) {
  std::string or_layer_64;
  std::string or_layer_32;
  std::string or_layer_16;
  std::string or_layer_8;
  std::string or_layer_4;
  std::string or_layer_2;
  // Initially 64 bits.
  for (int i = 0; i <= 62; i += 2) {
    or_layer_32 += logic::OR(input.substr(i, 2));
  }
  // Now 32 bits.
  for (int i = 0; i <= 30; i += 2) {
    or_layer_16 += logic::OR(or_layer_32.substr(i, 2));
  }
  // Now 16 bits.
  for (int i = 0; i <= 14; i += 2) {
    or_layer_8 += logic::OR(or_layer_16.substr(i, 2));
  }
  // Now 8 bits.
  for (int i = 0; i <= 6; i += 2) {
    or_layer_4 += logic::OR(or_layer_8.substr(i, 2));
  }
  // Now 4 bits.
  for (int i = 0; i <= 2; i += 2) {
    or_layer_2 += logic::OR(or_layer_4.substr(i, 2));
  }
  // Now 2 bits.
  return logic::NOR(or_layer_2);
}

std::string ALU::run(std::string input, std::string cin, std::string a_invert, std::string b_invert,
                     std::string opcode) {
  std::string retval;
  // Start by computing the LSB's ALU.
  // It forms a sequential circuit with the MSB's ALU (via the less-than bit), which affects the operation output.
  // This means that the operation output is incorrect, but we'll correct it after we compute the MSB's ALU.
  // On the other hand, the carry-out bit is correct, and luckily it's all we need right now.
  std::string lsb_alu = basic_alu(input.substr(63, 1) + input.substr(127, 1),
                                  cin, a_invert, b_invert, "0", opcode);
  // As aforementioned, we'll correct this bit later on. For now, just add it to the retval.
  retval += lsb_alu.substr(0, 1);
  // With the carry-out bit, we can go ahead an emulate all the other ALUs in a ripple-carry fashion via a for-loop.
  std::string current_cin = lsb_alu.substr(1, 1);
  for (int i = 62; i > 0; --i) {
    std::string current_alu = basic_alu(input.substr(i, 1) + input.substr(i + 64, 1),
                                        current_cin, a_invert, b_invert, "0", opcode);
    retval += current_alu.substr(0, 1);
    current_cin = current_alu.substr(1, 1);
  }
  // Now we compute the MSB's ALU and add its operation output to the retval.
  std::string final_alu = msb_alu(input.substr(0, 1) + input.substr(64, 1),
                                  current_cin, a_invert, b_invert, "0", opcode);
  retval += final_alu.substr(0, 1);
  // Make the retval big endian.
  std::reverse(retval.begin(), retval.end());
  // Now add the cout and overflow bits.
  retval += final_alu.substr(1, 2);
  // Now we perform the LSB correction. Extract the MSB's ALU's less-than bit and pass it back up to the LSB's ALU.
  std::string less_than = final_alu.substr(3, 1);
  lsb_alu = basic_alu(input.substr(63, 1) + input.substr(127, 1),
                      cin, a_invert, b_invert, less_than, opcode);
  // Make the correction at the last bit b/c the retval is now big endian.
  retval.replace(63, 1, lsb_alu.substr(0, 1));
  // Finally, based on the (now corrected) operation output, compute the zero bit and append it to the retval.
  retval += detect_zero(retval.substr(0, 64));
  return retval;
}
