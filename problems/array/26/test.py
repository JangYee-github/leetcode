#!/bin/python
from random import randint

size = randint(3, 100)

nums = []
for i in range(size):
    nums.append(randint(1, 20))

nums.sort()

for i in nums:
    print i
