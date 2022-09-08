# Fairly complex Makefile demo

COMPILER = clang++
COMPILER_FLAGS = -c -g -Wall -std=c++17

# list .cpp files separated by space
CPP_FILES = hello.cpp

# executable program name
PROGRAM_NAME = hello.exe

# rule using other rules
# other rules must be written after the rule name on the same line separated by a space
all: build run clean
	@echo "All Done!"


# rule for compiling and building program
# make or make all or make build triggers the following rule
# @ suppreses/hides the command itself from printing
build:
	@# compile .cpp to object file .o
	@echo "compiling..."
	$(COMPILER) $(COMPILER_FLAGS) $(CPP_FILES)
	@# build executable from object files
	@echo "building..."
	$(COMPILER) -o $(PROGRAM_NAME) *.o

# rule for running binary program
# make run triggers the following rule
run:
	@echo "running program..."
	./$(PROGRAM_NAME)

# rule for clean up
# make clean triggers the following rule
clean:
	@echo "cleaning up..."
	@rm -f $(PROGRAM_NAME) *.o *.out 2> /dev/null
