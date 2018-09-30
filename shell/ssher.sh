#!/bin/bash
host=`ifconfig | grep -w inet | head -2 | tail -1 | cut -d "." -f 4 |cut -d " "  -f 1`
port=$[8000 + $host]

ps -ef | grep "ssh -Nf -R $port" | grep -v grep  >/dev/null 2>&1
if [[ ! $? -eq 0 ]]; then
	ssh -Nf -R ${port}:127.0.0.1:22 ssher@zentao.haizeix.tech
    if [[ $? -eq 0 ]];then
    	echo "success!"
      else
        echo "failed!"
    fi
fi
