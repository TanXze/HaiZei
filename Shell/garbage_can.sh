#!/bin/bash

if [[ ! -d ~/garbage_can ]]
then
    mkdir ~/garbage_can
fi

if [[ "$1" == "-r" ]] || [[ "$1" == "-f" ]] || [[ "$1" == "-rf" ]]
then
    for file in "$@"
    do
        if [[ -f "$file" ]] || [[ -d "$file" ]]
        then
            mv "$file" ~/garbage_can/ 
        elif [[ "$1" == "-r" ]] && [[ "$file" != "-r" ]] && [[ "$2" != "-f" ]]
        then
            echo "No such file or directory"
        elif [[ "$1" == "-f" ]] && [[ "$#" -eq 1 ]]
        then
            exit
        fi
    done
elif [[ -f "$@" ]]
then
    mv "$@" ~/garbage_can/ 
else
    echo "Cant delete, is a directory"
fi
