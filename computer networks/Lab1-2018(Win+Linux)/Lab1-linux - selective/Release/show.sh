#!/bin/bash
echo `tail -n 5 u$1.log | grep -P '\d\d\.\d\d%' -o | tail -n 1`
echo `tail -n 5 $1.log | grep -P '\d\d\.\d\d%' -o | tail -n 1`
echo `tail -n 5 uf$1.log | grep -P '\d\d\.\d\d%' -o | tail -n 1`
echo `tail -n 5 f$1.log | grep -P '\d\d\.\d\d%' -o | tail -n 1`
echo `tail -n 5 fb$1.log | grep -P '\d\d\.\d\d%' -o | tail -n 1`

