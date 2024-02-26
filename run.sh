#!/bin/bash

module load Stages/2023 GCC CMake Boost GSL OpenMPI Python SciPy-Stack mpi4py GSL/2.7 libtool/.2.4.7  nano

cd Running
python3 benchmark.py
cd ..
