#!/usr/bin/python

import random
import sys
pat = raw_input().strip()
casesize = input()
lst = list()
for i in xrange(casesize):
    lst.append(random.randint(0, 1000000000))

if (pat == "increase"):
    lst.sort()
if (pat == "decrease"):
    lst.sort(reverse = True)
sys.stdout.write("%d\n"%casesize)
sys.stdout.write(' '.join(map(str, lst)))
