#!/bin/sh

while [ 1 == 1 ]
do
    is_running=`ps | grep probe.py | grep -v grep`
    if [ `echo $is_running | wc -c` == 1 ]
    then
        echo "Restart probe" | tee -a /media/cf/probe.log
        /etc/init.d/probe restart
    fi
    sleep 120
done
