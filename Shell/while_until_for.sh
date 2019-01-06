#!/bin/bash

j=7

while [[ $j -lt 10 ]]; do
    echo $j
    j=$(($j+1))
done

k=7
until [[ $k -eq 10 ]]; do
    echo $k
    k=$(($k+1))
done

for i in 7 8 9; do
    echo $i
done

for (( m=7; m<10; m++ )); do
    echo $m
done
