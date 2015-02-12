#!/bin/sh

#  Script.sh
#  Cosmos
#
#  Created by Benoît Barbot on 05/02/2015.
#

LPATH=sketchArduino/lib/SimClient
SEDCMD=s/.hpp/.h/g

rm -rf sketchArduino
mkdir -p sketchArduino
cd sketchArduino
ino init
rm -rf src/sketch.ino
cd ..
mkdir -p $LPATH
touch $LPATH/string
sed -e $SEDCMD Event.hpp > $LPATH/Event.h
sed -e $SEDCMD Event.cpp > $LPATH/Event.cpp
sed -e $SEDCMD EventsQueueLight.hpp > $LPATH/EventsQueueLight.h
sed -e $SEDCMD EventsQueueLight.cpp > $LPATH/EventsQueueLight.cpp
sed -e $SEDCMD spnLight.hpp > $LPATH/spnLight.h
sed -e $SEDCMD spn.cpp > $LPATH/spn.cpp
sed -e $SEDCMD SimLight.hpp > $LPATH/SimLight.h
sed -e $SEDCMD SimLight.cpp > $LPATH/SimLight.cpp
sed -e $SEDCMD markingImpl.hpp > $LPATH/markingImpl.h
sed -e $SEDCMD macro.h > $LPATH/macro.h
cp Timer1.h $LPATH/Timer1.h
cp Timer1.c $LPATH/Timer1.c
echo "#include \"spnLight.h\"\n" $LPATH/magic.h
sed -e 's/return \("[^"]*"\);/print(\1);break;/g' -e 's/return std::to_string(v)/print((TR_PL_ID)v);break;/g' -e 's/ string / void /g' -e $SEDCMD magic.hpp >> $LPATH/magic.h

cp sketchArduino.ino sketchArduino/src/sketch.ino
cp -r $LPATH ~/Documents/Arduino/libraries

cd sketchArduino
ino build -m fio

SERIAL=`ls /dev/tty.usbserial-* /dev/ttyUSB*`

ino upload -m fio -p $SERIAL
