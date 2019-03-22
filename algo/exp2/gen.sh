#!/bin/bash
for ((i=100;i<=100000;i=i*10))
do
    echo -e "random\n"$i | python gen.py > "./data/r"$i".txt"
    ./std.out < "./data/r"$i".txt" > "./data/r"$i".ans"
    echo -e "increase\n"$i | python gen.py > "./data/i"$i".txt"
    ./std.out < "./data/i"$i".txt" > "./data/i"$i".ans"
    echo -e "decrease\n"$i | python gen.py > "./data/d"$i".txt"
    ./std.out < "./data/d"$i".txt" > "./data/d"$i".ans"
done
