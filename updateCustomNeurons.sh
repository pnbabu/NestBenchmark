source nest-simulator-install/bin/nest_vars.sh


cd Running/target_optimized
rm -rf CMakeCache.txt CMakeFiles
cmake .
make -j24 install
cd ../..

cd Running/target
rm -rf CMakeCache.txt CMakeFiles
cmake .
make -j24 install
cd ../..
