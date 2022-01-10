#!/bin/python
from random import randint

size = randint(3, 100)

nums = []
for i in range(size):
    nums.append(randint(-100, 100))


for i in nums:
    print i
