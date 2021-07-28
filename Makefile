.PHONY: all
all: format
	mkdir -p build
	g++ -std=c++17 -Wall -Wextra src/main.cpp -o build/chip.out

.PHONY: check
check: format tests/catch.o
	# g++ -std=c++11 -Wall -Itests -o tests/testrunner.o tests/catch.o tests/logic.cpp tests/mux.cpp
	g++ -std=c++11 -Wall -Itests -o tests/testrunner.o tests/catch.o \
	tests/logic.test.cpp \
	src/logic.cpp \
	tests/mux.test.cpp \
	src/mux.cpp
	./tests/testrunner.o
	rm -f tests/testrunner.o

.PHONY: clean
clean:
	rm -rf build

.PHONY: format
format:
	npx clang-format -i --verbose src/main.cpp src/*.hpp tests/*.cpp

tests/catch.o:
	g++ -std=c++11 -Wall -Itests -c tests/catch.cpp -o tests/catch.o
