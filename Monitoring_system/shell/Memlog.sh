#!/bin/bash

TIME=`date +"%Y-%m-%d %H:%M"`
echo "`free -m | head -n 2 | tail -n 1 | awk '{print $2" "$3}'`" > /home/tanxiaoze/HaiZei/Monitoring_system/shell/txtfile/free.log
TOTAL=`cat /home/tanxiaoze/HaiZei/Monitoring_system/shell/txtfile/free.log | awk '{print $1}'`
USE=`cat /home/tanxiaoze/HaiZei/Monitoring_system/shell/txtfile/free.log | awk '{print $2}'`
SURPLUS=$[${TOTAL}-${USE}]
DATE=`echo "scale=1;${USE}*100/${TOTAL}" | bc`
D=1
DYNAMIC=`echo "scale=1;0.3*$D+0.7*${DATE}" | bc`

echo "$TIME  ${TOTAL}M  ${SURPLUS}M  ${DATE}%  ${DYNAMIC}%" >> /home/tanxiaoze/HaiZei/Monitoring_system/shell/logfile/Mem.log
