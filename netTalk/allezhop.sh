#!/bin/sh

if test $# -eq 0
then
    echo "usage: allezhop.sh n"
    echo "n etant le nombre de mot passe a la moulinette"
fi

./bobTalk t conf enculeR.csv 20. > /tmp/out &
count=`echo $1+3|bc`
./stopbobbyat.sh $count
paidi=`ps | grep bobTalk | cut -nc 1-6`
kill $paidi
./filtre.sh /tmp/out /tmp/
#gnuplot < gnuplot.command
#gs /tmp/nrj.ps
