from random import randint

strs = []
size = randint(0, 100)

for i in range(size):
    strs.append(chr(randint(65, 90)))

print "".join(strs)

