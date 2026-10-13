# CS1 Lab - Strings and Unittest - C

Possible Points: 100

Write a C++ program to check if the given phrase is palindrome or not.

## Type and fix the code

1. Create the directory structure similar to this lab as shown below:

```bash
namespace/
├── includes/
│   └── utils.h
├── src/
│   └── utils.cpp
│   └── main.cpp
├── tests/
│   └── test_utils.cpp
├── Makefile
└── README.md
└── screenshots/
```

2. Type the contents provided in `.h`, `.hpp` and `.cpp` files and fix all fixmes. Write #fixed# after each #fixme.
3. Follow best programming practices by using proper white spaces, comments, etc.

## Whole program test

- Test the program mannually by running the executable file and take a screenshot of the output and save it to the **screenshots** folder (10 points).

```bash
make all
```

## Unit testing with Doctest

1. Create **doctest** folder in the **labs** root folder and copy the `doctest.h` file into it from [https://github.com/doctest/doctest/tree/master/doctest ](https://github.com/doctest/doctest/tree/master/doctest) if not already done in previous labs.
2. Set the doctest rule in the Makefile and run the tests. Fix any issues found.

```bash
make doctest
```

## Submission

1. Create at screenshots showing manual tests and doctest and save them to the **screenshots** folder. (10 points).
2. Update the `README.md` file (10 points) as shown here: https://github.com/rambasnet/csXXX-rbasnet

```bash
cd <main repo folder>
ls
git pull
git status
git add <each file in the red that is part of this lab>
git status
git commit -m "write brief description of what was done"
git push
git status
```

3. Make sure the files are actually pushed to your remote GitHub repo.
