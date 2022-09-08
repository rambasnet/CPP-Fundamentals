# C++ Fundamentals

- Jupyter Notebooks, Pdfs, Powerpoint Slides, Lecture Notes, Labs and Exercises for Computer Science Foundational Concepts (CS1) using C++
- some of the contents are based on the open source textbook: Think C++ by Allen B. Downey, [https://en.cppreference.com/](https://en.cppreference.com/) and [http://cplusplus.com/](http://cplusplus.com/)
- PDF of the textbook can be found at [http://www.greenteapress.com/thinkcpp/thinkCScpp.pdf](http://www.greenteapress.com/thinkcpp/thinkCScpp.pdf)

## PDF format

- pdf of each jupyter notebook chapter can be found in [pdfs](https://github.com/rambasnet/CPPFundamentals-Notebooks/tree/master/pdfs) folder
- pdfs of lecture notes can be found in [notes](https://github.com/rambasnet/CPP-Fundamentals/tree/master/notes) folder


## Powerpoint slides

- powerpoint slides and corresponding pdfs based on the lecutre notes are found in [slides](https://github.com/rambasnet/CPP-Fundamentals/tree/master/slides) folder

## Who can use this content

### University and high-school coding instructors

Depending on the course level and topics covered, instructors can pick and choose appropriate chapters.

### Self learners

Depending on their skill and interest level, learners can move as swiftly as appropriate through the chapters. Try solving some exercises towards the end of each chapter before moving on to self-assess the mastery of the materials.

## How to use Jupyter Notebook

### Important

In order to learn coding, it's very important to actually type code on your own from scratch and NOT copy paste! You can run provided cells to see the output, follow along and learn from it. However, it's very important that you either start a new notebook or add cells and write your own code from scratch to practice the concepts covered with many similar examples and solve the exercises provided.

### Online services

You can launch an interactive session of this project using online [Binder](http://mybinder.org/) service:
[![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/rambasnet/CPP-Fundamentals/HEAD?filepath=Ch00-TableOfContents.ipynb)

### On a local system

To run these notebooks interactively and save your work locally, you need the following environment and programs installed.

- Linux, MacOS or WSL (Ubuntu App) on Windows
- Jupyter Notebook - learning environment
- xeus-cling kernel - to execute C++ code in Jupyter notebook
- git client - to use version control
- g++ compiler - to compile and run sample codes, solve exercises and labs
- VS Code or any Code Editor to write C++ programs

#### Setup development environment

- detail step-by-step instructions (with screenshots) can be found here: [https://github.com/rambasnet/DevEnvSetup](https://github.com/rambasnet/DevEnvSetup)

#### Install required programs

- if you went through Development Environment Setup step, you can ignore this section
- Note: these libraries and tools need to be installed just once, if you've Jupyter Notebook with C++ Kernel, you can safely ignore this section

- git client is already available on Mac and Linux
- install Miniconda: [https://conda.io/miniconda.html](https://conda.io/miniconda.html)
- open a terminal/shell and run the following commands
- create a virual environment to keep C++ specific installtions seperate from base installation

```bash
    conda update conda
    conda create -n cpp python=3.9
    conda activate cpp
    conda install -c conda-forge retrolab # jupyter notebook/retro
    conda install -c conda-forge xeus-cling
```

#### Run Jupyter notebook or retrolab on a local system

- clone the repository locally once the tools are installed
- open a Terminal and `cd` into this cloned repo folder and run `jupyter notebook`

```bash
    cd <CPP Fundamentals repo folder>
    conda activate cpp # activate virtualenv cpp if created
    jupyter notebook # run notebook
    jupyter retro # run retrolab
```

- Enter ctrl+c to stop jupyter notebook from the terminal where its running from
- to deactivate the virtual env and go back to base installation type the following command

```bash
    conda deactivate
```

## NOTE: Use C++11 or C++14 kernels. C++17 kernel is not working as of xeus-cling version 0.13 (August 2022).

## Demo programs and sample solutions to exercises

- Jupyter Notebook doesn't run complete C++ program with main()
- complete demo programs and example solutions to selected exercises are provided in [demos](https://github.com/rambasnet/CPP-Fundamentals/tree/master/demos) folder
- these programs need to be compiled using any C++ compiler (g++ recommended with C++11 or newer standard)

## Compiling and running C++ programs

### Compiling with g++ compiler

- open a terminal and run the following commands
- `cd` into a folder with a demo program; compile and run the program

```bash
    cd demos/Ch...
    g++ -g -Wall -std=c++17 -o programName inputFile.cpp
    ./programName
```

### Compiling with Make program

- see GNU Make: [https://www.gnu.org/software/make/](https://www.gnu.org/software/make/)
- create a Makefile in the project folder; see `makefile_demos` folder for examples
- once the Makefile is created; run the following commands on a Terminal
- `cd` into the project folder with the Makefile; compile and run the program using make command

```bash
    cd <project_folder>
    make
    make run
    make clean
```

### Compiling and running C++ programs with [VS Code](https://code.visualstudio.com/)

- install C/C++ extensions for VS Code
- open integreted terminal in VS Code: View -> Terminal and follow the commands above
- you can also click run button on the top right corner for some programs, but not recommended for many programs that are interactive

## Content contributors

1. Ram Basnet, PhD, (rbasnet@coloradomesa.edu) Professor of Computer Science, Colorado Mesa University
2. Sherine Antoun, PhD, (santoun@coloradomesa.edu) Professor of Computer Science, Colorado Mesa University

## Contributing

Contributions are accepted via pull requests. You can also open issues on bugs, typos or any corrections and suggest improvements on the notebooks and other contents.

## Copyright and License

Permission is granted to copy, distribute and/or modify this document under the terms of the [MIT License](https://opensource.org/licenses/MIT). See LICENSE file for details.
