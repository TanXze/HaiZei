#!/bin/bash

echo "`df -m | grep -v "文件" | grep -v "tmpfs" | grep -v "Filesystem" | awk '{print $2,$3,$4,$5,$6}'`" >  df.txt
TIME=`date +"%Y-%m-%d %H:%M:%S"`
DISK_TOTAL=`cat df.txt | awk '{print $1}' | echo $[$(tr '\n' '+')0]`
DISK_SURPLUS=`cat df.txt | awk '{print $3}' | echo $[$(tr '\n' '+')0]`
DISK_USE=`cat df.txt | awk '{print $2}' | echo $[$(tr '\n' '+')0]`
OCCUPANCY=`echo "scale=1;${DISK_USE}*100/${DISK_TOTAL}" | bc`
  
echo "$TIME 0 disk $DISK_TOTAL $DISK_SURPLUS $OCCUPANCY%"
echo "$TIME 1 `cat df.txt | head -n 1 | awk '{print $5,$1,$3,$4}'`"
echo "$TIME 1 `cat df.txt | tail -n 1 | awk '{print $5,$1,$3,$4}'`"
