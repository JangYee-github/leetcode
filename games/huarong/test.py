#!/bin/python

from random import randint

res = [x for x in range(1,10)]
size = 8

# print res

for i in range(9):
	index = randint(0, size)
	print res[index]
	del res[index]
	size -= 1

