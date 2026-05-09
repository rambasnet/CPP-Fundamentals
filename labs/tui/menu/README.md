# CS1 Lab - Textual User Interface (TUI) Menu with ncurses

Possible Points: 100

Write a C++ program to perform basic math operations using a textual user interface (TUI) menu. Run the program in the terminal and use the arrow keys to navigate through the menu and perform operations. Read the problem statement carefully to design a correct solution.

## Type and fix the code

1. Create the directory structure similar to this lab as shown below:

```bash
tui_menu/
├── include/
│   └── my_math.hpp
│   └── tui.hpp
├── src/
│   └── main.cpp
│   └── my_math.cpp
│   └── tui.cpp
├── tests/
│   └── test_mymath.cpp
├── Makefile
└── README.md
└── screenshots/
```

2. Type the contents provided in `.h`, `.hpp`, and `.cpp` files and fix all fixmes. Write #fixed# after each #fixme.
3. Follow best programming practices by using proper white spaces, comments, etc.

## Whole program test

- Test the program mannually by running the executable file.

```bash
make run
```

## Unit testing with Doctest

1. Set the doctest rule in the Makefile and run the tests. Fix any issues if found.

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
