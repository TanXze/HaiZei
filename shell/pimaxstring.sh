#!/bin/bash

filter() {
    a=(rmvb png img)
    suffix=`echo $1 | awk -F. '{print $NF}'`
    echo ${a[*]} | grep "$suffix" >/dev/null 
    if [[ $? -eq 0 ]]; then
        return 1;
    fi
    return 0;
}

function getdir() {
    for file in `ls $1`; do
        dir_or_file=$1"/"$file
        if [[ -d $dir_or_file ]]; then
            getdir $dir_or_file
        else
            file $dir_or_file | grep "exec" >/dev/null 
            if [[ $? -eq 1 ]]; then
                filter $dir_or_file
                if [[ $? -eq 0 ]]; then
                    get_str_length $dir_or_file
                fi
            fi
        fi 
    done
}

maxlen=0
maxstr=""
path=""

function get_str_length() {
    for line in `cat $1`; do
        len=${#line}
        if [[ ${len} -gt ${maxlen} ]]; then
            maxlen=${len}
            maxstr=${line}
            path=$1
            number=`grep -n ${maxstr} ${path} | awk '{print $1}' | tr ":" " " | awk '{print $1}'`
        fi
    done
}

getdir `pwd`

hostname=`hostname`

echo "${maxstr}  ${hostname}:${path}  ${number}" > maxstr${hostname}.log

`scp maxstr${hostname}.log tanxiaoze@192.168.1.178:~/HaiZei/shell/`
