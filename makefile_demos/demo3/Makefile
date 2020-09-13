# a simple Makefile with 4 rules

# rule for compiling program
# make or make compile triggers the rule
compile:
	# compiles .cpp to object file .o
	g++ -c -g -Wall -std=c++17 hello.cpp

# rule for building executable program
# make or make build triggers the rule
build:
	g++ -o hello.exe hello.o

# rule for running programming
# make run triggers the  rule
run:
	./hello.exe

# rule for clean up
# make clean triggers the rule
clean:
	rm -f hello.exe hello.o
