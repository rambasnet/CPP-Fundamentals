COMPILER = g++

COMPILER_FLAGS = -c -g -Wall -std=c++17

PROGRAM_NAME =  assert.exe

CPP_FILES =  assertdebug.cpp

build:
	$(COMPILER) $(COMPILER_FLAGS) $(CPP_FILES)
	$(COMPILER) -o $(PROGRAM_NAME) *.o


run:
	./$(PROGRAM_NAME)

clean:
	rm -f $(PROGRAM_NAME) *.o
