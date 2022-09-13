CXX = g++
CXXFLAGS = -c -g -Wall -std=c++17

PROGRAM = triangle_area.exe

# list .cpp files separated by space
CPPFILES = main.cpp

all:
	$(CXX) $(CXXFLAGS) $(CPPFILES)
	$(CXX) -o $(PROGRAM) *.o

run:
	./$(PROGRAM)
	
# make clean rule
# delete object and binary files
clean:
	rm -f $(PROGRAM) *.o

test:
	@echo "diff doesn't work correctly on floating point numbers, e.g. 5.0 and 5.0000000 are different!"
	@echo "stick to unit testing!"
	