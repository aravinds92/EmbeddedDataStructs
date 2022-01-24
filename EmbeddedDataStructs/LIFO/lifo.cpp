//
//  lifo.cpp
//  EmbeddedDataStructs
//
//  Created by Aravind Sridhar on 1/23/22.
//

#include <iostream>
using namespace std;


#include "lifo.hpp"

bool LIFO::isLIFOFull()
{
    return (pointer == length);
}

bool LIFO::isLIFOEmpty()
{
    return (pointer < 0);
}


bool LIFO::pushByte(uint8_t data)
{
    return (pushData(&data, 1) == 1);
}


int LIFO::pushData(uint8_t *data, int dataLength)
{
    int count = 0;
    for(int i = 0; i<dataLength; i++)
    {
        if(isLIFOFull())
            break;
        buffer[pointer] = data[i];
        pointer++;
        count++;
    }
    
    return count;
}


uint8_t LIFO::popByte()
{
    uint8_t ret;
    
    popData(&ret, 1);
    return ret;
    
}

int LIFO::popData(uint8_t *destination, int lengthToPop)
{
    int count = 0;
    for(int i = 0; i<lengthToPop; i++)
    {
        pointer--;
        if(isLIFOEmpty())
        {
            pointer++;
            break;
        }

        destination[i] = buffer[pointer];
        
        count++;
    }
    
    return count;
}
