/**
 * Arithmetic logic unit declaration.
 * Copyright (C) 2021 Westermeister. All rights reserved.
 */

#ifndef ALU_HPP
#define ALU_HPP

#include <string>

class ALU {
private:
  /**
   * Implement 1-bit addition between 2 bits.
   * @param input - The 2 bits to add.
   * @returns 2-bit bus; first the sum, then the cout.
   */
  std::string half_adder(std::string input);

  /**
   * Implement 1-bit addition between 2 bits and a carry-in bit.
   * @param input - The 2 bits to add.
   * @param cin - The carry-in bit.
   * @returns 2-bit bus; first the sum, then the cout.
   */
  std::string full_adder(std::string input, std::string cin);

  /**
   * Implement 1-bit ALU as a basic building block.
   * @param input - The 2 bits to operate on.
   * @param cin - The carry-in bit.
   * @param a_invert - 1 bit. Whether or not to invert the middle input bit.
   * @param b_invert - 1 bit. Whether or not to invert the last input bit.
   * @param less - 1 bit. Serves as input for the less-than signal. Should be
   * "0" except for the LSB's ALU.
   * @param opcode - 2 bits. 00 = AND, 01 = OR, 10 = ADD, 11 = LESS-THAN
   * @returns 2-bit bus; first the output according to the opcode, then the
   * carry-out bit.
   */
  std::string alu_basic(std::string input, std::string cin,
                        std::string a_invert, std::string b_invert,
                        std::string less, std::string opcode);

  /**
   * Implement a special 1-bit ALU that is only used for the MSB.
   * @param input - The 2 bits to operate on.
   * @param cin - The carry-in bit.
   * @param a_invert - 1 bit. Whether or not to invert the middle input bit.
   * @param b_invert - 1 bit. Whether or not to invert the last input bit.
   * @param less - 1 bit. Serves as input for the less-than signal. Should be
   * "0" except for the LSB's ALU.
   * @param opcode - 2 bits. 00 = AND, 01 = OR, 10 = ADD, 11 = LESS-THAN
   * @returns 3-bit bus; first the output according to the opcode, then the
   * overflow bit, then the set-less-than bit.
   */
  std::string alu_msb(std::string input, std::string cin, std::string a_invert,
                      std::string b_invert, std::string less,
                      std::string opcode);

public:
  ;
};

#endif
