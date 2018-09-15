#!/bin/bash

echo "`df -m | grep -v "tmpfs" | grep -v "Filesystem" | grep -v "loop" | grep -v "udev" | tail -n 2 | awk '{print $2,$3,$4,$5,$6}'`" > df.txt
echo "`free -m | head -n 2 | tail -n 1`" > free.txt

Time=`date +"%Y-%m-%d %H:%M"`
User=`whoami`
Disk_total=`cat df.txt | awk '{print $1}' | echo $[$(tr '\n' '+')0]`
Disk_use=`cat df.txt | awk '{print $2}' | echo $[$(tr '\n' '+')0]`
Disk_useper=`echo "scale=1;${Disk_use}*100/${Disk_total}" | bc`
CPU_temperature=`sensors | grep "CPU" | awk '{print $2}'`
MEM_total=`cat free.txt | awk '{print $2}'`
MEM_use=`cat free.txt | awk '{print $3}'`
MEM_useper=`echo "scale=1;${MEM_use}*100/${MEM_total}" | bc`

if [[ ${Disk_useper}<80 ]]; then
    Disk_alarm="normal"
elif [[ ${Disk_useper}<90 ]]; then
    Disk_alarm="note"
else
    Disk_alarm="warning"
    echo "$Time $User Disk $Disk_alarm Disk usage $Disk_useper" >> /var/log/warning.log
    echo "$Time $User Proc $Disk_alarm danger Proc "`ps | awk '{print $}'`""
fi 

if [[ ${CPU_temperature}<50 ]]; then 
    CPU_alarm="normal"
elif [[ ${CPU_temperature}<70 ]]; then
    CPU_alarm="note"
else 
    CPU_alarm="warning"
    echo "$Time $User CPU $CPU_alarm CPU temperature $CPU_temperature" >> /var/log/warning.log
fi

if [[ ${MEM_useper}<70 ]]; then
    MEM_alarm="normal"
elif [[ ${MEM_useper}<80 ]]; then
    MEM_alarm="note"
else 
    MEM_alarm="warning"
    echo "$Time $User MEM $MEM_alarm MEM usage $MEM_useper" >> /var/log/warning.log
fi
echo "bash" >> /var/log/warning.log