#!/bin/bash
arr=('1' '10' '30' '2' '20' '30' '3' '10' '100' '4' '20' '50' '4' '20' '50' '4' '20' '50' '4' '20' '50')
for i in 0 1 2 3 4 5 6
do
    echo "./data/case${arr[0 + $i * 3]}.txt ${arr[1 + $i * 3]} ${arr[2 + $i * 3]}" | python gen.py
done
