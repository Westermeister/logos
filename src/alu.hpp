/**
 * Arithmetic logic unit declaration.
 * Copyright (c) 2021 Westermeister. All rights reserved.
 */

#ifndef ALU_HPP
#define ALU_HPP

#include <string>

/** A 64-bit ALU. */
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
   * @param less_than - 1 bit. Serves as input for the less-than signal. Should
   * be "0" except for the LSB's ALU.
   * @param opcode - 3 bits. 000 for AND, 001 for OR, 010 for XOR, 011 for ADD,
   * 100 for LESS-THAN
   * @returns 2-bit bus; first the operation output according to the opcode,
   * then the carry-out bit.
   */
  std::string basic_alu(std::string input, std::string cin, std::string a_invert, std::string b_invert,
                        std::string less_than, std::string opcode);

  /**
   * Implement a special 1-bit ALU that is only used for the MSB.
   * @param input - The 2 bits to operate on.
   * @param cin - The carry-in bit.
   * @param a_invert - 1 bit. Whether or not to invert the middle input bit.
   * @param b_invert - 1 bit. Whether or not to invert the last input bit.
   * @param less_than - 1 bit. Serves as input for the less-than signal. Should
   * be "0" except for the LSB's ALU.
   * @param opcode - 3 bits. 000 for AND, 001 for OR, 010 for XOR, 011 for ADD,
   * 100 for LESS-THAN
   * @returns 4-bit bus; first the operation output according to the opcode,
   * then the carry-out bit, then the overflow bit, then the less-than bit.
   */
  std::string msb_alu(std::string input, std::string cin, std::string a_invert, std::string b_invert,
                      std::string less_than, std::string opcode);

  /**
   * Detects if all of the 64 bits of the ALU's operation output are 0.
   * @param input - 64-bit bus. Should represent the ALU's operation output.
   * @returns 1 bit. 1 if all are zero; otherwise 0.
   */
  std::string detect_zero(std::string input);

public:
  /**
   * Runs the ALU.
   * @param input - 128-bit bus; first operand is first 64 bits, second is last
   * 64 bits.
   * @param cin - The carry-in bit.
   * @param a_invert - 1 bit. Whether or not to perform bitwise inversion on
   * first operand.
   * @param b_invert - 1 bit. Whether or not to perform bitwise inversion on
   * second operand.
   * @param opcode - 3 bits. 000 for AND, 001 for OR, 010 for XOR, 011 for ADD,
   * 100 for LESS-THAN
   * @returns 67-bit bus. The first 64 bits are the ALU's operation output. The
   * 65th bit is the carry-out bit. The 66th bit is the overflow bit. The 67th
   * bit is the zero bit.
   */
  std::string run(std::string input, std::string cin, std::string a_invert, std::string b_invert, std::string opcode);
};

#endif
