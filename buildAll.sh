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

cmake -DCMAKE_INSTALL_PREFIX:PATH=$installPath $srcPath -Dwith-mpi=OFF -Dwith-optimize="-O3" -Dwith-readline=OFF -Dwith-detailed-timers=ON 
make -j24 install


cd ..

echo installing nestml
#install nestml
cd nestml
python3 pip install setup.py
cd ..

source nest-simulator-install/bin/nest_vars.sh

echo installing custom neurons
#install custom neurons

source updateCustomNeurons.sh