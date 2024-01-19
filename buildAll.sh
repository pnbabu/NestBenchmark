module load Stages/2023 GCC CMake Boost GSL OpenMPI Python SciPy-Stack mpi4py GSL/2.7 libtool/.2.4.7  nano

echo installing nestml-simulator

#Install nestsimulator
rm -rf nest-build
rm -rf nest-simulator-install


# Paths
srcPath=$(pwd)/nest-simulator
installPath=$(pwd)/nest-simulator-install

mkdir nest-build
mkdir nest-simulator-install

cd nest-build

cmake -DCMAKE_INSTALL_PREFIX:PATH=$installPath $srcPath -Dwith-mpi=ON -Dwith-optimize="-O3" -Dwith-readline=OFF -Dwith-detailed-timers=ON 
make -j24 install


cd ..

echo installing nestml
#install nestml
cd nestml
python3 -m pip install .
cd ..

source nest-simulator-install/bin/nest_vars.sh

echo installing custom neurons
#install custom neurons

source updateCustomNeurons.sh