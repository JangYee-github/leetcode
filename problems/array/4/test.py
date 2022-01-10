#!/bin/python
from random import randint

size1 = randint(3, 50)
nums1 = []
for i in range(size1):
    nums1.append(randint(-100, 100))
nums1.sort()
for i in nums1:
    print i


size2 = randint(3, 50)
nums2 = []
for i in range(size2):
    nums2.append(randint(-100, 100))
nums2.sort()
for i in nums2:
    print i


print size1
