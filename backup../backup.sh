#!/bin/bash

source .back.rc

TIME_NOW=`date +"%Y-%m-%d %H:%M"`
TIME_FILE=`date +"%Y_%m_%d_%H_%M"`


if [[ ! -d $dest_dir ]]; then
    echo "\033[31m $TIME_NOW [ERROR] The Dest dir  $dest_dir not exists \033[0m" >> $log
    return
fi

echo "$TIME_NOW backup started!" >> $log

for i in `echo $back_dir | tr ":" "\n"`; do
    if [[ ! -d $i ]]; then
        echo "\033[31m $TIME_NOW backup [ERROR] The dir $i not exist \033[0m" >> $log
    fi
    echo "$i started" >> $log
    target=`echo $i | cut -d "/" -f 2- | tr "/" "_"`
    target=${target}_${TIME_FILE}.tar.gz
    tar -czPf ${dest_dir}/${target} $i
    if [[ $? -eq 0 ]]; then
        size=`du -h ${dest_dir}/${target}`
        echo -e "$TIME_NOW \033[32m backup \033[0m $i $target +$size" >> $log
    else
        echo -e "\033[31m $TIME_NOW [ERROR] Something .... \033[0m " >> $log
    fi
done

Del_list=`find $dest_dir -name "*.tar.gz" -mmin +1`

for i in $Del_list; do
    size=`du -h $i`
    rm -f $i
    echo -e "$TIME_NOW \033[32m delete \033[0m $i -$size" >> $log
done
