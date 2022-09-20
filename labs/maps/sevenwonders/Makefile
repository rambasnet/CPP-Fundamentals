# compiler name
CXX = g++
# g++ compiler flags
# -g: adds debugging information to the executable binary
# -Wall: turns on most, but not  all, compiler warnings
# -std=c++17: uses c++17 standard
# add all the required flags separated by space
CXXFLAGS = -c -g -Wall -std=c++17

# the build target executable file; .exe is not required
PROGRAM = a.out #FIXME

# list .cpp files separated by space
CPPFILES = main.cpp #FIXME

# make all rule/default rule that'll be run when we run "make"
# first compile each file to object code
# then make a single binary/executable code
build:
	$(CXX) $(CXXFLAGS) $(CPPFILES)
	$(CXX) -o $(PROGRAM) *.o

# make clean rule
# delete object and binary files
clean:
	rm -f $(PROGRAM) *.o

# FIXME
# add a rule to run the program

unittest:
	./$(PROGRAM) test

# test the kattis provided samples
kattis_test: # FIXME - add commands to test 6 more sample files
	cat ./sample_tests/1.in | ./$(PROGRAM) | diff - ./sample_tests/1.ans
	
	@echo "All Test Cases Passed!"

all: build unittest kattis_test clean
	@echo "All done!"

	
