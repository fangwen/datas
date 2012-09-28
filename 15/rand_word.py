import random

in_ = open("dict.txt", 'r')
out = open("rand.txt", 'w')
line = in_.readlines()
rand = random.sample(range(0, 79339), 79339)
for i in rand:
	out.write(line[i])
out.close()
in_.close()
