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
#include <signal.h>
#include <poll.h>
#include <limits.h>
#include <iostream>
#include <list>


#include "SerialPort.h"
#include "SocketPort.h"

SimulatorLight  mySim; 

int             gftHandle[MAX_DEVICES] = {-1, -1, -1, -1, -1};
int             giDeviceID = 0;
bool            gDataAvailable = 0;

struct pollfd   gWaitDescriptors[2];
/**
 * main function it read the options given as arguments and initialyse
 * the simulator.
 * Then it start a while loop which compute a batch of trajectory
 * and output the result.
 * The loop stop only when the programme receive end_of_file on
 * his standart input
 */

struct timeval gStartTime;
std::list<TR_PL_ID> gTranList;

unsigned int BytesToInt(unsigned char iBytes[4])
{
    unsigned int ri = 0;
    
    ri = (unsigned int)(iBytes[3]);
    ri = (ri << 8) | (unsigned int)(iBytes[2]);
    ri = (ri << 8) | (unsigned int)(iBytes[1]);
    ri = (ri << 8) | (unsigned int)(iBytes[0]);
    
    return ri;
}

// Main thread for socket read
void *SocketReadThread(void *pArgs)
{
    struct ThreadSerialInfo *sInfo = (struct ThreadSerialInfo *)pArgs;
    
    MainSocketRead(sInfo);
    return NULL;
}

int main(int nargs, char** argv)
{
    struct  termios             oldTio;
    struct  addrinfo            *hostInfoList = nullptr; // Pointer to the to the linked list of host_info's.
    struct  ThreadSerialInfo    sInfo = {-1, -1, -1, 1, SIM_NONE, &mySim, 0, {0, 0, 0, 0}};
    auto                        serial = ARDUINO_SP_NAME;
    pthread_t                   threadID;
    
    gettimeofday(&gStartTime, NULL);
    
    // Hardcode the serial communication for PC client
    mySim.verbose= atoi(argv[2]);
    
    if(!CreateSocket(&sInfo.gSocketHandle, hostInfoList))
        return 1;
    
    // Create the the thread
    if(pthread_create(&threadID, NULL, &SocketReadThread, &sInfo)) {
        print("Error: Couldn't create the thread\n");
        
        CloseSocket(&sInfo.gSocketHandle, &sInfo.gListenSocketHandle, hostInfoList);
        return 1;
    }
    
    while(sInfo.gSocketHandle==-1)
        usleep(WAIT_TIME_INF_LOOP);
    
    print("Waiting for python script app to connect...\n");
    
    while(sInfo.gListenSocketHandle==-1)
        usleep(WAIT_TIME_INF_LOOP);
    
    print("Python script connected\n");

    // The third parameter for the app is the port name
    if((gftHandle[giDeviceID] = open(serial, O_RDWR | O_NOCTTY | O_NONBLOCK | O_NDELAY))==-1) {
        print("Error: Could not connect to "); print(argv[3]); print("\n");
        CloseSocket(&sInfo.gSocketHandle, &sInfo.gListenSocketHandle, hostInfoList);
        return 1;
    } else {
        print("Opened device "); print(serial); print("\n");
        
        SetDefaultPortSettings(&gftHandle[giDeviceID], &oldTio);
        
        sInfo.serialPortHandle = gftHandle[giDeviceID];
    
        gWaitDescriptors[0].fd = gftHandle[giDeviceID];
        gWaitDescriptors[0].events = POLLIN;
        gWaitDescriptors[1].fd = sInfo.gListenSocketHandle;
        gWaitDescriptors[1].events = POLLIN;
        
        TR_PL_ID *bufIDs = NULL;
        
        while(sInfo.gCommands!=SIM_END) {
            unsigned char Buf = 0, sParBuf[6];
            int idx = 0;
            ssize_t dwBytes;
            unsigned int nBufIDs = 0, parValue = 0;
            int pollRc;
            size_t bytesRead = 0;
            
            //simulate a batch of trajectory
            if(sInfo.gCommands != SIM_NONE)
                mySim.SimulateSinglePath();
            
            //usleep(WAIT_TIME_INF_LOOP);
            
            switch (sInfo.gCommands)
            {
                case SIM_START:
                    gettimeofday(&gStartTime, NULL);
                    
                    gTranList.clear();
                    mySim.StartSimulation();
                    
                    Buf = 'W';
                    WriteToPort(&gftHandle[giDeviceID], 1, &Buf);
                    
                    break;
                    
                case SIM_END:
                    
                    Buf = 'S';
                    WriteToPort(&gftHandle[giDeviceID], 1, &Buf);
                    
                    break;
                    
                case SIM_STOP:
                    sInfo.gCommands = SIM_NONE;
                    
                    Buf = 'S';
                    WriteToPort(&gftHandle[giDeviceID], 1, &Buf);
                    
                    break;
                    
                case SIM_GET_ID:
                    sInfo.gCommands = SIM_NONE;
                    
                    nBufIDs = gTranList.size();
                    
                    if(bufIDs!=NULL) delete [] bufIDs;
                    
                    bufIDs = new TR_PL_ID[nBufIDs];
                    
                    print("Number of transition IDs: "); print((float)(nBufIDs)); print("\n");
                    
                    dwBytes = send(sInfo.gListenSocketHandle, (void*)&nBufIDs, sizeof(nBufIDs), 0);
                    
                    for (std::list<TR_PL_ID>::iterator it=gTranList.begin(); it != gTranList.end(); ++it, ++idx)
                        bufIDs[idx] = *it;
                    
                    dwBytes = send(sInfo.gListenSocketHandle, (void*)bufIDs, (size_t)(nBufIDs)*sizeof(TR_PL_ID), 0);
                    
                    if(!dwBytes)
                        print("No IDs or write socket error\n");
                    else {
                        print("Number of bytes sent: "); print((float)(dwBytes)); print("\n");
                    }

                    break;
                    
                case SIM_SET_CPAR:
                    sInfo.gCommands = SIM_NONE;
                    
                    parValue = BytesToInt(sInfo.gParBuf);
                    print("Setting Client parameter ID: "); print((float)(sInfo.gParId)); print(" Value: "); print((float)parValue); print("\n");
                    
                    SetParameters(sInfo.gParId, (unsigned long)(parValue));
                    
                    Buf = SIM_READY;
                    dwBytes = send(sInfo.gListenSocketHandle, (void*)&Buf, 1, 0);
                    
                    break;
                    
                case SIM_SET_PPAR:
                    sInfo.gCommands = SIM_NONE;
                    
                    parValue = BytesToInt(sInfo.gParBuf);
                    print("Setting Arduino parameter ID: "); print((float)(sInfo.gParId)); print(" Value: "); print((float)parValue); print("\n");
                    
                    sParBuf[0] = 'D';
                    sParBuf[1] = sInfo.gParId;
                    memcpy((void*)&sParBuf[2], (const void*)&sInfo.gParBuf[0], 4);
                    
                    WriteToPort(&gftHandle[giDeviceID], 6, &sParBuf[0]);
                    
                    pollRc = poll(&gWaitDescriptors[0], 2, -1);
                    
                    if (pollRc < 0) {
                        print("Error: setting the poll\n");
                    } else if(pollRc > 0) {
                        
                        if( gWaitDescriptors[0].revents & POLLIN ) {
                            bytesRead = read(gftHandle[giDeviceID], &Buf, (int)1);
                            
                            if (Buf!=SIM_READY) {
                                print("Wrong Arduino reply\n");
                                Buf=SIM_READY;
                                dwBytes = send(sInfo.gListenSocketHandle, (void*)&Buf, 1, 0);
                                break;
                            }
                            
                            dwBytes = send(sInfo.gListenSocketHandle, (void*)&Buf, 1, 0);
                        }
                        else if(gWaitDescriptors[0].revents & POLLHUP || gWaitDescriptors[0].revents & POLLERR)
                            print("Error: poll read gftHandle\n");
                    }
                    break;
                    
                case SIM_NONE:
                    break;
                    
                default:
                    sInfo.gCommands = SIM_NONE;
            }
            
        }
        
        if(bufIDs!=NULL)
            delete [] bufIDs;
    }
    
    // End the thread
    sInfo.gEndThread = 0;

    // wait for the thread to exit
    pthread_join(threadID, NULL);

    CloseSocket(&sInfo.gSocketHandle, &sInfo.gListenSocketHandle, hostInfoList);
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
    unsigned char retVal = 0;
    size_t bytesRead = 0;
    if(gDataAvailable) {
        bytesRead = read(gftHandle[giDeviceID], &retVal, (int)1);
        if(retVal==0x33 || retVal==0x34)
            std::cerr << "<<<<<<< Pace -> Heart: "<< mySim.curr_time << " ["<< retVal << "]"<< std::endl;
        else if(retVal==0x35)
            std::cerr << "<<<<<<< Syn: "<< mySim.curr_time << std::endl;
        else
            std::cerr << "<<<<<<< Data: "<< mySim.curr_time << " ["<< retVal << "]"<< std::endl;;
        
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
    if (t<=0) return;
    
    gDataAvailable = 0;

    int pollRc = poll(&gWaitDescriptors[0], 2, (int)(t));
    
    if (pollRc < 0) {
        print("Error: setting the poll\n");
    } else if(pollRc > 0) {
        
        if( gWaitDescriptors[0].revents & POLLIN )
            gDataAvailable = 1;
        else if(gWaitDescriptors[0].revents & POLLHUP || gWaitDescriptors[0].revents & POLLERR)
            print("Error: poll read gftHandle\n");

        if( gWaitDescriptors[1].revents & POLLIN )
            print("Received SocketListen in wait\n");
        else if(gWaitDescriptors[1].revents & POLLHUP || gWaitDescriptors[1].revents & POLLERR)
            print("Error: poll read SocketListen\n");
    }
    
    //mySim.curr_time += t;
}

REAL_TYPE cRealTime(){
    struct timeval time;
    gettimeofday(&time, NULL);
    float timef = (time.tv_sec - gStartTime.tv_sec)*1000 + (time.tv_usec - gStartTime.tv_usec)/1000;
    return timef;
}

void AddTransitionID(TR_PL_ID tranID)
{
    gTranList.push_back(tranID);
}