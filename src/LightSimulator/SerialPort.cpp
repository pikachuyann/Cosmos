//
//  SerialPort.cpp
//  Cosmos
//
//  Created by Alexandru Mereacre on 12/02/2015.
//
//

#include "SerialPort.h"

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