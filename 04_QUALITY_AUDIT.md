# Quality Audit

## Compilation Issues

### 1. Missing `#include <climits>` - INT_MAX undeclared
**Files affected:**
- `notebooks/demos/conditionals/rectangle/main.cpp`
- `notebooks/demos/loops/rectangle/main.cpp`
- `notebooks/demos/loops/input_validate/input_validation.cpp`
- `notebooks/demos/arrays/overflow_fixed/overflow_fixed.cpp`
- `notebooks/demos/pointers/rectangle/main.cpp`

**Evidence:**
```
main.cpp:65:16: error: 'INT_MAX' was not declared in this scope
   65 |     cin.ignore(INT_MAX, '\n');
```

**Severity:** High (blocks compilation)  
**Fix Candidate:** Yes

---

### 2. Missing ncurses library for TUI demos
**Files affected:**
- `notebooks/demos/tui/hello/`
- `notebooks/demos/tui/window/`
- `notebooks/demos/tui/menu/`
- `notebooks/demos/tui/noecho/`

**Evidence:**
```
fatal error: ncursesw/ncurses.h: No such file or directory
    7 | #include <ncursesw/ncurses.h>
```

**Severity:** Medium (TUI is advanced topic, may not be core focus)  
**Fix Candidate:** Yes (document library requirement or provide fallback)

---

### 3. Signed/Unsigned Comparison Warnings
**Files affected:**
- `notebooks/demos/structs/triangle/triangle.cpp:268`
- Multiple other files

**Evidence:**
```
warning: comparison of integer expressions of different signedness: 'int' and 'std::vector<Triangle>::size_type'
```

**Severity:** Low (warnings only, code works)  
**Fix Candidate:** Yes

---

## Missing Documentation

### 4. No Expected Output Files
**Finding:** Only `notebooks/demos/vectors/triangle/output.txt` exists. Most demos lack expected output documentation.

**Evidence:**
```bash
$ find . -name "output.txt" | wc -l
1
```

**Severity:** Medium (educational content needs verification)  
**Fix Candidate:** Yes

---

### 5. Deprecated Links
**Finding:** Multiple links to `cplusplus.com` which has had issues with ad injection and reliability.

**Evidence:**
```
notebooks/Arrays.ipynb:10: "C-Arrays - https://cplusplus.com/doc/tutorial/arrays/\n"
notebooks/DataTypesAndVariables.ipynb:21: "Variables and Data Types in C++: [https://cplusplus.com/doc/tutorial/variables/]"
notebooks/StdInputOutput.ipynb:16: "Basic Input and Output in C++: [https://cplusplus.com/doc/tutorial/basic_io/]"
```

**Severity:** Low (content still works but site reliability questionable)  
**Fix Candidate:** Yes (update to cppreference.com)

---

### 6. HTTP links still in use
**Evidence:**
```
notebooks/Arrays.ipynb: "http://pythontutor.com/cpp.html#code=..."
notebooks/LibraryAndFunction.ipynb: "http://cplusplus.com/reference/cstring/"
```

**Severity:** Low  
**Fix Candidate:** Yes (upgrade to HTTPS)

---

## Code Quality Issues

### 7. `system()` calls for screen clearing
**Files affected:**
- `notebooks/demos/loops/countdown/countdown.cpp`
- `notebooks/demos/loops/rectangle/main.cpp`
- `notebooks/demos/structs/triangle/triangle.cpp`

**Evidence:**
```cpp
void clear() {
    #ifdef _WIN32
    system("cls");
    #else 
    system("clear");
    #endif
}
```

**Severity:** Low (security best-practice warning in comments but code exists)  
**Fix Candidate:** Yes (use cross-platform alternative or document limitation)

---

### 8. `using namespace std` in demo files
**Evidence:**
```bash
$ grep -rn "using namespace std" notebooks/demos --include="*.cpp" | wc -l
45
```

**Severity:** Low (common in educational code, acceptable practice)  
**Fix Candidate:** No (would be too large a change for educational demos)

---

## Test Automation

### 9. No CI/CD Pipeline
**Finding:** No GitHub Actions workflows found

**Evidence:**
```bash
$ find . -path "./.github" -prune -o -name "*.yml" -print
./environment.yml
./docker-compose.yml
(no .github/workflows/)
```

**Severity:** Medium (no automated compilation testing)  
**Fix Candidate:** Yes

---

### 10. Inconsistent Makefile Standards
**Finding:** Not all Makefiles have `test` target; some use `.exe` extension, some don't

**Evidence:**
```make
# Some use .exe extension
PROGRAM = rectangle.exe

# Some don't
PROGRAM = triangle
```

**Severity:** Low  
**Fix Candidate:** Yes

---

## Educational Content Gaps

### 11. Missing CONTRIBUTING.md
**Finding:** No CONTRIBUTING.md file despite README mentioning contributions

**Evidence:**
```bash
$ cat CONTRIBUTING.md
File not found
```

**Severity:** Low  
**Fix Candidate:** Yes

---

### 12. xeus-cling Mac Silicon Warning Outdated
**Finding:** README mentions "xeus-cling C++ kernel doesn't work on Mac Silicon (M chips) as of Nov. 4 2025" - this date suggests it may be outdated

**Evidence:**
README line 63 notes this limitation but the date (Nov 2025) is in the past relative to repo context

**Severity:** Low  
**Fix Candidate:** Yes (verify if still accurate)

---

## Summary Table

| Finding | Type | Evidence | Severity | Fix Candidate? |
|---------|------|----------|----------|----------------|
| Missing `#include <climits>` | Compilation Error | 5 files use INT_MAX without include | High | Yes |
| Missing ncurses library | Compilation Error | TUI demos fail to compile | Medium | Yes |
| Signed/unsigned warnings | Code Quality | triangle.cpp:268 | Low | Yes |
| No expected output files | Documentation | 1 of 57 demos has output.txt | Medium | Yes |
| Deprecated cplusplus.com links | Documentation | 10+ instances | Low | Yes |
| HTTP links not upgraded | Documentation | pythontutor.com links | Low | Yes |
| system() calls for clear | Security | 3 files | Low | Yes |
| No CI/CD | Process | No .github/workflows | Medium | Yes |
| Inconsistent Makefiles | Standardization | Various patterns | Low | Yes |
| Missing CONTRIBUTING.md | Documentation | File not found | Low | Yes |
| Mac Silicon warning dated | Documentation | Nov 2025 date | Low | Yes |