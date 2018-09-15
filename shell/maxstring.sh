#!/bin/bash

read -p "please input path:" root_dir

function getdir(){
    for element in `ls $1`
    do
        dir_or_file=$1"/"$element
        if [[ -d $dir_or_file ]]
        then
            getdir $dir_or_file
        else
            echo $dir_or_file
            get_str_length $dir_or_file
        fi
    done
}

maxlen=0
maxstr=""
path=""

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
