//
//  lifoTests.cpp
//  EmbeddedDataStructs
//
//  Created by Aravind Sridhar on 1/23/22.
//

#include <iostream>
using namespace std;

#include "assert.h"
#include "lifoTests.hpp"
#include "lifo.hpp"
#include "hexDump.hpp"


void testLIFO()
{
    uint8_t* buffer = new uint8_t[BUFFER_LENGTH];
    LIFO* stack = new LIFO(buffer, BUFFER_LENGTH);
    
    uint8_t buff[] = "1234567";
    
    int ret = stack->pushData(buff, 7);
    cout<<ret<<"\n";
    
    
    uint8_t data[10];
    memset(data, 0, 10);
    ret = stack->popData(data, 10);
    cout<<ret<<"\n";
    
    hexdump(data, 10);
    
    
    stack->pushByte(1);
    stack->pushByte(2);
    stack->pushByte(3);
    stack->pushByte(4);
    stack->pushByte(5);
    
    printf("%02x\n", stack->popByte());
    printf("%02x\n", stack->popByte());
    printf("%02x\n", stack->popByte());
    printf("%02x\n", stack->popByte());
    printf("%02x\n", stack->popByte());
    
}
