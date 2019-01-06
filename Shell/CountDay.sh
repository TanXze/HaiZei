#!/bin/bash

count=0
END=$[$1+$2-1]

for i in `seq $1 $END`; do
    if [[ $[$i%4] -eq 0 && $[$i%100] -ne 0 ]]; then 
        ((count++))
    elif [[ $[$i%400] -eq 0 ]]; then
        ((count++))
    fi
done

normal_years=$[$2-$count]
normal_days=$[$normal_years*365]
run_days=$[$count*366]
all_days=$[$normal_days+$run_days]

echo $all_days
