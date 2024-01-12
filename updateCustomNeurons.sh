source nest-simulator-install/bin/nest_vars.sh


cd Running/target_optimized
cmake .
make -j24 install
cd ../..

cd Running/target
cmake .
make -j24 install
cd ../..
