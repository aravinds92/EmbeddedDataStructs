//
//  lifo.hpp
//  EmbeddedDataStructs
//
//  Created by Aravind Sridhar on 1/23/22.
//

#ifndef lifo_hpp
#define lifo_hpp

#include <stdio.h>

class LIFO {
    uint8_t* buffer;
    int length;
    int pointer;
    bool isLIFOFull();
    bool isLIFOEmpty();
    
    
public:
    LIFO(uint8_t* buffer, int length)
    {
        this->buffer = buffer;
        this->length = length;
        pointer = 0;
        memset(buffer, 0, length);
    }
    
    ~LIFO()
    {
        buffer = NULL;
        length = 0;
        pointer = 0;
    }

    bool pushByte(uint8_t data);
    int pushData(uint8_t* data, int dataLength);
    uint8_t popByte();
    int popData(uint8_t* destination, int lengthToPop);
};


#endif /* lifo_hpp */
