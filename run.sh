cd Running
nohup python3 benchmark.py > /dev/null 2>&1 & echo $! > pid.txt

cd ..
chmod +x getConsoleLog.sh
./getConsoleLog.sh

