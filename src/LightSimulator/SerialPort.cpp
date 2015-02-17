//
//  SerialPort.cpp
//  Cosmos
//
//  Created by Alexandru Mereacre on 12/02/2015.
//
//

#include <string.h>

#include "SerialPort.h"


void ClosePortDevice(int *portHandle, struct termios  *tio, char *seriaPortName)
{
    /* Cleanup */
    tcdrain(*portHandle);
    tcsetattr(*portHandle,TCSANOW,tio);
    close(*portHandle);
    
    print("Closed device ");
    print(seriaPortName);
    print("\n");
}

void SetDefaultPortSettings(int *portHandle, struct termios  *tio)
{
    struct termios newtio;
    
    ioctl(*portHandle, TIOCEXCL);
    fcntl(*portHandle, F_SETFL, 0);
    
    /* Set the baud rate and other serial port parameters */
    tcgetattr(*portHandle,tio); /* save current port settings */
    memset (&newtio, 0, sizeof newtio);
    
    newtio.c_iflag=0;
    newtio.c_oflag=0;
    newtio.c_cflag=CS8 | CREAD | CLOCAL;           /* 8n1, see termios.h for more information */
    newtio.c_lflag=0;
    newtio.c_cc[VMIN]=1;
    newtio.c_cc[VTIME]=0;
    
    cfsetospeed(&newtio,B115200);
    cfsetispeed(&newtio,B115200);
    
    tcflush(*portHandle, TCIOFLUSH);
    tcsetattr(*portHandle,TCSANOW,&newtio);

}

bool WriteToPort(int *portHandle, int nbytes, char *buf)
{
    if(write(*portHandle, buf, nbytes)==-1)
        return 0;
    
    return 1;
}

void ProcessSerial(struct ThreadSerialInfo *sInfo)
{

}
