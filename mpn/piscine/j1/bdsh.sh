#! /bin/sh

#fonction put
fctn_put ()
{

    #le parametre existe il ?
    grep $2 $1
    echo $?
    if test $? -ne 0 ; then
        #oui
        echo $2 >> $1
        echo "put effectue"
	return
    else
        #non
        echo "doublon ..."
    fi
    return
}

#fonction print
fctn_print ()
{
    cat $1
    echo "print effectue"
    return
}

#fonction find
fctn_find ()
{
    grep $2 $1
    echo "find effectue"
    return
}

#fonction rm
fctn_rm ()
{
    grep -v $2 $1 > temp
    mv temp $1
    echo "rm effectue"
    return
}


#begin
#set -e


#Appel des fonctions demandee

if test $1 = "put" ; then
    if test $# -ne 3 ; then
	echo "usage: <command> <fichier> <parametres>"
	exit 0
    fi
    fctn_put $2 $3
    exit 0
fi

if test $1 = "print" ; then
    if test $# -ne 2 ; then
	echo "usage: <command> <fichier>"
	exit 0
    fi
    fctn_print $2
    exit 0
fi

if test $1 = "find" ; then
    if test $# -ne 3 ; then
	echo "usage: <command> <fichier> <parametres>"
	exit 0
    fi
    fctn_find $2 $3
    exit 0
fi

if test $1 = "rm" ; then
    if test $# -ne 3 ; then
	echo "usage: <command> <fichier> <parametres>"
	exit 0
    fi
    fctn_rm $2 $3
    exit 0
fi

#end

