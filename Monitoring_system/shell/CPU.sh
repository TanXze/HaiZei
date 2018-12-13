#!/bin/bash

TIME=`date +"%Y-%m-%d__%H:%M"`
LOAD=`uptime | awk '{for(i=NF-2;i<=NF;i++)printf("%s",$i)}'`

CPULOG_1=`cat /proc/stat | grep 'cpu ' | head -n 1 | awk '{print $2" "$3" "$4" "$5" "$6" "$7" "$8}'`
IDLE_1=`echo $CPULOG_1 | awk '{print $4}'`
Total_1=`echo $CPULOG_1 | awk '{print $1+$2+$3+$4+$5+$6+$7}'`

sleep 0.5

CPULOG_2=`cat /proc/stat | grep 'cpu ' | head -n 1 | awk '{print $2" "$3" "$4" "$5" "$6" "$7" "$8}'`
IDLE_2=`echo $CPULOG_2 | awk '{print $4}'`
Total_2=`echo $CPULOG_2 | awk '{print $1+$2+$3+$4+$5+$6+$7}'`

IDLE=$[$IDLE_2-$IDLE_1]
Total=$[$Total_2-$Total_1]
CPU_AGE=`echo "scale=1;${IDLE}*100/${Total}" | bc`
CPU_USEAGE=`echo "scale=1;100-${CPU_AGE}" | bc`

TEMPERATURE=`sensors | grep "CPU" | awk '{print $2}'`

if [[ ${TEMPERATURE}<50 ]]; then
    CPU_ALARM="normal"
elif [[ ${TEMPERATURE}<70 ]]; then
    CPU_ALARM="note"
else
    CPU_ALARM="warning"
fi

echo "$TIME [$LOAD] ${CPU_USEAGE}% $TEMPERATURE $CPU_ALARM" >> ./logfile/CPU.log
