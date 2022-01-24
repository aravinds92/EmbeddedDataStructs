//
//  fifo.hpp
//  EmbeddedDataStructs
//
//  Created by Aravind Sridhar on 1/23/22.
//

#ifndef fifo_hpp
#define fifo_hpp

#include <stdio.h>

class FIFO      //Circular buffer
{
    uint8_t* buffer;
    int head;
    int tail;
    int length;     //Length of the buffer

    
public:
    FIFO(uint8_t* buffer, int length)
    {
        this->buffer = buffer;
        this->length = length;
        head = 0;
        tail = 0;
        
        memset(buffer, 0, this->length);
    }
    
    ~FIFO()
    {
        buffer = NULL;
        head = 0;
        tail = 0;
        length = 0;
    }
    
    int getBufferLength();
    int bufferWrite(uint8_t* data, int length);
    int bufferRead(uint8_t* destination, int lengthToRead);
    void bufferPutC(uint8_t data);
    uint8_t bufferGetC();
    int isBufferEmpty();
    
};


#endif /* fifo_hpp */
