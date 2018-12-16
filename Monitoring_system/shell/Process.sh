#!/bin/bash

TIME=`date +"%Y-%m-%d__%H:%M:%S"`

`ps -aux | awk '{if($3 > 50 || $4 > 50) print $11" "$2" "$1" "$3" "$4}' > /home/tanxiaoze/HaiZei/Monitoring_system/shell/txtfile/Process1.txt`
sleep 5
`ps -aux | awk '{if($3 > 50 || $4 > 50) print $11" "$2" "$1" "$3" "$4}' > /home/tanxiaoze/HaiZei/Monitoring_system/shell/txtfile/Process2.txt`

flag=0
for i in `cat /home/tanxiaoze/HaiZei/Monitoring_system/shell/txtfile/Process2.txt | awk '{print $2}'`
do
    for j in `cat /home/tanxiaoze/HaiZei/Monitoring_system/shell/txtfile/Process1.txt | awk '{print $2}'`
    do 
        if [[ $i == $j ]]
        then
            (( flag++ ))
            if [[ $flag -eq 1 ]]
            then
                `cat /home/tanxiaoze/HaiZei/Monitoring_system/shell/txtfile/Process2.txt | grep $j > /home/tanxiaoze/HaiZei/Monitoring_system/shell/txtfile/Process.txt`
            else
                `cat /home/tanxiaoze/HaiZei/Monitoring_system/shell/txtfile/Process2.txt | grep $j >> /home/tanxiaoze/HaiZei/Monitoring_system/shell/txtfile/Process.txt`
            fi
        fi
    done
done

Process=`cat /home/tanxiaoze/HaiZei/Monitoring_system/shell/txtfile/Process.txt`

echo "$TIME $Process" >> /home/tanxiaoze/HaiZei/Monitoring_system/shell/logfile/Process.log
