//
//  fifoTests.cpp
//  EmbeddedDataStructs
//
//  Created by Aravind Sridhar on 1/23/22.
//

#include <iostream>
using namespace std;

#include "fifo.hpp"
#include "fifoTests.hpp"
#include "hexDump.hpp"

void testFIFO()
{
    uint8_t* buffer = new uint8_t[10];
    FIFO* fifo = new FIFO(buffer, 10);
    
    
    cout<<"Buffer length: "<<fifo->getBufferLength() << "\n";
    cout<<"Buffer status: "<<fifo->isBufferEmpty() << "\n";
    
    uint8_t a[] = "123456789abcde";
    
    
    fifo->bufferWrite(a, 14);
    
    uint8_t b[10];
    fifo->bufferRead(b, 20);
    
    hexdump(b, 10);
    
}
