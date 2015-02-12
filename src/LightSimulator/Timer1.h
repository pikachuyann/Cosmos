//
//  Timer1.h
//  Cosmos
//
//  Created by Benoît Barbot on 11/02/2015.
//
//

#ifndef __Cosmos__Timer1__
#define __Cosmos__Timer1__

#ifdef __cplusplus
extern "C"{
#endif


void initTimer1();
unsigned long millis1();
void sleepMillis(unsigned long k);


#ifdef __cplusplus
} // extern "C"
#endif


#endif /* defined(__Cosmos__Timer1__) */
