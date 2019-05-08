#!/bin/bash
if [ -n "$1" ]
then
    for i in "u" "" "uf" "f" "fb"
    do
        if [ -f "$i$1.log" ]
        then
            echo `tail -n 5 "$i$1.log" | grep -P '\d\d\.\d\d%' -o | tail -n 1`
        fi
    done
else
    echo "No parameter"
    # echo `tail -n 5 $1.log | grep -P '\d\d\.\d\d%' -o | tail -n 1`
    # echo `tail -n 5 uf$1.log | grep -P '\d\d\.\d\d%' -o | tail -n 1`
    # echo `tail -n 5 f$1.log | grep -P '\d\d\.\d\d%' -o | tail -n 1`
    # echo `tail -n 5 fb$1.log | grep -P '\d\d\.\d\d%' -o | tail -n 1`
fi
