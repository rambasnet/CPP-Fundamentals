# compiler name
CXX = g++
# c++ compiler flags
# -g : adds debugging information to the executable file
# -Wall : turns on most, but not  all, compiler warnings
# -std=C++17 : uses c++17 standard
# put all the required flags separated by space
CXXFLAGS = -c -g -Wall -std=c++17

# the build target executable file; .exe is not required
PROGRAM = hello.exe

# list all .cpp file(s) separated by space
CPPFILES = main.cpp

# make all rule or the default rule that'll be run when we run "make"
# first compile each file to object file
# then make a single binary program
all:
	$(CXX) $(CXXFLAGS) $(CPPFILES) # compile each file to object file
	$(CXX) -o $(PROGRAM) *.o # build the binary program using object file(s)
	# ./$(PROGRAM) # uncomment it if you want to run the program if successfully built

# make clean rule
# delete object and binary files
clean:
	rm -f $(PROGRAM) *.o
	