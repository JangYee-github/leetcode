from random import randint

head = ""
size = randint(0, 10)
for i in range(size):
    head += chr(randint(65, 90))


size = randint(0, 10)
for i in range(size):
    tail = ""
    tsize = randint(0, 10)
    for j in range(tsize):
        tail += chr(randint(65, 90))
    print head + tail
