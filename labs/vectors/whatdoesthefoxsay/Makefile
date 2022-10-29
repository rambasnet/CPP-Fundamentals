# compiler name
CXX = g++
# g++ compiler flags
# -g: adds debugging information to the executable file
# -Wall: turns on most, but not  all, compiler warnings
# -std=c++17: uses c++17 standard
# put all the required flags separated by space
CXXFLAGS = -c -g -Wall -std=gnu++17

# the build target executable file; .exe is not required
PROGRAM = foxsays.exe #FIXME

# list .cpp files separated by space
CPPFILES = main.cpp #FIXME

# make all rule/default rule that'll be run when we run "make"
# first compile each file to object file
# then make a single binary/executable program
build:
	$(CXX) $(CXXFLAGS) $(CPPFILES)
	$(CXX) -o $(PROGRAM) *.o

# make clean rule
# delete object and binary files
clean:
	@rm -f $(PROGRAM) *.o

# FIXME3 - add rule to run unittest functions

# FIXME4 - add 4 more commands to test the 4 input files
kattis:
	cat 1.in | ./$(PROGRAM) | diff - 1.ans
	@#FIXME - Add commands to test 4 more input files
	@echo "All kattis test cases passed!"

all: build test clean
	@echo "All done!"