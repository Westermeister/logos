COMPILER=g++
FORMATTER=clang-format

COMPILER_FLAGS=-std=c++17 -Wall -Wextra
FORMATTER_FLAGS=-i --verbose

.PHONY: all
all: format
	mkdir -p ./build
	$(COMPILER) $(COMPILER_FLAGS) ./src/main.cpp -o ./build/chip.out

.PHONY: clean
clean:
	rm -rf ./build

.PHONY: format
format:
	$(FORMATTER) $(FORMATTER_FLAGS) ./src/main.cpp ./src/*.hpp
