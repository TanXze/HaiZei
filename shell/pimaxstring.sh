#!/bin/bash

#filter() {
#    a=(rmvb png img)
#    suffix=`echo $1 | awk -F. '{print $NF}'`
#    echo ${a[*]} | grep "$suffix" >/dev/null 
#    if [[ $? -eq 0 ]]; then
#        return 1;
#    fi
#    return 0;
#}

function getdir() {
    for file in `ls $1`; do
        dir_or_file=$1"/"$file
        if [[ -d $dir_or_file ]]; then
            getdir $dir_or_file
        else
            file $dir_or_file | grep "exec" >/dev/null 
            if [[ $? -eq 0 ]]; then
                get_str_length $dir_or_file
            fi
        fi 
    done
}

maxlen=(0 0 0)
maxstr=("" "" "")
path=("" "" "")
number=("" "" "")

function get_str_length() {
    for line in `cat $1`; do
        if echo "$line" | grep -q '^[a-zA-Z0-9]\+$'; then
            len=${#line}
            if [[ ${len} -gt ${maxlen[1]} ]]; then
                maxlen[3]=${maxlen[2]}
                maxstr[3]=${maxstr[2]}
                path[3]=${path[2]}
                number[3]=${number[2]}
                maxlen[2]=${maxlen[1]}
                maxstr[2]=${maxstr[1]}
                path[2]=${path[1]}
                number[2]=${number[1]}
                maxlen[1]=${len}
                maxstr[1]=${line}
                path[1]=$1
                number[1]=`grep -n ${maxstr[1]} ${path[1]} | awk -F: '{print $1}'`
            elif [[ ${len} -gt ${maxlen[2]} ]]; then
                maxlen[3]=${maxlen[2]}
                maxstr[3]=${maxstr[2]}
                path[3]=${path[2]}
                number[3]=${number[2]}
                maxlen[2]=${len}
                maxstr[2]=${line}
                path[2]=$1
                number[2]=`grep -n ${maxstr[2]} ${path[2]} | awk -F: '{print $1}'`
            elif [[ ${len} -gt ${maxlen[3]} ]]; then
                maxlen[3]=${len}
                maxstr[3]=${line}
                path[3]=$1
                number[3]=`grep -n ${maxstr[3]} ${path[3]} | awk -F: '{print $1}'`
            fi
        fi
    done
}

getdir `pwd`

hostname=`hostname`

echo "${maxlen[1]}:${maxstr[1]}<tab>${hostname}:${path[1]}<tab>Line:${number[1]}" #> maxstr${hostname}.log
echo "${maxlen[2]}:${maxstr[2]}<tab>${hostname}:${path[2]}<tab>Line:${number[2]}" #> maxstr${hostname}.log
echo "${maxlen[3]}:${maxstr[3]}<tab>${hostname}:${path[3]}<tab>Line:${number[3]}" #> maxstr${hostname}.log

#`scp maxstr${hostname}.log tanxiaoze@192.168.1.178:~/HaiZei/shell/`
