#!/bin/bash

LD_LIBRARY_PATH=/home/charl/nest-simulator-install/lib/nest:/home/charl/nest-simulator-install/lib/python3.9/site-packages/nest:$LD_LIBRARY_PATH PYTHONPATH=/home/charl/nest-simulator-install/lib/python3.9/site-packages:/home/charl/bmtk-fork-bmtk_nestml:/home/charl/nestml-fork-integrate_specific_odes/nestml:$PYTHONPATH python3 generate_nestml_model_code.py

