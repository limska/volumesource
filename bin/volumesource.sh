#!/bin/bash

BINDIR=`dirname $0`
BINDIR=`cd $BINDIR && pwd`
TOPDIR=`dirname $BINDIR`
VS=$TOPDIR/build/volumesource
LOG=$HOME/volumesource.log

export LD_LIBRARY_PATH=/home/sava/src/volumesource/boost/1.67.0/lib:$LD_LIBRARY_PATH

while true;
do
  echo "$VS block10.stl  >> $LOG 2>&1"
  $VS block10.stl  >> $LOG 2>&1
done

