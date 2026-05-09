CXX = g++
FLAGS = -std=c++23
TARGET = calculator.exe
CPPFILES = $(wildcard src/*.cpp)

build:
	$(CXX) $(FLAGS) $(CPPFILES) -o $(TARGET) -lncurses

run: build
	./$(TARGET)

doctest:
	$(CXX) -std=c++23 tests/test_mymath.cpp src/my_math.cpp -o test.exe  && ./test.exe	

clean:
	rm -f $(TARGET) *.o *.exe
