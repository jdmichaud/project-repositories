#!/bin/bash

install_package()
{
    # arg 1: installer file
    # arg 2: package name
    cat <<EOF >> $1

ipkg install $2
if [ \$? -ne 0 ]; then
   echo "failed to install package $2, bailing out"
   exit 127
fi
EOF
}

install_file()
{
    # arg 1: installer file
    # arg 2: filename
    # arg 3: install location
    source=`echo $2 | awk -F '/' '{ print $NF}'`
    cat <<EOF >> $1

cp $source $3
if [ \$? -ne 0 ]; then
   echo "failed to install file $source in $3, bailing out"
   exit 127
fi
EOF
}

ex_command()
{
    # arg 1: installer file
    # arg 2: command
    __installer_file__=$1
    shift
    cat <<EOF >> $__installer_file__

$@
if [ \$? -ne 0 ]; then
   echo "\'$@\' failed, bailing out"
   exit 127
fi
EOF
}

check()
{
   if [ $? -ne 0 ]; then
      echo "a command failed, bailing out..."
      exit 127
   fi
}


if [ $# -ne 2 ]; then
    echo 1>&2 Usage: $0 "<gumstix_oe directory> <list of files>"
    exit 127
fi

package=gumstix-package-`date +%d-%m-%Y_%Hh%Mm%Ss`
mkdir "/tmp/"$package

tmp_file=`mktemp`
grep -E '^[^#]' $2 > $tmp_file

file_length=`wc -l $tmp_file | awk '{print $1}'`
file_length=`expr $file_length + 0`
while [ $file_length -ne 0 ];
do
    line=`head -$file_length $tmp_file | tail -1`

    if [ `echo $line | awk '{ print $1 }'` == "package" ]; then
        package_name=`echo $line | awk '{ print $2 }'`
        echo 'copying '$package_name' to /tmp/'$package'/ ...'
        cp $1/$package_name "/tmp/"$package"/"
        check
    fi

    if [ `echo $line | awk '{ print $1 }'` == "file" ]; then
        package_name=`echo $line | awk '{ print $2 }'`
        echo 'copying '$package_name' to /tmp/'$package'/ ...'
        cp $1/$package_name "/tmp/"$package"/"
        check
    fi

    file_length=`expr $file_length - 1`
done

echo 'generating installer ...'
installer_file='/tmp/'$package'/installer.sh'
touch $installer_file
chmod +x $installer_file
cat <<EOF > $installer_file
#!/bin/sh

check()
{
   if [ \$? -ne 0 ]; then
      echo "a command failed, bailing out..."
      exit 127
   fi
}

if [ \$# -ne 1 ]; then
    echo 1>&2 Usage: \$0 "<package directory>"
    exit 127
fi

EOF

file_length=`wc -l $tmp_file | awk '{print $1}'`
file_length=`expr $file_length + 0`
count=`expr 1`
while [ $count -le $file_length ];
do
    line=`head -$count $tmp_file | tail -1`

    if [ `echo $line | awk '{ print $1 }'` == "package" ]; then
        package_name=`echo $line | awk '{ print $2 }' | awk -F '/' '{ print $NF}'`
        install_package $installer_file $package_name
    fi

    if [ `echo $line | awk '{ print $1 }'` == "file" ]; then
        filename__=`echo $line | awk '{ print $2 }'`
        install_location=`echo $line | awk '{ print $3 }'`
        install_file $installer_file $filename__ $install_location
    fi

    if [ `echo $line | awk '{ print $1 }'` == "command" ]; then
        command_=`echo $line | awk '{ tail=$0; for (i=1;i<2;i++) sub($i,"",tail); sub(/ */,"",tail); print tail}'` 
        ex_command $installer_file $command_
    fi
       
    count=`expr $count + 1`
done



echo 'taring package ...'
pushd .
cd /tmp/$package
echo 'write crc ...'
md5sum * > crc_check
cd /tmp
tar zcvf $package.tar.gz $package
popd
mv /tmp/$package.tar.gz .

