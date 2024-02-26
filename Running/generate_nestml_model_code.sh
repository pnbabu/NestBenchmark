source start.sh &&

#!/bin/bash
LD_LIBRARY_PATH=/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator-install/lib/nest:/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator-install/lib/python3.10/site-packages/nest:$LD_LIBRARY_PATH PYTHONPATH=/p/home/jusers/linssen1/jusuf/NestBenchmark/nest-simulator-install/lib/python3.9/site-packages:/p/home/jusers/linssen1/jusuf/NestBenchmark/bmtk-fork-bmtk_nestml:/p/home/jusers/linssen1/jusuf/NestBenchmark/nestml:$PYTHONPATH python3 generate_nestml_model_code.py

