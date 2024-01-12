source start.sh &&

#!/bin/bash
LD_LIBRARY_PATH=/home/lukkyguy/code/NestBenchmark/nest-simulator-install/lib/nest:/home/lukkyguy/code/NestBenchmark/nest-simulator-install/lib/python3.10/site-packages/nest:$LD_LIBRARY_PATH PYTHONPATH=/home/lukkyguy/code/NestBenchmark/nest-simulator-install/lib/python3.9/site-packages:/home/lukkyguy/code/NestBenchmark/bmtk-fork-bmtk_nestml:/home/charl/nestml:$PYTHONPATH python3 generate_nestml_model_code.py

