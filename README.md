# Logos
**Logic gate hardware emulation of a 64-bit ALU written in C++**

To compile, type:

```
make
```

That will create a `build` directory and put a `chip.out` executable within it.

To run, type:

```
./build/chip.out SOURCE_FILE
```

The source file should be a plain text file. Each line of the file (excluding an optional ending newline) should contain
a series of 1's and 0's. The format is as follows:

1. The first 64 bits should be the first operand
2. The following 64 bits are the second operand.
3. The next bit controls whether or not to perform bitwise inversion on the first operand. 1 for yes, 0 for no.
4. The next bit is the same as the above, but for the second operand.
5. The final 3 bits are the opcode:
   1. `000` for `AND`
   2. `001` for `OR`
   3. `010` for `XOR`
   4. `011` for `ADD`
   5. `100` for `LESS-THAN`

The program will then write the results for each line to standard output, line-by-line. The format is as follows:

1. The first 64 bits are the operation's result given the opcode.
2. Then it's the carry-out bit, which indicates whether there was a carry-out from the operation. 1 for yes, 0 for no.
3. The next bit is the overflow bit, which indicates whether the ALU has overflowed. 1 for yes, 0 for no.
4. The final bit is the zero bit, which is 1 if the ALU result is all 0's, and 0 otherwise.

# Example Usage

If you have these two lines in a file `input.txt`:

```
00000000000000000000000000000000000000000000000000000000000000001111111111111111111111111111111111111111111111111111111111111111000000
00000000000000000000000000000000000000000000000000000000000000001111111111111111111111111111111111111111111111111111111111111111000001
```

`./build/chip.out ./input.txt` results in:

```
0000000000000000000000000000000000000000000000000000000000000000001
1111111111111111111111111111111111111111111111111111111111111111000
```

The first line is the result of an `AND` operation on all 0's and all 1's, which gave all 0's (and so the zero bit is
1).

The second line is the result of an `OR` operation on the same inputs, which is all 1's.
