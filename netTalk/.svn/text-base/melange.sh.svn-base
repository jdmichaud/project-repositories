#!/bin/sh

if test $# -eq 0
then
    echo "usage: filtre.sh input output taille"
fi

RANDOM=42

count=0
length=`wc -l $1|cut -nc 5-8`
echo -n > $2

if test $3 -gt $length
then
    echo "taille maxi pour la base: $length"
    exit
fi

while test $count -le $3
do
    r=`echo $RANDOM%$length|bc`
    line=`head -n $r $1 | tail -n 1`
    echo $line >> $2
    count=`echo $count+1|bc`
done