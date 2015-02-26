//
//  SocketPort.cpp
//  Cosmos
//
//  Created by Alexandru Mereacre on 26/02/2015.
//
//

#include "SocketPort.h"

bool CreateSocket(int *socketHandle, struct addrinfo *hostInfoList)
{
    struct addrinfo host_info;       // The struct that getaddrinfo() fills up with data.
    
    // Set up the server
    memset(&host_info, 0, sizeof host_info);
    
    host_info.ai_family = AF_UNSPEC;     // IP version not specified. Can be both.
    host_info.ai_socktype = SOCK_STREAM; // Use SOCK_STREAM for TCP or SOCK_DGRAM for UDP.
    host_info.ai_flags = AI_PASSIVE;     // IP Wildcard
    
    // Now fill up the linked list of host_info structs with localhost address information.
    int sockStatus = getaddrinfo(NULL, PORT_NUMBER, &host_info, &hostInfoList);
    
    // getaddrinfo returns 0 on succes, or some other value when an error occured.
    // (translated into human readable text by the gai_gai_strerror function).
    if (sockStatus != 0) {
        print("Error: getaddrinfo\n");
        return 0;
    }
    
    print("Creating a server socket\n");
    
    *socketHandle = socket(hostInfoList->ai_family, hostInfoList->ai_socktype,
                             hostInfoList->ai_protocol);
    if (*socketHandle == -1) {
        print("Error: socket error\n");
        return 0;
    }
    
    // we use to make the setsockopt() function to make sure the port is not in use
    // by a previous execution of our code. (see man page for more information)
    int someYes = 1;
    if(setsockopt(*socketHandle, SOL_SOCKET, SO_REUSEADDR, &someYes, sizeof(someYes))==-1) {
        print("Reuse port Error\n");
        return 0;
    }
    
    sockStatus = bind(*socketHandle, hostInfoList->ai_addr, hostInfoList->ai_addrlen);
    if (sockStatus == -1) {
        print("Error: socket bind\n");
        return 0;
    }
    
    print("Listen()ing for Ev connections\n");
    sockStatus =  listen(*socketHandle, 5);
    
    if (sockStatus == -1) {
        printf("Error: listen error\n");
        return 1;
    }

    return 1;
}

void CloseSocket(int *socketHandle, int *socketListenHandle, struct addrinfo *hostInfoList)
{
    freeaddrinfo(hostInfoList);
    close(*socketHandle);
    close(*socketListenHandle);
    
    print("Socket closed\n");
}

