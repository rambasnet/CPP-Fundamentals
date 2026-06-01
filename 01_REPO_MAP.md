# Repo Map - CPP-Fundamentals

## Project Overview

**What the project does:** Educational C++ fundamentals course for CS1 (Computer Science 1) level. Contains Jupyter Notebooks, PDF lecture materials, demo programs, labs, and exercises teaching C++ programming concepts.

**Upstream:** https://github.com/rambasnet/CPP-Fundamentals  
**Fork:** https://github.com/Arvuno/CPP-Fundamentals  
**License:** MIT  
**Primary Language:** HTML (via Jupyter notebooks converted to various formats)

## Repository Structure

```
CPP-Fundamentals/
├── README.md
├── LICENSE (MIT)
├── notebooks/           # Jupyter notebooks for each topic (38 notebooks)
│   ├── demos/           # Demo C++ programs organized by topic
│   │   ├── intro/
│   │   ├── conditionals/
│   │   ├── loops/
│   │   ├── vectors/
│   │   ├── structs/
│   │   ├── classes/
│   │   ├── file_io/
│   │   ├── makefiles/
│   │   ├── pointers/
│   │   ├── memory/
│   │   ├── tui/
│   │   ├── arrays/
│   │   ├── variables/
│   │   ├── functions/
│   │   ├── stdio/
│   │   ├── library/
│   │   ├── debugging/
│   │   ├── unittest/
│   │   ├── regex/
│   │   ├── maps/
│   │   ├── header_files/
│   │   └── doctest/
│   └── *.ipynb         # 38 Jupyter notebooks
├── labs/               # Lab exercises (24 topics, 42+ labs)
│   ├── arrays/
│   ├── conditionals/
│   ├── loops/
│   ├── vectors/
│   ├── structs/
│   ├── functions/
│   └── ...
├── exercises/         # Additional exercises
│   ├── intro/
│   ├── conditionals/
│   ├── loops/
│   ├── variables/
│   ├── functions/
│   ├── stdio/
│   ├── library/
│   └── header_files/
├── pdfs/              # PDF versions of notebooks
├── markdowns/         # Markdown versions of notebooks
├── htmls/             # HTML versions of notebooks
├── environment.yml    # Conda environment for Jupyter
├── docker-compose.yml
├── run-docker.sh
└── convert_*.sh scripts
```

## Content Organization

### By Type
- **Jupyter Notebooks (38):** Think C++ style lessons covering topics from introduction to advanced C++ concepts
- **Demo Programs (57 .cpp files):** Full C++ programs with Makefiles showing complete implementations
- **Labs (42+):** Hands-on programming exercises organized by topic
- **Exercises:** Smaller exercise sets for practice
- **PDFs:** Converted notebook content

### Topics Covered
1. Introduction to C++
2. Data Types and Variables
3. Operators and Expressions
4. Conditionals (if/else, switch)
5. Loops (while, for, do-while)
6. Functions
7. Arrays and Vectors
8. Pointers and Memory
9. Strings
10. Structures
11. Classes and Objects
12. File I/O
13. STL Containers (vectors, maps, sets, etc.)
14. Algorithms
15. Recursion
16. Makefiles
17. Unit Testing
18. Debugging
19. Regular Expressions
20. Textual User Interface (TUI)

## Build/Test Commands

### Compiler Check
```bash
g++ --version
# g++ (Ubuntu 13.3.0-6ubuntu2~24.04.1) 13.3.0
```

### Compiling Demos with Make
Each demo folder has a Makefile. Example:
```bash
cd notebooks/demos/intro
make clean && make
./helloworld
```

### Compiling Demos with g++ directly
```bash
cd notebooks/demos/intro
g++ -g -Wall -std=c++17 -o helloworld helloworld.cpp
./helloworld
```

### Common Makefile Pattern
```make
CXX = g++
CXXFLAGS = -c -g -Wall -std=c++17
PROGRAM = program.exe
CPPFILES = main.cpp

all:
    $(CXX) $(CXXFLAGS) $(CPPFILES)
    $(CXX) -o $(PROGRAM) *.o

clean:
    rm -f $(PROGRAM) *.o
```

## Compilation Issues Found

### Working Demos
- `notebooks/demos/intro/helloworld.cpp` - Compiles and runs correctly
- `notebooks/demos/arrays/buffer_overflow1/buffer_overflow1.cpp` - Compiles with warnings
- `notebooks/demos/structs/triangle/triangle.cpp` - Compiles with warnings

### Broken Demos (require fixes)
1. `notebooks/demos/conditionals/rectangle/main.cpp`
   - Error: `INT_MAX` not declared - missing `#include <climits>`
   
2. `notebooks/demos/loops/rectangle/main.cpp`
   - Same error: `INT_MAX` not declared - missing `#include <climits>`

3. `notebooks/demos/tui/hello/`
   - Error: `ncurses.h` not found - missing `-lncursesw` library on system

### Pattern Analysis
Several demos use `INT_MAX` from `<climits>` without including it:
- `notebooks/demos/conditionals/rectangle/main.cpp`
- `notebooks/demos/loops/rectangle/main.cpp`

Many demos have `-Wsign-compare` warnings (signed/unsigned comparison).

## Missing Expected Outputs

- `notebooks/demos/vectors/triangle/` has `output.txt` showing expected output
- Most other demo programs lack `output.txt` expected output files
- Notebooks don't consistently show expected output for examples

## Recent Contribution Patterns

Git log shows recent commits (last 20):
- `6186e82` add run-time exceptions
- `a55de26` update Toc
- `538e82a` add Function Pointers and Lambda Chapter
- `55f2590` update ToC
- `a705333` update Textual User Interface - TUI
- `c036bc6` add TUI lab
- `60c6b80` add ncurses library and update docstring

## Risk-Sensitive Areas

1. **TUI demos:** Require ncurses library which may not be installed
2. **Missing header includes:** Some demos won't compile without fixes
3. **No CI/CD:** No GitHub Actions workflows found
4. **Large content variety:** 38 notebooks + 42+ labs + 57 demos = high maintenance burden

## Best Areas for Medium-Sized Useful PRs

1. **Fix missing `#include <climits>`** in `rectangle/main.cpp` (2 files) - Simple, low-risk
2. **Add output.txt expected output files** to demo folders - Documents behavior
3. **Standardize Makefiles** - Not all Makefiles use consistent patterns
4. **Add compile instructions** to demo README sections in notebooks
5. **Fix `-Wsign-compare` warnings** - Use consistent signed/unsigned types
6. **Add missing test targets** to Makefiles (e.g., `make test`)
7. **Update outdated xeus-cling instructions** - Mac Silicon issue noted in README
8. **Add expected output comments** in source files where output.txt is missing