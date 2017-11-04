#!/bin/sh

if test $# -ne 2
then
    "usage: bench conffile ntest"
    exit
fi


defaultEPS=0.01
defaultTL=3
defaultHIDDEN=30

echo "compiling bobTalk ..."
gmake nc

echo "cleaning /tmp/ ..."
rm /tmp/oeuf.tgz
rm /tmp/out
rm /tmp/*.dat

# $1: ligne
# $2: fichier
getID()
{
    line=`head -n $1 $2 | tail -n 1`
    count=1
    char=`echo 0`
    while test $char != "="
    do
      char=`echo $line | cut -nc $count-$(($count))`
      count=$(($count+1))
    done
    currentid=`echo $line | cut -nc 1-$(($count-2))`
}

# $1: ligne
# $2: valeur
# $3: fichier
getValue()
{
    line=`head -n $1 $3 | tail -n 1`
    borneinf=0
    count=1
    char=`echo 0`
    while test $char != "="
    do
      char=`echo $line | cut -nc $count-$(($count))`
      count=$(($count+1))
    done
    
    nvalue=0
    while test $nvalue -ne $2
    do
      borneinf=$count
      char=`echo 0`
      while test $char != "-"
	do
	char=`echo $line | cut -nc $count-$(($count))`
	count=$(($count+1))
	if ! test $char
	then
	    currentvalue=`echo NaN`
	    return
	fi
      done
      nvalue=$(($nvalue+1))
    done
    currentvalue=`echo $line | cut -nc $borneinf-$(($count-2))`
}


i=1
length=`wc -l $1|cut -nc 4-8`
while test $i -le $length
do
  getID $i $1
  echo -e "parameter: $currentid"
  
  n=1
  currentvalue=0

  while test $currentvalue != "NaN"
    do
    getValue $i $n $1
    echo -e "with \033[1;33m$currentvalue \033[1;0m"
    n=$(($n+1))

    if test $currentid = "EPS"
    then
	EPS=$currentvalue
    else
	EPS=$defaultEPS
    fi
    if test $currentid = "TL"
    then
	TL=$currentvalue
    else
	TL=$defaultTL
    fi
    if test $currentid = "HIDDEN"
    then
	HIDDEN=$currentvalue
    else
	HIDDEN=$defaultHIDDEN
    fi
    
    if test $currentvalue != "NaN"
	then
	echo "EPS=$EPS" > conf
	echo "TL=$TL" >> conf
	echo "INPUT=41" >> conf
        echo "HIDDEN=$HIDDEN" >> conf
	echo "OUTPUT=41" >> conf
	
	./allezhop.sh $2
	mv /tmp/nrj.dat /tmp/nrj_$currentid$currentvalue.dat
	mv /tmp/error.dat /tmp/error_$currentid$currentvalue.dat
	rm -fr /tmp/out
	rm -fr /tmp/nrj.dat
	rm -fr /tmp/error.dat
    fi

  done
    i=$(($i+1))
done

echo "the tests are over, zipping results, please wait ..."
tar zcvf /tmp/oeuf_$HOST.tgz /tmp/*.dat
cp /tmp/oeuf_$HOST.tgz ~/