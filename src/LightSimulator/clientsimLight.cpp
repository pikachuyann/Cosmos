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
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <paths.h>
#include <termios.h>
#include <sysexits.h>
#include <sys/ioctl.h>
#include <sys/param.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/poll.h>
#include <signal.h>
#include <assert.h>
#include <pthread.h>
#include <curses.h>
#include <time.h>

#include "SimLight.hpp"
#include "Print.h"

#define MAX_DEVICES		5

int             gftHandle[MAX_DEVICES];
char            gcBufLD[MAX_DEVICES][64];
char            gEndThread = 1;
int             giDeviceID = 0;
struct termios  gOldTio;

pthread_t gThreadID;


SimulatorLight mySim;


void ClosePortDevice(void)
{
    /* Cleanup */
    tcdrain(gftHandle[giDeviceID]);
    tcsetattr(gftHandle[giDeviceID],TCSANOW,&gOldTio);
    close(gftHandle[giDeviceID]);
    
    print("Closed device ");
    print(gcBufLD[giDeviceID]);
    print("\n");
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
    char *dSerialNumber;
    
    if (nargs!=4) {
        print("Error: Not enough arguments\n");
        return 1;
    }
    
    // Hardcode the serial communication for PC client
    mySim.verbose= atoi(argv[2]);
    
    // The third parameter for the app is the port name
    dSerialNumber = argv[3];
    
    if((gftHandle[giDeviceID] = open(argv[3], O_RDWR | O_NOCTTY | O_NONBLOCK))==-1) {
        print("Error: Could not connect to ");
        print(argv[3]);
        print("\n");
        return 1;
    }
    
    mySim.SimulateSinglePath(); //simulate a batch of trajectory
    
    ClosePortDevice();
    return (0);
}


REAL_TYPE getPr(TR_PL_ID t){
    return (REAL_TYPE)mySim.N.GetPriority(t);
}

void SWrite(char header, char data, char end)
{
    
}

char SReceive(void)
{
    return 0;
}

int SReceive2(void)
{
    return 0;
}

int SReceive4(void)
{
    return 0;
}

bool InDataAvailable(){
    return false;
    //TO COMPLETE
}

// fake real time
void wait(REAL_TYPE t){
    if(t<=0)return;
    mySim.curr_time += t;
}

REAL_TYPE cRealTime(){
    return mySim.curr_time;
}
