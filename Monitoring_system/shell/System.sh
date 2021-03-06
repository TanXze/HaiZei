#!/bin/bash

echo "`df -m | grep -v "tmpfs" | grep -v "Filesystem" | grep -v "loop" | grep -v "udev" | tail -n 2 | awk '{print $2,$3,$4,$5,$6}'`" > ~/HaiZei/Monitoring_system/shell/txtfile/df.txt
echo "`free -m | head -n 2 | tail -n 1`" > ~/HaiZei/Monitoring_system/shell/txtfile/free.txt

TIME=`date +"%Y-%m-%d__%H:%M"`
HOSTNAME=`hostname`
OS=`uname -o`
KERNEL=`uname -v`
RUNTIME=`uptime -p`
LOADAVERAGE=`uptime | awk '{for(i=NF-2;i<=NF;i++)printf("%s",$i)}'`
DISK_TOTAL=`cat ~/HaiZei/Monitoring_system/shell/txtfile/df.txt | awk '{print $1}' | echo $[$(tr '\n' '+')0]`
DISK_USE=`cat ~/HaiZei/Monitoring_system/shell/txtfile/df.txt | awk '{print $2}' | echo $[$(tr '\n' '+')0]`
DISK_USEPER=`echo "scale=1;${DISK_USE}*100/${DISK_TOTAL}" | bc`
MEM_TOTAL=`cat ~/HaiZei/Monitoring_system/shell/txtfile/free.txt | awk '{print $2}'`
MEM_USE=`cat ~/HaiZei/Monitoring_system/shell/txtfile/free.txt | awk '{print $3}'`
MEM_USEPER=`echo "scale=1;${MEM_USE}*100/${MEM_TOTAL}" | bc`
#CPU_TEMPERATURE=`sensors | grep "CPU" | awk '{print $2}'`
CPU_TEMPERATURE=`cat /sys/class/thermal/thermal_zone0/temp`

if [[ ${DISK_USEPER}<80 ]]; then
    DISK_ALARM="normal"
elif [[ ${DISK_USEPER}<90 ]]; then
    DISK_ALARM="note"
else
    DISK_ALARM="warning"
fi

if [[ ${CPU_TEMPERATURE}<50 ]]; then
    CPU_ALARM="normal"
elif [[ ${CPU_TEMPERATURE}<70 ]]; then
    CPU_ALARM="note"
else
    CPU_ALARM="warning"
fi

if [[ ${MEM_USEPER}<70 ]]; then
    MEM_ALARM="normal"
elif [[ ${MEM_USEPER}<80 ]]; then
    MEM_ALARM="note"
else
    MEM_ALARM="warning"
fi

echo "$TIME $HOSTNAME $OS [$KERNEL] [$RUNTIME] [$LOADAVERAGE] ${DISK_TOTAL}M ${DISK_USEPER}% ${MEM_TOTAL}M ${MEM_USEPER}% $CPU_TEMPERATURE $DISK_ALARM $MEM_ALARM $CPU_ALARM" >> ~/HaiZei/Monitoring_system/shell/logfile/System.log
