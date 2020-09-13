# a simple Makefile with variables and 3 rules

COMPILER = g++
COMPILER_FLAGS = -c -g -Wall -std=c++17

# list .cpp files separated by space
CPP_FILES = hello.cpp

# executable program name
PROGRAM_NAME = hello.exe

# rule for compiling and building program
# make or make all triggers the following rule
all:
	# compiles .cpp to object file .o
	$(COMPILER) $(COMPILER_FLAGS) $(CPP_FILES)
	# builds executable from object files
	$(COMPILER) -o $(PROGRAM_NAME) *.o

# rule for running programming
# make run triggers the following rule
run:
	./$(PROGRAM_NAME)

# rule for clean up
# make clean triggers the following rule
clean:
	rm -f $(PROGRAM_NAME) *.o
