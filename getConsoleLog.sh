#!/bin/bash

# Check if the PID file exists
if [ -f Running/pid.txt ]; then
    # Read the PID from the file
    PID=$(cat Running/pid.txt)

    # Check if the process is still running
    if ps -p $PID > /dev/null; then
        echo "Resuming Python script with PID: $PID"
        # Attach to the console session of the Python script
        screen -r $PID
    else
        echo "Python script with PID $PID is not running."
        exit 1
    fi
else
    echo "No PID file found. Make sure the script is started first."
    exit 1
fi