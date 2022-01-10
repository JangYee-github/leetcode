#!/bin/bash

if [ "x$1" == "xown" ]; then
    echo g++ -std=c++11 main.cpp -Iown -g -o own/app
elif [ "x$1" == "xoffice" ]; then
    echo g++ -std=c++11 main.cpp -Ioffice -g -o office/app
fi
g++ -std=c++11 main.cpp -Iown -g -o own/app
g++ -std=c++11 main.cpp -Ioffice -g -o office/app

echo $1

for i in `seq $1`
do
    echo $i
    python test.py > /tmp/input
    cat /tmp/input | own/app  > /tmp/own.output
    cat /tmp/input | office/app > /tmp/office.output
    diff /tmp/own.output /tmp/office.output
    if [ $? -eq 0 ]; then
        echo "you are right"
    else
        echo "you are error"
    fi
done
