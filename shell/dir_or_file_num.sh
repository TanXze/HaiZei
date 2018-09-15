#!/bin/bash

filenum=0
dirnum=0

read -p "path:" path

function get_dirnum(){
    for file in `ls -a $1`; do
        dir_or_file=$1"/"$file
        if [[ -d $dir_or_file ]]; then
            if [[ "$file" == "." ]] || [[ "$file" == ".." ]]; then
                continue
            else
                (( dirnum++ ))
                get_dirnum $dir_or_file
            fi
        else
            (( filenum++ ))
        fi 
    done
}

get_dirnum $path
echo filenum:$filenum
echo dirnum:$dirnum

