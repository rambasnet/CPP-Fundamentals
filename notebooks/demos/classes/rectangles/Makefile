CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
TARGET = rectangle.exe
SRCS = $(wildcard src/*.cpp)

all: $(TARGET)
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f *.exe