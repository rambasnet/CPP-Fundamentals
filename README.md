# C++ Fundamentals
- Jupyter Notebooks for Learning Computer Science Foundational Concepts (CS1) using C++
- Most chapters of notebooks are based on the open source textbook: Think C++ by Allen B. Downey
- PDF of the textbook can be found at [http://www.greenteapress.com/thinkcpp/thinkCScpp.pdf](http://www.greenteapress.com/thinkcpp/thinkCScpp.pdf)


## Requirements
- Linux/MacOS/WSL on Windows (Not tested on Windows itself)
- Jupyter Notebook
- xeus-cling notebook kernel to run C++ code in Jupyter
- git client

## Install required tools
- Note: these libraries and tools need to be installed just once, if you've Jupyter Notebook with C++, you can safely ignore this section

- git client is already available on Mac and Linux
- install Miniconda: [https://conda.io/miniconda.html](https://conda.io/miniconda.html)
- open a terminal/shell and run the following commands
- create a virual environment to keep C++ specific installtions seperate from base installation

```bash
    conda create -n cpp python=3.7 # create virtual env named cpp with Python3.7 support
    conda activate cpp #activate the virual environemnt
    conda install notebook
    conda install -c conda-forge xeus-cling
    conda install -c conda-forge jupyter_contrib_nbextensions
    conda install -c conda-forge jupyter_nbextensions_configurator
    jupyter nbextensions_configurator enable --user
```

## Run notebooks
- clone the repository locally once the tools are installed
- open a terminal and cd into this cloned repo and run jupyter notebook

```bash
    cd <CPP Fundamentals repo folder>
    conda activate cpp
    jupyter notebook
```

- Enter ctrl+c to stop jupyter notebook from the terminal where its running from
- $ conda deactivate # to deactivate the virtual env and go back to base installation