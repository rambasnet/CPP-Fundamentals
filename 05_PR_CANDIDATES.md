# PR Candidates

## Candidate Backlog

---

### CANDIDATE_001
- **candidate_id:** CANDIDATE_001
- **title:** Fix missing `#include <climits>` in conditionals/rectangle
- **category:** Bug Fix (Compilation)
- **linked_issue:** None (found during audit)
- **source:** Quality Audit
- **problem:** `main.cpp` uses `INT_MAX` without including `<climits>`, causing compilation failure
- **proof/evidence:**
```
main.cpp:65:16: error: 'INT_MAX' was not declared in this scope
   65 |     cin.ignore(INT_MAX, '\n');
```
- **proposed_solution:** Add `#include <climits>` to the header includes
- **target_files:** `notebooks/demos/conditionals/rectangle/main.cpp`
- **test_plan:** Compile with `make clean && make` and verify `./rectangle.exe` runs
- **risk_level:** Low (single header include addition)
- **expected_diff_size:** ~1 line
- **merge_likelihood:** High (simple fix, obvious improvement)
- **maintainer_discussion_needed:** No
- **selected:** pending

---

### CANDIDATE_002
- **candidate_id:** CANDIDATE_002
- **title:** Fix missing `#include <climits>` in loops/rectangle
- **category:** Bug Fix (Compilation)
- **linked_issue:** None (found during audit)
- **source:** Quality Audit
- **problem:** `main.cpp` uses `INT_MAX` without including `<climits>`, causing compilation failure
- **proof/evidence:**
```
main.cpp:83:16: error: 'INT_MAX' was not declared in this scope
   83 |     cin.ignore(INT_MAX, '\n');
```
- **proposed_solution:** Add `#include <climits>` to the header includes
- **target_files:** `notebooks/demos/loops/rectangle/main.cpp`
- **test_plan:** Compile with `make clean && make` and verify executable runs
- **risk_level:** Low (single header include addition)
- **expected_diff_size:** ~1 line
- **merge_likelihood:** High (simple fix, obvious improvement)
- **maintainer_discussion_needed:** No
- **selected:** pending

---

### CANDIDATE_003
- **candidate_id:** CANDIDATE_003
- **title:** Add expected output file to conditionals/rectangle demo
- **category:** Documentation
- **linked_issue:** None (found during audit)
- **source:** Quality Audit
- **problem:** Demo has no `output.txt` file showing expected console output
- **proof/evidence:** Only 1 of 57 demos has output.txt (vectors/triangle)
- **proposed_solution:** Create `output.txt` by running the program with sample input and capturing output
- **target_files:** `notebooks/demos/conditionals/rectangle/output.txt` (new file)
- **test_plan:** Document the sample input used and expected output format
- **risk_level:** Low (documentation only)
- **expected_diff_size:** ~20-30 lines
- **merge_likelihood:** High (improves educational value)
- **maintainer_discussion_needed:** No
- **selected:** pending

---

### CANDIDATE_004
- **candidate_id:** CANDIDATE_004
- **title:** Add expected output file to loops/rectangle demo
- **category:** Documentation
- **linked_issue:** None (found during audit)
- **source:** Quality Audit
- **problem:** Demo has no `output.txt` file showing expected console output
- **proof/evidence:** Demo lacks output documentation like vectors/triangle has
- **proposed_solution:** Create `output.txt` by running the program with sample input
- **target_files:** `notebooks/demos/loops/rectangle/output.txt` (new file)
- **test_plan:** Document the sample input used and expected output format
- **risk_level:** Low (documentation only)
- **expected_diff_size:** ~20-30 lines
- **merge_likelihood:** High (improves educational value)
- **maintainer_discussion_needed:** No
- **selected:** pending

---

### CANDIDATE_005
- **candidate_id:** CANDIDATE_005
- **title:** Fix signed/unsigned comparison in structs/triangle
- **category:** Code Quality (Warning Fix)
- **linked_issue:** None (found during audit)
- **source:** Quality Audit
- **problem:** Loop uses `int i` compared against `tris.size()` which returns `size_type` (unsigned)
- **proof/evidence:**
```
triangle.cpp:268:19: warning: comparison of integer expressions of different signedness: 'int' and 'std::vector<Triangle>::size_type'
  268 |     for(int i=0; i< tris.size(); i++) {
```
- **proposed_solution:** Change `int i` to `size_t i` or use `int i = 0; i < static_cast<int>(tris.size());`
- **target_files:** `notebooks/demos/structs/triangle/triangle.cpp`
- **test_plan:** Compile with `make clean && make` and verify no warnings; run with `test` argument
- **risk_level:** Low (warning fix, behavior unchanged)
- **expected_diff_size:** ~1 line
- **merge_likelihood:** High (straightforward warning fix)
- **maintainer_discussion_needed:** No
- **selected:** pending

---

### CANDIDATE_006
- **candidate_id:** CANDIDATE_006
- **title:** Add CONTRIBUTING.md file
- **category:** Documentation
- **linked_issue:** None (found during audit)
- **source:** Quality Audit
- **problem:** No CONTRIBUTING.md exists despite README mentioning contributions
- **proof/evidence:**
```bash
$ cat CONTRIBUTING.md
File not found
```
README says "Contributions are accepted via pull requests"
- **proposed_solution:** Create CONTRIBUTING.md with guidelines for:
  - How to submit PRs
  - Code style expectations
  - How to test changes
  - Contact for questions
- **target_files:** `CONTRIBUTING.md` (new file)
- **test_plan:** Verify file is readable and properly formatted
- **risk_level:** Low (documentation only)
- **expected_diff_size:** ~30-50 lines
- **merge_likelihood:** High (standard practice, low controversy)
- **maintainer_discussion_needed:** No
- **selected:** pending

---

### CANDIDATE_007
- **candidate_id:** CANDIDATE_007
- **title:** Update deprecated cplusplus.com links to cppreference.com
- **category:** Documentation (Link Fix)
- **linked_issue:** None (found during audit)
- **source:** Quality Audit
- **problem:** Multiple links point to cplusplus.com which has had reliability/ad injection issues
- **proof/evidence:**
```
notebooks/Arrays.ipynb:10: "C-Arrays - https://cplusplus.com/doc/tutorial/arrays/\n"
notebooks/DataTypesAndVariables.ipynb:21: "Variables and Data Types in C++: [https://cplusplus.com/doc/tutorial/variables/]"
notebooks/StdInputOutput.ipynb:16: "Basic Input and Output in C++: [https://cplusplus.com/doc/tutorial/basic_io/]"
```
- **proposed_solution:** Replace cplusplus.com links with cppreference.com equivalents
  - https://cplusplus.com/doc/tutorial/arrays/ → https://en.cppreference.com/w/cpp/language/arrays
  - etc.
- **target_files:** Multiple notebooks (Arrays.ipynb, DataTypesAndVariables.ipynb, StdInputOutput.ipynb, etc.)
- **test_plan:** Verify all links work after update
- **risk_level:** Low (link updates only)
- **expected_diff_size:** ~10-15 lines across 5-6 files
- **merge_likelihood:** High (improves resource reliability)
- **maintainer_discussion_needed:** No
- **selected:** pending

---

### CANDIDATE_008
- **candidate_id:** CANDIDATE_008
- **title:** Add GitHub Actions CI workflow for compilation testing
- **category:** Process Improvement
- **linked_issue:** None (found during audit)
- **source:** Quality Audit
- **problem:** No CI pipeline to catch compilation errors in demos
- **proof/evidence:**
```bash
$ find . -path "./.github" -prune -o -name "*.yml" -print
./environment.yml
./docker-compose.yml
(no .github/workflows/)
```
- **proposed_solution:** Add `.github/workflows/compile-check.yml` that:
  - Checks out code
  - Runs `g++ --version`
  - Attempts to compile key demo programs
  - Reports success/failure
- **target_files:** `.github/workflows/compile-check.yml` (new file)
- **test_plan:** Verify workflow runs on push/PR, check compilation of sample demos
- **risk_level:** Medium (new infrastructure, needs testing)
- **expected_diff_size:** ~50-80 lines
- **merge_likelihood:** Medium (needs maintainer buy-in for CI expectations)
- **maintainer_discussion_needed:** Maybe (confirm CI scope and which demos to test)
- **selected:** pending

---

### CANDIDATE_009
- **candidate_id:** CANDIDATE_009
- **title:** Add `test` target to conditionals/rectangle Makefile
- **category:** Feature Enhancement
- **linked_issue:** None (found during audit)
- **source:** Quality Audit
- **problem:** Makefile lacks `make test` target despite program supporting `./rectangle.exe test` for assertions
- **proof/evidence:** Program uses `if (argc == 2 && string(argv[1]) == "test")` pattern but no `make test`
- **proposed_solution:** Add to Makefile:
```make
test: $(PROGRAM)
    ./$(PROGRAM) test
```
- **target_files:** `notebooks/demos/conditionals/rectangle/Makefile`
- **test_plan:** Run `make test` and verify unit tests execute
- **risk_level:** Low (Makefile enhancement)
- **expected_diff_size:** ~3-5 lines
- **merge_likelihood:** High (standardizes testing)
- **maintainer_discussion_needed:** No
- **selected:** pending

---

### CANDIDATE_010
- **candidate_id:** CANDIDATE_010
- **title:** Add expected output files to all demos that have `test` mode
- **category:** Documentation
- **linked_issue:** None (found during audit)
- **source:** Quality Audit
- **problem:** Most demos with unit test support lack output.txt expected output files
- **proof/evidence:** Only 1 demo (vectors/triangle) has output.txt out of 57 cpp files
- **proposed_solution:** Add output.txt to demos that have test mode:
  - conditionals/rectangle
  - loops/rectangle
  - structs/triangle
  - vectors/triangle
  - And others with testargv[1] == "test" pattern
- **target_files:** Multiple demo folders (new output.txt files)
- **test_plan:** Document expected behavior for each demo
- **risk_level:** Low (documentation only)
- **expected_diff_size:** ~15-20 files × ~20-30 lines = ~300-600 lines
- **merge_likelihood:** High (improves educational value)
- **maintainer_discussion_needed:** No
- **selected:** pending

---

## Summary

| candidate_id | title | category | risk_level | expected_diff_size | merge_likelihood |
|--------------|-------|----------|------------|-------------------|------------------|
| CANDIDATE_001 | Fix missing climits in conditionals/rectangle | Bug Fix | Low | ~1 line | High |
| CANDIDATE_002 | Fix missing climits in loops/rectangle | Bug Fix | Low | ~1 line | High |
| CANDIDATE_003 | Add output.txt to conditionals/rectangle | Documentation | Low | ~25 lines | High |
| CANDIDATE_004 | Add output.txt to loops/rectangle | Documentation | Low | ~25 lines | High |
| CANDIDATE_005 | Fix signed/unsigned warning in triangle | Code Quality | Low | ~1 line | High |
| CANDIDATE_006 | Add CONTRIBUTING.md | Documentation | Low | ~40 lines | High |
| CANDIDATE_007 | Update cplusplus.com links to cppreference | Documentation | Low | ~15 lines | High |
| CANDIDATE_008 | Add GitHub Actions CI workflow | Process | Medium | ~65 lines | Medium |
| CANDIDATE_009 | Add test target to Makefile | Feature | Low | ~4 lines | High |
| CANDIDATE_010 | Add output.txt to all test-capable demos | Documentation | Low | ~400 lines | High |

**Total Candidates:** 10