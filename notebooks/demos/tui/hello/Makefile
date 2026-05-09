CXX = g++
FLAGS = -std=c++23

TARGET = tui.exe
CPPFILES = $(wildcard src/*.cpp)

# lncursesw (W) is used for wide character support (Unicode)
build:
	$(CXX) $(FLAGS) $(CPPFILES) -o $(TARGET) -lncursesw

run: build
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o *.exe

doctest:
	$(CXX) -std=c++23 tests/test_util.cpp src/util.cpp -o test.exe -lncursesw && ./test.exe
