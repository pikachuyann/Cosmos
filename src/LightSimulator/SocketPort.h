//
//  SocketPort.h
//  Cosmos
//
//  Created by Alexandru Mereacre on 26/02/2015.
//
//

#ifndef __Cosmos__SocketPort__
#define __Cosmos__SocketPort__

#include <sys/socket.h> // Needed for the socket functions
#include <netdb.h>      // Needed for the socket functions
#include <arpa/inet.h>
#include <netinet/in.h>

#include <errno.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/param.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/poll.h>
#include <signal.h>
#include <assert.h>
#include <pthread.h>

#include "Print.h"

#define PORT_NUMBER "27777"

bool CreateSocket(int *socketHandle, struct addrinfo *hostInfoList);
void CloseSocket(int *socketHandle, int *socketListenHandle, struct addrinfo *hostInfoList);

#endif /* defined(__Cosmos__SocketPort__) */
