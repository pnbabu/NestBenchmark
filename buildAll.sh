rm -rf nest-build
rm -rf nest-simulator-install


# Paths
srcPath=$(pwd)/nest-simulator
installPath=$(pwd)/nest-simulator-install

mkdir nest-build
mkdir nest-simulator-install

cd nest-build

cmake -DCMAKE_INSTALL_PREFIX:PATH=$installPath $srcPath -Dwith-mpi=OFF -Dwith-optimize="-O3" -Dwith-readline=OFF -Dwith-detailed-timers=ON
make
make -j24 install
make installcheck

cd ..

