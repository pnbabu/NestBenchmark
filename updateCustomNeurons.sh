source nest-simulator-install/bin/nest_vars.sh

#install custom neurons
cd Running/target
rm -rf CmakeFiles
rm -rf CMakeCache.txt
rm -rf cmake_install.cmake

cmake .
make
make install
cd ../..