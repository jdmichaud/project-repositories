#!/bin/sh

if test $# -eq 0
then
    echo "usage: filtre.sh input output"
fi

count=1
length=`wc -l $1|cut -nc 1-8`

echo -n > $2error.dat
echo -n > $2nrj.dat

cat $1 | cut -nc 1-10 >> $2error.dat
cat $1 | cut -nc 24-37 >> $2tmp
tail -n `echo $length-3|bc` $2tmp > $2nrj.dat

#while test $count -le $length
#do
    #line=`head -n $count $1 | tail -n 1`
    #first=`echo $line | cut -nc 1-10`
    #second=`echo $line | cut -nc 11-20`
    #third=`echo $line | cut -nc 24-37`
    #count=`echo $count+1|bc`
    
    #echo -n "*"
    #echo "$count $first" >> $2error.dat
    #echo "$count $third" >> $2nrj.dat

#    test $count -le $length
#done
echo
