# a simple Makefile with 3 rules

# rule for compiling program
# make or make build triggers the following rule
build:
	# compiles .cpp to object file .o
	g++ -c -g -Wall -std=c++17 hello.cpp
	# builds executable from object files
	g++ -o hello.exe hello.o

# rule for running programming
# make run triggers the following rule
run:
	./hello.exe

# rule for clean up
# make clean triggers the following rule
clean:
	rm -f hello.exe hello.o
