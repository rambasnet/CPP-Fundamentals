CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
TARGET = point.exe
SRCS = $(wildcard src/*.cpp)

all: $(TARGET)
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f *.exe

unittest: $(TARGET)
	$(CXX) $(CXXFLAGS) -o test_point.exe tests/test_point.cpp src/point.cpp -I src
	./test_point.exe

