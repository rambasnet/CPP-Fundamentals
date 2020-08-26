# compiler name
CXX = g++
# c++ compiler flags
# -g: adds debugging information to the executable file
# - Wall turns on most, but not  all, compiler warnings
# -std=C++17 uses c++17 standard
# put all the required flags separated by space
CXXFLAGS = -g -Wall -std=c++17

# the build target executable file
TARGET = helloworld.exe
# list cpp files separated by space
INPUTFILES = helloworld.cpp

# make all rule
all: $(TARGET)

$(TARGET): $(INPUTFILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(INPUTFILES)

# make clean rule
clean:
	$(RM) $(TARGET)