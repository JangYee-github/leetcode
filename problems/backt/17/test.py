from random import randint

res = []
size = randint(0, 10)
for i in range(size):
	res.append(str(randint(2, 9)))


print "".join(res)
