#!/bin/bash
./datalink A -p 30011 -l A.log -t 700 1>/dev/null&
./datalink B -p 30011 -l B.log -t 700 1>/dev/null&
./datalink A -p 30012 -l uA.log -u -t 700 1>/dev/null&
./datalink B -p 30012 -l uB.log -u -t 700 1>/dev/null&
./datalink A -p 30013 -l ufA.log -u -f -t 700 1>/dev/null&
./datalink B -p 30013 -l ufB.log -u -f -t 700 1>/dev/null&
./datalink A -p 30014 -l fA.log -f -t 700 1>/dev/null&
./datalink B -p 30014 -l fB.log -f -t 700 1>/dev/null&
./datalink A -p 30015 -l fbA.log -f -b 1e-4 -t 700 1>/dev/null&
./datalink B -p 30015 -l fbB.log -f -b 1e-4 -t 700 1>/dev/null&
