#!/bin/bash

TIME=`date +"%Y-%m-%d %H:%M"`
USER=`cat /etc/passwd | awk -F: '$3>=500 {print $1}'| wc -l`
ALLUSER=$[${USER}+1]
ACTUSER=`last | grep -v "^$" | grep -v "reboot" | grep -v "wtmp" | awk '{print $1}' | uniq -c | head -n 3 | awk '{print $2}' | tr "\n" "," | sed 's/.$//'`
ROOTUSER=`cat /etc/passwd | tr ":" " " | awk '{print $1}' | xargs -l id | grep "sudo" | awk '{print $1}' | cut -d "(" -f2 | sed 's/.$//'`
NOWUSER=`w -h | awk '{printf("%s_%s_%s",$1,$3,$2)}'`

echo "$TIME $ALLUSER [$ACTUSER] [$ROOTUSER] [$NOWUSER]" > /home/tanxiaoze/HaiZei/Monitoring_system/shell/logfile/User.log
