# compiler name
CXX = g++
# g++ compiler flags
# -g: adds debugging information to the executable file
# -Wall: turns on most, but not  all, compiler warnings
# -std=c++17: uses c++17 standard
# add all the required flags separated by space
CXXFLAGS = -c -g -Wall -std=c++17

# the build target executable file; .exe is not required
PROGRAM = fileio.exe

# list .cpp files separated by space
CPPFILES = fileio.cpp

# make all rule/default rule that'll be run when we run "make"
# first compile each file to object file
# then make a single binary/executable program
build:
	$(CXX) $(CXXFLAGS) $(CPPFILES)
	$(CXX) -o $(PROGRAM) *.o

# make clean rule
# delete object and binary files
clean:
	rm -f $(PROGRAM) *.o

# FIXME
# add a rule to run the program

# rule to run unittest
unittest:
	./$(PROGRAM) "test"

all: build unittest clean
	@echo "All done!"
	