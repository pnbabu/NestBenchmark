

# Run the start.sh file
source start.sh &&

#!/bin/bash
LD_LIBRARY_PATH=/home/lukkyguy/code/nest-simulator-install/lib/nest:/home/lukkyguy/code/nest-simulator-install/lib/python3.9/site-packages/nest:$LD_LIBRARY_PATH PYTHONPATH=/home/charl/nest-simulator-install/lib/python3.9/site-packages:/home/charl/bmtk-fork-bmtk_nestml:/home/charl/nestml-fork-integrate_specific_odes/nestml:$PYTHONPATH python3 benchmark.py
