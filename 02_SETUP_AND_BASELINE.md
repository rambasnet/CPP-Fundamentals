# Setup and Baseline

## Environment Check

### Compiler Version
```bash
$ g++ --version
g++ (Ubuntu 13.3.0-6ubuntu2~24.04.1) 13.3.0
```

### Git Setup
```bash
$ git remote -v
origin  https://github.com/Arvuno/CPP-Fundamentals.git (fetch)
origin  https://github.com/Arvuno/CPP-Fundamentals.git (push)
upstream        https://github.com/rambasnet/CPP-Fundamentals.git (fetch)
upstream        https://github.com/rambasnet/CPP-Fundamentals.git (push)
```

### Branches
- `main` (local and remote)
- `v1` tag
- `upstream/main` and `upstream/v1` remotes

## Directory Structure

```
CPP-Fundamentals/
├── notebooks/           # 38 Jupyter notebooks + demos
│   └── demos/           # 57 .cpp files in ~20 topic folders
├── labs/               # 24 topic folders, 42+ labs with Makefiles
├── exercises/          # 8 topic folders
├── pdfs/              # PDF versions of notebooks
├── markdowns/         # Markdown versions
├── htmls/             # HTML versions
├── environment.yml    # Conda environment spec
├── docker-compose.yml
└── run-docker.sh
```

## Build System Detection

### Makefiles Found
- **42 Makefiles** in labs folder
- **Multiple Makefiles** in demos folder
- No CMakeLists.txt found
- No automated test framework (no Catch2, GoogleTest in repo except doctest.hpp)

### Build Pattern
Most demos use Makefiles with this pattern:
```make
CXX = g++
CXXFLAGS = -c -g -Wall -std=c++17
PROGRAM = name.exe
CPPFILES = main.cpp

all:
    $(CXX) $(CXXFLAGS) $(CPPFILES)
    $(CXX) -o $(PROGRAM) *.o

clean:
    rm -f $(PROGRAM) *.o
```

## Compilation Tests

### Test 1: helloworld.cpp (SUCCESS)
```bash
cd notebooks/demos/intro
g++ -g -Wall -std=c++17 -o helloworld helloworld.cpp
./helloworld
# Output: Hello World!
```
**Status:** ✓ Compiles and runs correctly

### Test 2: rectangle/main.cpp (FAIL)
```bash
cd notebooks/demos/conditionals/rectangle
make clean && make
```
**Error:**
```
main.cpp:65:16: error: 'INT_MAX' was not declared in this scope
   65 |     cin.ignore(INT_MAX, '\n');
      |                ^~~~~~~
main.cpp:25:1: note: 'INT_MAX' is defined in header '<climits>'
```
**Status:** ✗ Missing `#include <climits>`

### Test 3: loops/rectangle/main.cpp (FAIL)
Same error as Test 2 - missing `#include <climits>`

### Test 4: buffer_overflow1.cpp (SUCCESS with warnings)
```bash
cd notebooks/demos/arrays/buffer_overflow1
make clean && make
```
**Status:** ✓ Compiles with warnings (signed/unsigned comparison)

### Test 5: structs/triangle/triangle.cpp (SUCCESS with warnings)
```bash
cd notebooks/demos/structs/triangle
make clean && make
```
**Status:** ✓ Compiles with warnings (signed/unsigned comparison)

### Test 6: tui/hello (FAIL)
```bash
cd notebooks/demos/tui/hello
make clean && make
```
**Error:**
```
fatal error: ncursesw/ncurses.h: No such file or directory
```
**Status:** ✗ Missing ncurses library

## CI/CD Check

- No `.github/workflows/` directory found
- No GitHub Actions configured
- No automated testing pipeline

## Baseline Summary

| Demo | Compile | Run | Notes |
|------|---------|-----|-------|
| intro/helloworld | ✓ | ✓ | Clean compile |
| conditionals/rectangle | ✗ | - | Missing `#include <climits>` |
| loops/rectangle | ✗ | - | Missing `#include <climits>` |
| arrays/buffer_overflow1 | ✓ | - | Warnings present |
| structs/triangle | ✓ | - | Warnings present |
| tui/hello | ✗ | - | Missing ncurses library |

**Key Issues:**
1. At least 2 demos fail to compile due to missing header includes
2. TUI demos require ncurses which is not installed
3. No CI pipeline to catch compilation issues
4. Several signed/unsigned comparison warnings exist