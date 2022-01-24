//
//  fifo.cpp
//  EmbeddedDataStructs
//
//  Created by Aravind Sridhar on 1/23/22.
//

#include <iostream>
using namespace std;


#include "fifo.hpp"


int FIFO::getBufferLength()
{
    return length;
}


int FIFO::bufferWrite(uint8_t* data, int dataLength)
{
    for(int i = 0; i<dataLength; i++)
    {
        buffer[head] = data[i];
        head++;
        if(head == length)
            head = 0;
    }
    
    return 0;
}

void FIFO::bufferPutC(uint8_t data)
{
    bufferWrite(&data, 1);
}



int FIFO::bufferRead(uint8_t* destination, int lengthToRead)
{
    int count = 0;
    for(int i = 0; i<lengthToRead; i++)
    {
        if(isBufferEmpty())
            return 0;
        
        destination[i] = buffer[tail];
        tail++;
        count++;
        if(tail == length)
            tail = 0;
    }
    return count;
}


uint8_t FIFO::bufferGetC()
{
    uint8_t data;
    bufferRead(&data, 1);
    return data;
}

int FIFO::isBufferEmpty()
{
    return (tail == head);
}
