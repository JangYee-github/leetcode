#!/bin/bash


g++ main.cpp -std=c++11 -o app  && ./test.py > input1 && cat input | ./app > output
