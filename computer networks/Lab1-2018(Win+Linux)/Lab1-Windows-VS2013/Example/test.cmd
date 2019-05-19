@echo off
echo 'Initializing'
start %1 A -p 300%21 -l A.log -t 700
start %1 B -p 300%21 -l B.log -t 700
start %1 A -p 300%22 -l uA.log -u -t 700
start %1 B -p 300%22 -l uB.log -u -t 700
start %1 A -p 300%23 -l ufA.log -u -f -t 700
start %1 B -p 300%23 -l ufB.log -u -f -t 700
start %1 A -p 300%24 -l fA.log -f -t 700
start %1 B -p 300%24 -l fB.log -f -t 700
start %1 A -p 300%25 -l fbA.log -f -b 1e-4 -t 700
start %1 B -p 300%25 -l fbB.log -f -b 1e-4 -t 700
echo 'Initialized'
