#!/bin/sh

# Make PyNEST available by prepending its path to PYTHONPATH in a safe way.
export PYTHONPATH="/home/lukkyguy/code/BachlorThesis/nest-install/lib/python3.10/site-packages${PYTHONPATH:+:$PYTHONPATH}"

# Make NEST executables available by prepending their path to PATH.
export PATH="/home/lukkyguy/code/BachlorThesis/nest-install/bin:${PATH}"
