#!/bin/bash
ASSIGNMENT_PATH="assignment_$1"
ASSIGNMENT_NAMES=(
    "1" 
    "2" 
    "3" 
    "4" 
    "5" 
    "shaderpipeline")

echo "Assignment path ${ASSIGNMENT_PATH}"
cd $ASSIGNMENT_PATH
cd $(ls -d */|head -n 1)
pwd
echo ${ASSIGNMENT_NAMES[$1-1]}

git pull 
cd build
cmake ..
make


