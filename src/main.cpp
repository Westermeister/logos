/**
 * Entry point for emulation.
 * Copyright (c) 2021 Westermeister. All rights reserved.
 */

#include <fstream>
#include <iostream>
#include <string>

#include "alu.hpp"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "You need to provide a filename!" << std::endl;
    return 1;
  }
  std::ifstream file(argv[1]);
  if (file.is_open()) {
    ALU alu;
    std::string input;
    std::string cin;
    std::string a_invert;
    std::string b_invert;
    std::string opcode;
    std::string output;
    std::string line;
    while (std::getline(file, line)) {
      input = line.substr(0, 128);
      cin = line.substr(128, 1);
      a_invert = line.substr(129, 1);
      b_invert = line.substr(130, 1);
      opcode = line.substr(131, 3);
      output = alu.run(input, cin, a_invert, b_invert, opcode);
      std::cout << output << std::endl;
    }
    file.close();
  }
  return 0;
}
