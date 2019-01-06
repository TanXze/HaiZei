#!/bin/bash

read -p "please input path:" root_dir

function getdir(){
    for element in `ls $1`
    do
        dir_or_file=$1"/"${element}
        if [[ -d $dir_or_file ]]
        then
            getdir $dir_or_file
        else
            file $dir_or_file | grep "exec" >/dev/null 
            if [[ $? -eq 1 ]]; then 
                get_str_length $dir_or_file
            fi
        fi
    done
}

maxlen=0

function get_str_length(){
    for line in `cat $1`
    do
        len=${#line}
        if [[ ${len} -gt ${maxlen} ]]
        then
            maxlen=${len}
            maxstr=${line}
            path=$1
        fi
    done
}

getdir $root_dir

echo ${maxstr}
echo ${maxlen}
echo ${path}
