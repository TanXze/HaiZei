#!/bin/bash

TIME=`date +"%Y-%m-%d %H:%M"`
TOTAL=`free -m | head -n 2 | tail -n 1 | awk '{print $2}'`
USE=`free -m | head -n 2 | tail -n 1 | awk '{print $3}'`
SURPLUS=$[${TOTAL}-${USE}]
DATE=`echo "scale=1;${USE}*100/${TOTAL}" | bc`
DYNAMIC=`echo "scale=1;0.3*$1+0.7*${DATE}" | bc`

echo "$TIME  ${TOTAL}M  ${SURPLUS}M  ${DATE}%  ${DYNAMIC}%"
