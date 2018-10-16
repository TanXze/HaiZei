#!/bin/bash

for i in `seq 40 49`
do
    scp /home/tanxiaoze/HaiZei/shell/pimaxstring.sh TanXze@192.168.1.$i:~
    ssh TanXze@192.168.1.$i bash pimaxstring.sh
done

echo `cat maxstrpi?.log` > maxstrpi.log

maxstr=`cat maxstrpi.log | awk '{print $1}' | sort -n | head -n 1`

echo `cat maxstrpi.log | grep "${maxstr}"`

