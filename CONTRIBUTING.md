# Contributing to CPP-Fundamentals

Thank you for your interest in contributing!

## Ways to Contribute

- Report bugs via GitHub Issues
- Suggest improvements or new topics via GitHub Issues  
- Submit pull requests for bug fixes or new demo programs
- Help improve documentation

## Getting Started

1. Fork the repository
2. Clone your fork: `git clone https://github.com/<your-username>/CPP-Fundamentals.git`
3. Create a branch: `git checkout -b contrib/<your-feature>`

## Adding a New Demo

1. Create your demo under `notebooks/demos/<topic>/<demo-name>/`
2. Add a `main.cpp` file with your C++ code
3. Add a `Makefile` (use an existing demo as template)
4. Test compilation: `make clean && make`
5. Test execution with sample input

## Code Standards

- Compile with: `g++ -Wall -std=c++17`
- For `INT_MAX`, always include: `#include <climits>`
- For `SIZE_MAX`, always include: `#include <cstddef>`
- Use `size_t` for loop indices when comparing with `.size()`
- Document expected input and output in comments

## Makefile Template

```
CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET = demo

all: $(TARGET)

$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.cpp

clean:
	rm -f $(TARGET)

.PHONY: all clean
```

## Testing

Run all demos manually:
```bash
cd notebooks/demos/<topic>/<demo-name>
make clean && make
./demo-name
```

## Pull Request Guidelines

- Use a clear title and description
- Reference any related GitHub Issue
- Ensure your demo compiles with `make`
- Test with sample input/output