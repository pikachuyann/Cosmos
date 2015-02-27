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
#include <iostream>

#include "SimLight.hpp"
#include "SerialPort.h"
#include "SocketPort.h"

SimulatorLight  mySim;
int             gftHandle[MAX_DEVICES];
int             giDeviceID = 0;
bool            gDataAvailable = 0;

int             gSocketHandle = -1;
int             gListenSocketHandle = -1;
pthread_t       gThreadID;

char            gEndThread = 1;

/**
 * main function it read the options given as arguments and initialyse
 * the simulator.
 * Then it start a while loop which compute a batch of trajectory
 * and output the result.
 * The loop stop only when the programme receive end_of_file on
 * his standart input
 */

struct timeval gStartTime;

// Main thread for socket read
void *SerialReadThread(void *pArgs)
{
    struct pollfd   fds;
    int             pollrc;

    print("Socket thread created\n");
    
    fds.fd = gSocketHandle;
    fds.events = POLLIN;
    
    while(gEndThread) {
        pollrc = poll(&fds, 1, -1);
        
        
        // Check if bytes are available in the read queue
        if (pollrc < 0) {
            print("Error: setting the poll\n");
            return NULL;
        }else if(pollrc > 0) {
            if (fds.revents & POLLIN && fds.fd==gSocketHandle) {
                gListenSocketHandle = accept(gSocketHandle, NULL, NULL);
                
                if (gListenSocketHandle < 0) {
                    if (errno != EWOULDBLOCK)
                        print("Error: accept() failed");
                    return NULL;
                }
                
                print("Client socket connected\n");
                
                fds.fd = gListenSocketHandle;
                fds.events = POLLIN;
            } else if (fds.revents & POLLIN && fds.fd==gListenSocketHandle) {
                
                char data[2]={0,0};
                ssize_t rc = recv(fds.fd, (void*)&data[0], 1, 0);
                
                print("Data"); print(&data[0]); print("\n");
                
                if (rc < 0) {
                    if (errno != EWOULDBLOCK)
                        print("Error:  recv() failed\n");
                    return NULL;
                }
                if (rc == 0) {
                    printf("Connection closed\n");
                    return NULL;
                }
                
                if(data[0]=='q') {
                    print("Hit\n");
                    gEndThread = 0;
                    return NULL;
                }
                
            } else if(fds.revents & POLLHUP || fds.revents & POLLERR) {
                printf("Error: socket poll read\n");
                return NULL;
            }
        }
    }
    return NULL;
}

int main(int nargs, char** argv)
{
    struct termios  oldTio;
    struct addrinfo *hostInfoList = nullptr; // Pointer to the to the linked list of host_info's.

    gettimeofday(&gStartTime, NULL);

    auto serial = "arduino";
    
    /*if (nargs==4) {
        serial = argv[3];
        //print("Error: Not enough arguments\n");
        return 1;
    }*/
    
    // Hardcode the serial communication for PC client
    mySim.verbose= atoi(argv[2]);
    
    // The third parameter for the app is the port name
    if((gftHandle[giDeviceID] = open(serial, O_RDWR | O_NOCTTY | O_NONBLOCK | O_NDELAY))==-1) {
        print("Error: Could not connect to "); print(argv[3]); print("\n");
        return 1;
    } else {
        print("Opened device "); print(serial); print("\n");
        SetDefaultPortSettings(&gftHandle[giDeviceID], &oldTio);
        
        if(!CreateSocket(&gSocketHandle, hostInfoList)) {
            ClosePortDevice(&gftHandle[giDeviceID], &oldTio);
            return 1;
        }
        
        // Create the thread
        if(pthread_create(&gThreadID, NULL, &SerialReadThread, NULL)) {
            print("Error: Couldn't create the thread\n");
            
            CloseSocket(&gSocketHandle, &gListenSocketHandle, hostInfoList);
            ClosePortDevice(&gftHandle[giDeviceID], &oldTio);
            
            return 1;
        }
        
        // For testing
        while(gEndThread) {
            sleep(1);
        }
        
        //simulate a batch of trajectory
        //mySim.SimulateSinglePath();
    }
    
    // End the thread
    gEndThread = 0;

    // wait for the thread to exit
    pthread_join(gThreadID, NULL);

    CloseSocket(&gSocketHandle, &gListenSocketHandle, hostInfoList);
    ClosePortDevice(&gftHandle[giDeviceID], &oldTio);
    
    return (0);
}

REAL_TYPE getPr(TR_PL_ID t){
    return (REAL_TYPE)mySim.N.GetPriority(t);
}

void SWrite3(unsigned char header,unsigned char data, unsigned char end)
{
    unsigned char Buf[3] = {header, data, end};
    std::cerr << "Heart -> Pace: "<< mySim.curr_time << " ["<< (int)header << "]["<< (int)data << "]["<< (int)end << "]"<< std::endl;
    WriteToPort(&gftHandle[giDeviceID], 3, &Buf[0]);
}

void SWrite(unsigned char data)
{
    unsigned char Buf[1] = {data};
    std::cerr << "Heart -> Pace: "<< mySim.curr_time << " ["<< data << "]"<< std::endl;
    WriteToPort(&gftHandle[giDeviceID], 1, &Buf[0]);
}

char SReceive(void)
{
    /*if(gDataAvailable) {
        char retVal[101];
        size_t bytesRead = read(gftHandle[giDeviceID], &retVal, (int)100);
        std::cout << retVal;
        std::cout.flush();
    }
    return 0;*/


    unsigned char retVal = 0;
    size_t bytesRead = 0;
    if(gDataAvailable) {
        bytesRead = read(gftHandle[giDeviceID], &retVal, (int)1);
        std::cerr << "<<<<<<< Pace -> Heart: "<< mySim.curr_time << " ["<< retVal << "]"<< std::endl;
        gDataAvailable = 0;
    }
    
    return retVal;
}

unsigned char InDataAvailable(){
    if(gDataAvailable){
        return 1;} else {return 0;
    };
}

// real time
void wait(REAL_TYPE t){
    struct pollfd   fds;
    int pollRc;
    
    if(t<=0)return;
    
    gDataAvailable = 0;

    fds.fd = gftHandle[giDeviceID];
    fds.events = POLLIN;

    pollRc = poll(&fds, 1, (int)(t));
    
    if (pollRc < 0)
        print("Error: setting the poll\n");
    else if(pollRc > 0){
        if( fds.revents & POLLIN ){
            gDataAvailable = 1;
        } else if(fds.revents & POLLHUP || fds.revents & POLLERR)
            printf("Error: poll read\n");
    }
    //mySim.curr_time += t;
}

REAL_TYPE cRealTime(){
    struct timeval time;
    gettimeofday(&time, NULL);
    float timef = (time.tv_sec - gStartTime.tv_sec)*1000 + (time.tv_usec - gStartTime.tv_usec)/1000;
    return timef;
}
