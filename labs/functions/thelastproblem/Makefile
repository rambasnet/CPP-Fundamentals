CXX = g++
CXXFLAGS = -c -g -Wall -std=c++17

# the build target executable file; .exe is not required
PROGRAM = thelastproblem.exe

# use wildcard to get all .cpp files in src/ directory

SRC = $(wildcard src/*.cpp)
TESTS = $(wildcard tests/*.cpp)

.PHONY: all build run clean unittest

all: build run clean

build:
	$(CXX) $(CXXFLAGS) $(SRC)
	$(CXX) -o $(PROGRAM) *.o	


run:
	./$(PROGRAM)
	
# delete object and binary files
clean:
	find . -type f -name "*.out" -delete
	find . -type f -name "*.o" -delete
	find . -type f -name "*.exe" -delete
	find . -type d -name "*.dSYM" -exec rm -r {} +

unittest:
	@echo "FIXME! compile and run test_helper.cpp file"
