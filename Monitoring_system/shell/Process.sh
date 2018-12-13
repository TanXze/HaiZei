#!/bin/bash

TIME=`date +"%Y-%m-%d__%H:%M:%S"`

`ps -aux | awk '{if($3 > 50 || $4 > 50) print $11" "$2" "$1" "$3" "$4}' > ./txtfile/Process1.txt`
sleep 5
`ps -aux | awk '{if($3 > 50 || $4 > 50) print $11" "$2" "$1" "$3" "$4}' > ./txtfile/Process2.txt`

flag=0
for i in `cat ./txtfile/Process2.txt | awk '{print $2}'`
do
    for j in `cat ./txtfile/Process1.txt | awk '{print $2}'`
    do 
        if [[ $i == $j ]]
        then
            (( flag++ ))
            if [[ $flag -eq 1 ]]
            then
                `cat ./txtfile/Process2.txt | grep $j > ./txtfile/Process.txt`
            else
                `cat ./txtfile/Process2.txt | grep $j >> ./txtfile/Process.txt`
            fi
        fi
    done
done

Process=`cat ./txtfile/Process.txt`

echo "$TIME $Process" >> ./logfile/Process.log
