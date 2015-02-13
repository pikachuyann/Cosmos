/*******************************************************************************
 *                                                                             *
 * Cosmos:(C)oncept et (O)utils (S)tatistique pour les (Mo)deles               *
 * (S)tochastiques                                                             *
 *                                                                             *
 * Copyright (C) 2009-2012 LSV & LACL                                          *
 * Authors: Paolo Ballarini Benoît Barbot & Hilal Djafri                       *
 * Website: http://www.lsv.ens-cachan.fr/Software/cosmos                       *
 *                                                                             *
 * This program is free software; you can redistribute it and/or modify        *
 * it under the terms of the GNU General Public License as published by        *
 * the Free Software Foundation; either version 3 of the License, or           *
 * (at your option) any later version.                                         *
 *                                                                             *
 * This program is distributed in the hope that it will be useful,             *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               *
 * GNU General Public License for more details.                                *
 *                                                                             *
 * You should have received a copy of the GNU General Public License along     *
 * with this program; if not, write to the Free Software Foundation, Inc.,     *
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.                 *
 * file clientsim.cpp created by Benoit Barbot.                                *
 *******************************************************************************
 */
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <errno.h>
#include <paths.h>
#include <assert.h>
#include <pthread.h>
#include <curses.h>
#include <time.h>
#include <termios.h>

#include "SimLight.hpp"
#include "SerialPort.h"

SimulatorLight mySim;
struct ThreadSerialInfo gThreadInfo;

static void *SerialReadThread(void *pArgs)
{
    struct ThreadSerialInfo *threadInfo = (struct ThreadSerialInfo*)pArgs;
    
    ProcessSerial(threadInfo);
    return NULL;
}

/**
 * main function it read the options given as arguments and initialyse
 * the simulator.
 * Then it start a while loop which compute a batch of trajectory
 * and output the result.
 * The loop stop only when the programme receive end_of_file on
 * his standart input
 */

int main(int nargs, char** argv)
{
    char serialBuf[SERIAL_BUF_SIZE];
    int             ftHandle[MAX_DEVICES];
    int             iDeviceID = 0;
    struct termios  oldTio;
    
    pthread_t threadID;

    
    if (nargs!=4) {
        print("Error: Not enough arguments\n");
        return 1;
    }
    
    // Hardcode the serial communication for PC client
    mySim.verbose= atoi(argv[2]);
    
    // The third parameter for the app is the port name
    if((ftHandle[iDeviceID] = open(argv[3], O_RDWR | O_NOCTTY | O_NONBLOCK))==-1) {
        print("Error: Could not connect to "); print(argv[3]); print("\n");
        return 1;
    } else {
        print("Opened device "); print(argv[3]); print("\n");
        
        SetDefaultPortSettings(&ftHandle[iDeviceID], &oldTio);
        
        gThreadInfo.endThread = 1;
        gThreadInfo.nBytesRead = 0;
        gThreadInfo.portHandle = ftHandle[iDeviceID];
        
        // Create the thread
        if(pthread_create(&threadID, NULL, &SerialReadThread, &gThreadInfo)) {
            print("Error: Couldn't create the thread\n");
            
            ClosePortDevice(&ftHandle[iDeviceID], &oldTio, argv[3]);
            return 1;
        }
        
        //simulate a batch of trajectory
        mySim.SimulateSinglePath();
    }

    // End the thread
    gThreadInfo.endThread = 0;
    pthread_join(threadID, NULL);
    
    ClosePortDevice(&ftHandle[iDeviceID], &oldTio, argv[3]);
    
    return (0);
}

REAL_TYPE getPr(TR_PL_ID t){
    return (REAL_TYPE)mySim.N.GetPriority(t);
}

void ShiftArray(int offset, char *buf, int bufsize)
{
    
}

void SWrite(char header, char data, char end)
{
    char Buf[3] = {header, data, end};
    WriteToPort(&gThreadInfo.portHandle, 3, &Buf[0]);
}

char SReceive(void)
{
    char retVal = 0;
    
    if(gThreadInfo.nBytesRead>0) {
        retVal = gThreadInfo.bytesRead[0];
        ShiftArray(1, &gThreadInfo.bytesRead[0], SERIAL_BUF_SIZE);
    }
    
    return retVal;
}

int SReceive2(void)
{
    int retVal = 0;
    
    if(gThreadInfo.nBytesRead>1) {
        retVal = gThreadInfo.bytesRead[1] << 8;
        retVal = retVal | gThreadInfo.bytesRead[0];
        ShiftArray(2, &gThreadInfo.bytesRead[0], SERIAL_BUF_SIZE);
    }

    return retVal;
}

int SReceive4(void)
{
    int retVal = 0, tmp = 0;
    
    if(gThreadInfo.nBytesRead>1) {
        retVal = gThreadInfo.bytesRead[3] << 32;
        retVal = retVal | (gThreadInfo.bytesRead[2] << 16);
        retVal = retVal | (gThreadInfo.bytesRead[1] << 8);
        retVal = retVal | gThreadInfo.bytesRead[0];
        ShiftArray(4, &gThreadInfo.bytesRead[0], SERIAL_BUF_SIZE);
    }
    
    return retVal;
}

bool InDataAvailable(){
    return gThreadInfo.nBytesRead>0;
}

// fake real time
void wait(REAL_TYPE t){
    if(t<=0)return;
    mySim.curr_time += t;
}

REAL_TYPE cRealTime(){
    return mySim.curr_time;
}
