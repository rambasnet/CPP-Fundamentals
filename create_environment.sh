#! /bin/bash
mamba create -n xeus-cling -c conda-forge cmake xeus-zmq cling nlohmann_json=3.11.2 cppzmq xtl pugixml doctest cpp-argparse
source activate xeus-cling
