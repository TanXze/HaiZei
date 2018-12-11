#!/bin/bash

TIME=`date +"%Y-%m-%d %H:%M"`
echo "`free -m | head -n 2 | tail -n 1 | awk '{print $2" "$3}'`" > free.log
TOTAL=`cat free.log | awk '{print $1}'`
USE=`cat free.log | awk '{print $2}'`
SURPLUS=$[${TOTAL}-${USE}]
DATE=`echo "scale=1;${USE}*100/${TOTAL}" | bc`
D=1
DYNAMIC=`echo "scale=1;0.3*$D+0.7*${DATE}" | bc`

echo "$TIME  ${TOTAL}M  ${SURPLUS}M  ${DATE}%  ${DYNAMIC}%" >> ./logfile/Mem.log
