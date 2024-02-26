 #!/bin/bash -x 
#SBATCH --job-name="build_nest"
#SBATCH --account=<budget_ID>
#SBATCH --nodes=1
#SBATCH --cpus-per-task=128
#SBATCH --time=00:30:00
#SBATCH --partition=batch

module load Stages/2023 GCC CMake Boost GSL OpenMPI Python SciPy-Stack mpi4py GSL/2.7 libtool/.2.4.7  nano

# XXX: use parastation instead of MPI? Sandra tested -> gives same error

python3 -m pip install pytest-xdist pytest-timeout junitparser

cd
mv -vi nest-simulator /tmp
git clone https://github.com/nest/nest-simulator
cd nest-simulator
git checkout v3.6
cd ..

mv -vi nest-simulator-build /tmp/
mkdir nest-simulator-build
cd nest-simulator-build
cmake -DCMAKE_INSTALL_PREFIX:PATH=$HOME/nest-simulator-install -Dwith-mpi=OFF -Dwith-detailed-timers=ON -Dwith-optimize="-O3" -Dwith-readline=OFF ../nest-simulator

make -j16
make install

#LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/p/software/jusuf/stages/2023/software/libreadline/8.1.2-GCCcore-11.3.0/lib PATH=$PATH:$HOME/.local/bin PYTHONPATH=$HOME/.local/lib/python3.6/site-packages build/install/share/nest/testsuite/do_tests.sh --prefix=$HOME/nest-simulator-install --report-dir=`pwd`/report
