
CXX = g++

CXXFLAGS = -c -g -Wall -std=c++17

PROGRAM = unittest.exe

CPPFILES = unittesting3.cpp

all:
	$(CXX) $(CXXFLAGS) $(CPPFILES)
	$(CXX) -o $(PROGRAM) *.o

clean:
	rm -f $(PROGRAM) *.o

run:
	./$(PROGRAM)