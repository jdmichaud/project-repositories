#!/bin/sh

if [ $# -ne 1 ]; then
  echo "usage: $0 <ip address>"
  exit 127
fi

echo "This will replace your file system and kernel. It will erase everything!"
echo "Now, you have to save all your data in /"
echo "proceed? (y/N)"
read yn
case $yn in
    y)
    ;;
    *) exit 0
    ;;
esac


rootfs=gumstix-basic-image-gumstix-custom-verdex.jffs2
rm -fr $rootfs
scp -P 443 jedi@$1:/home/jedi/projects/gumstix/gumstix-oe/tmp/deploy/glibc/images/gumstix-custom-verdex/$rootfs .

/etc/init.d/boa stop
/etc/init.d/bonjour stop
/etc/init.d/cron stop
 
ln -s /bin/busybox /tmp/mount

/tmp/mount -o remount,ro /
if [ $? -ne 0 ]; then 
  echo "mount readonly failed"
  exit 127                                                   
fi                                                           

test -x ./flash_eraseall
if [ $? -ne 0 ]; then
  echo "./flash_eraseall does not exist or is not executable"
  exit 127
fi

test -x ./flashcp     
if [ $? -ne 0 ]; then         
  echo "./flashcp does not exist or is not executable"
  exit 127                    
fi

test -r $rootfs
if [ $? -ne 0 ]; then         
  echo "$rootfs does not exist"
  exit 127                    
fi                            

echo "Continue? Ctrl-C to stop now"
read a                                                       


./flash_eraseall -j /dev/mtd1
./flashcp -v $rootfs /dev/mtd1

echo "power cycle now."
