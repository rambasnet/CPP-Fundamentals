# C++ Fundamentals

- Jupyter Notebooks for Computer Science Foundational Concepts (CS1) using C++
- some of the contents are based on the open source textbook: Think C++ by Allen B. Downey
    - others are based on https://en.cppreference.com/ and http://cplusplus.com/
    - PDF of the textbook can be found at [http://www.greenteapress.com/thinkcpp/thinkCScpp.pdf](http://www.greenteapress.com/thinkcpp/thinkCScpp.pdf)

## PDF Format

- pdf format of each chapter can be found in [pdfs](https://github.com/rambasnet/CPPFundamentals-Notebooks/tree/master/pdfs) folder

## System Requirements

- Linux/MacOS/WSL on Windows
- Jupyter Notebook
- xeus-cling kernel to run C++ code in Jupyter notebook
- git client - 
- G++ compiler to run sample codes, solve exercises and labs
- VS Code - Editor to write C++ code

### Note: xeus-cling doesn't support Windows
### Detail step-by-step instructions (with screenshots) can be found here: https://github.com/rambasnet/DevEnvSetup

## Install required tools

- Note: these libraries and tools need to be installed just once, if you've Jupyter Notebook with C++, you can safely ignore this section

- git client is already available on Mac and Linux
- install Miniconda: [https://conda.io/miniconda.html](https://conda.io/miniconda.html)
- open a terminal/shell and run the following commands
- create a virual environment to keep C++ specific installtions seperate from base installation

    ```bash
        conda update conda
        conda create -n cpp python=3.7
        conda activate cpp
        conda install notebook
        conda install -c conda-forge xeus-cling
        conda install -c conda-forge jupyter_contrib_nbextensions
        conda install -c conda-forge jupyter_nbextensions_configurator
        jupyter nbextensions_configurator enable --user
    ```

## Run or Use notebooks natively

- clone the repository locally once the tools are installed
- open a terminal and cd into this cloned repo and run jupyter notebook

    ```bash
        cd <CPP Fundamentals repo folder>
        conda activate cpp
        jupyter notebook
    ```

- Enter ctrl+c to stop jupyter notebook from the terminal where its running from
- $ conda deactivate # to deactivate the virtual env and go back to base installation

## Run notebooks using VS Code

- alternatively, VS Code can be used to load and execute notebooks
- VS Code will help you find the right plugins if missing to render and execute notebooks

## Demo programs and sample solutions

- Jupyter Notebook doesn't run complete C++ program with main()
- complete demo programs and example solutions are provided in demo_programs folder
- these programs need to be compiled using any C++ compiler (with C++11 or newer standandard)

## Compiling and running C++ programs with g++

- open a terminal and run the following commands
- cd into a chapter with with sample program; compile and run the program

    ```bash
       cd demo_programs/Ch...
       g++ -g -Wall -std=c++17 -o programName inputFile.cpp
       ./programName
    ```
    
- OR use Makefile see demo_program and labs folder for examples
- once the Makefile is created; use the following commands from terminal
    ```bash
        make all
        ./programName
        make clean
    ```

## Compiling and running C++ programs with VS Code

- install C/C++ extensions for VS Code
- open integreted terminal: View -> Terminal and follow the commands above
- you can also click run button on the top right corner for some programs, but not recommended for many programs that are interactive
