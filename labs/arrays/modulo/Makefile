# compiler name
CXX = g++
# g++ compiler flags
# -g: adds debugging information to the executable file
# -Wall: turns on most, but not  all, compiler warnings
# -std=c++17: uses c++17 standard
# put all the required flags separated by space
CXXFLAGS = -c -g -Wall -std=c++17

# the build target executable file; .exe is not required
PROGRAM = #FIXME

# list .cpp files separated by space
CPPFILES = #FIXME

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

# FIXME1
# add a rule to run the program

unittest:
	./$(PROGRAM) test

# FIXME2 - add 4 more commands to test the 4 input files
kattis_test:
	cat 1.in | ./$(PROGRAM) | diff - 1.ans
	cat 2.in | ./$(PROGRAM) | diff - 2.ans
	@#FIXME - Add commands to test 4 more input files
	@echo "All kattis test cases passed!"

all: build unitest kattis_test clean
	@echo "All done!"
	