#!/bin/bash
for i in ./data/case1.txt ./data/case2.txt ./data/case3.txt ./data/case4.txt ./data/case5.txt ./data/case6.txt ./data/case7.txt
do
    if [ "$(diff -Bb <(./dp < $i | head -n 1) <(./dnc < $i))" != "" ]
    then
        echo "WA $i"
    else
        echo "AC $i"
    fi
done
