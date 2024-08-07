#!/bin/bash

if [ $1 ]
then
export DRIVER=$1
else
export DRIVER="driver"
fi

if [ $2 ]
then
export CFG="mudos."$2".cfg"
else
export CFG="mudos.cfg"
fi

echo "driver: "$DRIVER
echo "cfg: "$CFG

# Specify your mud dir here.
MUDHOME="/srv/mud"

# It has been reported that non-US users have problems
# with some .o files because their systems default to
# commas for decimal notation and not periods. The
# following language exports are for the benefit of
# people who run into this problem.

LANG=en_US
LANGUAGE=en_US
LC_ALL=en_US

# Uncomment the following if you're on Solaris 10 with a
# 32 bit compiler and need to get around the 256 FD limit.
# NOTE: It will break things. The correct fix is to  compile 
# with a 64 bit compiler and set ENABLE_M64 in build.FluffOS to 1
#LD_PRELOAD_32=/usr/lib/extendedFILE.so.1
#export LD_PRELOAD_32

export LANG LANGUAGE LC_ALL MUDHOME

umask 007

ulimit -a 
ulimit -n 2048
ulimit -a 

while [ true ]; do

    cat $MUDHOME/lib/log/runtime >> $MUDHOME/lib/log/runtime.boot
    rm $MUDHOME/lib/log/runtime

    if [ $MUDHOME ] && [ -f $MUDHOME/bin/$DRIVER ]  && [ -f $MUDHOME/bin/$CFG ]
        then
        $MUDHOME/bin/$DRIVER $MUDHOME/bin/$CFG 
        else
        if [ -f ./$DRIVER ]  && [ -f ./$CFG ] 
            then
            ./$DRIVER ./$CFG
            else
            break
        fi
    fi

done
