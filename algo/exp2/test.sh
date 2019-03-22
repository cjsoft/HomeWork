#!/bin/bash

function check() {
    echo -e "\n$1 $3 \c"
    str="./$1.out < ./data/$3$2.txt > runtime.txt"
    eval $str
    if [ "$(diff -Bb <(head -n 1 runtime.txt) <(head -n 1 ./data/$3$2.ans))" = "" ]
    then
        echo "AC"
    else
        echo "WA"
    fi
    tail -n 1 runtime.txt
}
for ((i=100; i<=100000; i=i*10))
do
    echo -e "\n\n\n$i\c"
    # echo "qsort"
    # ./qsort.out < "./data/r"$i".txt" > runtime.txt
    # if [ "$(diff -Bb <(head -n 1 runtime.txt) <(head -n 1 ./data/r$i.txt))" != "" ]
    # then
    #     echo "AC"
    # else
    #     echo "WA"
    # fi
    # tail -n 1 runtime.txt
    for j in "r" "i" "d"
    do

        check "qsort" $i $j
        check "msort" $i $j
        check "isort" $i $j
    done
    # ./msort.out < "./data/r"$i".txt" > runtime.txt
    # ./isort.out < "./data/r"$i".txt" > runtime.txt
done
