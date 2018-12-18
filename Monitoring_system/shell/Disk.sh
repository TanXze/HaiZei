#!/bin/bash

echo "`df -m | grep -v "文件" | grep -v "tmpfs" | grep -v "Filesystem" | awk '{print $2,$3,$4,$5,$6}'`" >  ~/HaiZei/Monitoring_system/shell/txtfile/df.txt
TIME=`date +"%Y-%m-%d %H:%M:%S"`
DISK_TOTAL=`cat ~/HaiZei/Monitoring_system/shell/txtfile/df.txt | awk '{print $1}' | echo $[$(tr '\n' '+')0]`
DISK_SURPLUS=`cat ~/HaiZei/Monitoring_system/shell/txtfile/df.txt | awk '{print $3}' | echo $[$(tr '\n' '+')0]`
DISK_USE=`cat ~/HaiZei/Monitoring_system/shell/txtfile/df.txt | awk '{print $2}' | echo $[$(tr '\n' '+')0]`
OCCUPANCY=`echo "scale=1;${DISK_USE}*100/${DISK_TOTAL}" | bc`
  
echo "$TIME 0 disk $DISK_TOTAL $DISK_SURPLUS $OCCUPANCY%" >> ~/HaiZei/Monitoring_system/shell/logfile/Disk.log
echo "$TIME 1 `cat ~/HaiZei/Monitoring_system/shell/txtfile/df.txt | head -n 1 | awk '{print $5,$1,$3,$4}'`" >> ~/HaiZei/Monitoring_system/shell/logfile/Disk.log
echo "$TIME 1 `cat ~/HaiZei/Monitoring_system/shell/txtfile/df.txt | tail -n 1 | awk '{print $5,$1,$3,$4}'`" >> ~/HaiZei/Monitoring_system/shell/logfile/Disk.log
