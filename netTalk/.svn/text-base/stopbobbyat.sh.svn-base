#!/bin/sh

if test $# -eq 0
then
    echo "usage: stopbobbyat.sh n"
    echo "n etant le nombre de mot passe a la moulinette"
fi

count=0
while true
do
    sleep 2
    count=`wc -l /tmp/out | cut -nc 5-8`
    echo -n $count
    echo -n " - "
    if test $count -ge $1
    then 
	exit
    fi
done