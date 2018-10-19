#!/bin/bash

for i in `seq 40 47`
do
    scp /home/tanxiaoze/HaiZei/shell/pimaxstring.sh TanXze@192.168.1.$i:~
    ssh TanXze@192.168.1.$i bash pimaxstring.sh
done

`cat maxstrpi1.log > maxstrpi.log`

for j in `seq 2 8`
do
    `cat maxstrpi$j.log >> maxstrpi.log`
done

echo `cat maxstrpi.log | sort -nr | head -n 3` >> maxstrpi.log

`scp maxstrpi.log TanXze@192.168.1.49:~`
