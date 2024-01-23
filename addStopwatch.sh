#!/bin/bash

# Check if the string parameter is provided
if [ -z "$1" ]; then
    echo "Please provide a stopwatch parameter."
    exit 1
fi

# Use the string parameter
input_string="$1"
echo "The input string is: $input_string"
