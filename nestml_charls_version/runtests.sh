#!/bin/bash

export GITHUB_WORKSPACE=`pwd`
export NEST_INSTALL=/home/charl/nest-simulator-install





python3 extras/codeanalysis/check_copyright_headers.py
python3 -m pycodestyle $GITHUB_WORKSPACE --ignore=E241,E501,E714,E713,E714,E252,W503 --exclude=tests --exclude=$GITHUB_WORKSPACE/doc,$GITHUB_WORKSPACE/.git,$GITHUB_WORKSPACE/NESTML.egg-info,$GITHUB_WORKSPACE/pynestml/generated,$GITHUB_WORKSPACE/extras,$GITHUB_WORKSPACE/build,$GITHUB_WORKSPACE/.github


echo "RUn UNIT TESTS"

LD_LIBRARY_PATH=/home/charl/nest-simulator-install/lib/nest:/home/charl/nest-simulator-install/lib/python3.9/site-packages/nest:/home/charl/nest-simulator-install/pynest PYTHONPATH=/home/charl/nest-simulator-install/lib/python3.9/site-packages:`pwd`:/home/charl/ode-toolbox-upstream/ode-toolbox pytest -s  --pdb -o log_cli=true -o log_cli_level="DEBUG" tests/*.py


echo  "PREPARE INTEGRATION TESTS"

          cd $GITHUB_WORKSPACE
          # exclude third factor plasticity models; these will only compile successfully if code generation is as a neuron+synapse pair
          export ALL_MODEL_FILENAMES=`find models/neurons -name "*.nestml" | paste -sd " "`
          echo $ALL_MODEL_FILENAMES
          nestml --input_path $ALL_MODEL_FILENAMES --target_path target --suffix _nestml --logging_level INFO --module_name nestml_allmodels_module
          cd target
          echo "NEST_INSTALL = $NEST_INSTALL"
          cmake -Dwith-nest=$NEST_INSTALL/bin/nest-config .
          make && make install


          cd $GITHUB_WORKSPACE

echo "RUN INTEGRATION TESTS"

rc=0
for fn in $GITHUB_WORKSPACE/tests/nest_tests/*.py; do
           LD_LIBRARY_PATH=/home/charl/nest-simulator-install/lib/nest:/home/charl/nest-simulator-install/lib/python3.9/site-packages/nest:/home/charl/nest-simulator-install/pynest PYTHONPATH=/home/charl/nest-simulator-install/lib/python3.9/site-packages:`pwd`:/home/charl/ode-toolbox-upstream/ode-toolbox pytest -s  --pdb -o log_cli=true -o log_cli_level="DEBUG" ${fn} || rc=1
done
exit $rc
