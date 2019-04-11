#!/bin/bash
for i in case1.txt case2.txt case3.txt case4.txt case5.txt case6.txt case7.txt
do
    if [ "$(diff -Bb <(./dp < $i | head -n 1) <(./dnc < $i))" != "" ]
    then
        echo "WA $i"
    else
        echo "AC $i"
    fi
done
