#!/bin/sh

# Make PyNEST available by prepending its path to PYTHONPATH in a safe way.
export PYTHONPATH="/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator-install/lib64/python3.10/site-packages${PYTHONPATH:+:$PYTHONPATH}"

# Make NEST executables available by prepending their path to PATH.
export PATH="/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator-install/bin:${PATH}"
