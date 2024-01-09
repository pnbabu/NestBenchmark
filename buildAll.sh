mkdir nest-build
mkdir nest-simulator-install

# Paths
buildPath=$(pwd)/nest-build
installPath=$(pwd)/nest-simulator-install

cd nest-build

cmake -DCMAKE_INSTALL_PREFIX:PATH=$installPath $buildPath -Dwith-detailed-timers=ON
make
make install
make installcheck



