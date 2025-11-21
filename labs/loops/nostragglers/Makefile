CXX = g++
CXXFLAGS = -c -g -Wall -std=c++17

PROGRAM = mclimbroad.exe

# list .cpp files separated by space
SRC = $(wildcard src/*.cpp)
TEST_FILES = $(wildcard tests/*.cpp)
all: build run

build:
	$(CXX) $(CXXFLAGS) $(SRC)
	$(CXX) -o $(PROGRAM) *.o

run:
	./$(PROGRAM)
	
# make clean rule
# delete object and binary files
clean:
	find . -name "*.o" -delete
	find . -name "*.dSYM" -type d -exec rm -rf {} + 2>/dev/null || true
	find . -name "*.exe" -delete
	find . -name "*.out" -delete
	find . -name "*.pch" -delete

assert_test: build
	./$(PROGRAM) test
	@echo "Assert tests passed!"

doctest:
	$(CXX) -std=c++17 -I tests $(TEST_FILES) src/nostragglers.cpp -o doctest_runner.exe
	./doctest_runner.exe
	