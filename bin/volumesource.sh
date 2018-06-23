#!/bin/bash

BINDIR=`dirname $0`
BINDIR=`cd $BINDIR && pwd`
TOPDIR=`dirname $BINDIR`
VS=$TOPDIR/build/volumesource
LOG=$TOPDIR/volumesource.log

while true;
do
  echo "$VS block10.stl  >> $LOG 2>&1"
  $VS block10.stl  >> $LOG 2>&1
done
