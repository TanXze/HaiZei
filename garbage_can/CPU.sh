#!/bin/bash

TIME=`date +"%Y-%m-%d__%H:%M"`
LOAD=`uptime | awk '{for(i=NF-2;i<=NF;i++)printf("%s",$i)}'`

