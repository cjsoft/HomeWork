#!/usr/bin/python
import random
lst = raw_input().split()
f = open(lst[0], 'w')
f.write(lst[1] + ' ' + lst[2] + '\n')
for i in range(int(lst[1])):
    for j in range(int(lst[2])):
        f.write(str(random.randint(-100000, 100000)) + ' ')
    f.write('\n')
f.close()
