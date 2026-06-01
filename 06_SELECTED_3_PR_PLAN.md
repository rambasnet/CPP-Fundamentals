# Selected 3 PR Plan

## Selected Candidates for Implementation

### Selected PR #1: Fix missing `#include <climits>` in conditionals/rectangle

**CANDIDATE_001**

- **Target File:** `notebooks/demos/conditionals/rectangle/main.cpp`
- **Change:** Add `#include <climits>` to header section
- **Rationale:** This file fails to compile due to `INT_MAX` usage without the required header. Simple, high-value fix.
- **Testing:**
  ```bash
  cd notebooks/demos/conditionals/rectangle
  make clean && make
  ./rectangle.exe
  # (manual test with sample input)
  ./rectangle.exe test
  # (verify unit tests pass)
  ```

---

### Selected PR #2: Fix missing `#include <climits>` in loops/rectangle

**CANDIDATE_002**

- **Target File:** `notebooks/demos/loops/rectangle/main.cpp`
- **Change:** Add `#include <climits>` to header section
- **Rationale:** Same issue as PR #1 - another demo fails to compile. Can be combined with PR #1 as a single PR if desired.
- **Testing:**
  ```bash
  cd notebooks/demos/loops/rectangle
  make clean && make
  ./rectangle.exe
  # (manual test with sample input)
  ./rectangle.exe test
  # (verify unit tests pass)
  ```

---

### Selected PR #3: Add CONTRIBUTING.md file

**CANDIDATE_006**

- **Target File:** `CONTRIBUTING.md` (new file)
- **Change:** Create CONTRIBUTING.md with contribution guidelines
- **Rationale:** No CONTRIBUTING.md exists despite README mentioning contributions. Standard practice for open source repos.
- **Proposed Content:**
  ```markdown
  # Contributing to CPP-Fundamentals
  
  Contributions are welcome! Here's how to contribute:
  
  ## Ways to Contribute
  - Report bugs via GitHub Issues
  - Suggest improvements via GitHub Issues
  - Submit PRs for bug fixes or enhancements
  
  ## Process
  1. Fork the repository
  2. Create a feature branch
  3. Make your changes
  4. Test that demos compile with `make clean && make`
  5. Submit a PR with description of changes
  
  ## Code Standards
  - Use `-Wall -std=c++17` flags for compilation
  - Add `#include <climits>` for INT_MAX usage
  - Use size_t for loop indices when comparing with .size()
  ```
- **Testing:** Verify file is properly formatted and readable

---

## Implementation Order

1. **PR #1** - Fix conditionals/rectangle compilation error
2. **PR #2** - Fix loops/rectangle compilation error
3. **PR #3** - Add CONTRIBUTING.md

## Alternative: Combine PR #1 and #2

Since both PR #1 and PR #2 fix the same issue (missing `#include <climits>`), they could be combined into a single PR targeting both files. This is acceptable because:
- Same root cause
- Same fix pattern
- Low risk combined change

**Combined PR approach:**
- Single PR for both `notebooks/demos/conditionals/rectangle/main.cpp` and `notebooks/demos/loops/rectangle/main.cpp`
- Title: "Fix missing #include <climits> in demo programs"
- Description explains both files had the same issue

## Risk Assessment

| PR | Risk Level | Notes |
|----|------------|-------|
| #1 | Low | Single line header addition |
| #2 | Low | Single line header addition |
| #3 | Low | New file creation, no code changes |

## Expected Outcomes

- **Before:** 2 demo programs fail to compile
- **After:** All demo programs compile successfully
- **Additional:** Repository has clear contribution guidelines

## Branch Strategy

```
main (upstream/main)
 └── fix/climits-rectangle (PR #1)
      └── fix/climits-loops-rectangle (PR #2)
           └── docs/add-contributing (PR #3)
```

Or combined:
```
main (upstream/main)
 └── fix/missing-climits-in-demos (PR #1 + #2)
      └── docs/add-contributing (PR #3)
```