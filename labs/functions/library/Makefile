# compiler name
CXX = g++
# c++ compiler flags
# -g : adds debugging information to the executable file
# -Wall : turns on most, but not  all, compiler warnings
# -std=C++17 : uses c++17 standard
# put all the required flags separated by space
CXXFLAGS = -c -g -Wall -std=c++17

# the build target executable file; .exe is not required
PROGRAM = library.exe

# list .cpp files separated by space
CPPFILES = src/main.cpp src/my_math.cpp

# make build rule/default rule that'll be run when we run "make"
# first compile each file to object file
# then make a single binary program
all:
	$(CXX) $(CXXFLAGS) $(CPPFILES)
	$(CXX) -o $(PROGRAM) *.o

run:
	./$(PROGRAM)

unittest:
	$(CXX) tests/test_my_math.cpp src/my_math.cpp -o test_my_math.exe
	./test_my_math.exe
	@echo "All tests executed successfully!"
	
# make clean rule
# delete object and binary files
clean:
	find . -type f -name "*.out" -delete
	find . -type f -name "*.o" -delete
	find . -type f -name ".exe" -delete
	
	