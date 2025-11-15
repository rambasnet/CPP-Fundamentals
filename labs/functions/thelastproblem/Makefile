# compiler name variable
CXX = g++
# c++ compiler flags
# -g : adds debugging information to the executable file
# -Wall : turns on most compiler warnings
# -std=C++17 : uses c++17 standard
# assign all the required flags separated by space to a variable
CXXFLAGS = -c -g -Wall -std=c++17

# the build target executable file; .exe is not required
PROGRAM = thelastproblem.exe

# list .cpp files separated by space
CPPFILES = src/thelastproblem.cpp src/helper.cpp

# default rule that'll be run when we run "make"
# first compile each file to object files
# then link all objects files to a single binary program
all:
	$(CXX) $(CXXFLAGS) $(CPPFILES)
	$(CXX) -o $(PROGRAM) *.o

run:
	./$(PROGRAM)
	
# make clean rule
# delete object and binary files
clean:
	rm -f $(PROGRAM) *.o *.out

test:
	cat data/1.in | ./$(PROGRAM) | diff - data/1.ans
	cat data/2.in | ./$(PROGRAM) | diff - data/2.ans
	@#FIXME - Add commands to test 3 more input files
	@echo "All test cases passed!"

unit_test:
	$(CXX) tests/test_helper.cpp src/helper.cpp -o test_helper.exe
	./test_helper.exe
	@echo "All tests passed!"
