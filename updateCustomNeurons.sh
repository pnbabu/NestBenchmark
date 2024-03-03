source nest-simulator-install/bin/nest_vars.sh

for dir in Running/target_*; do
    if [ -d "$dir" ]; then
        cd "$dir"
        rm -rf CMakeCache.txt CMakeFiles
        cmake .
        make -j24 install
        cd ../..
    fi
done


