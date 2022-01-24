//
//  hexDump.cpp
//  EmbeddedDataStructs
//
//  Created by Aravind Sridhar on 1/23/22.
//

#include <iostream>
using namespace std;

#include <assert.h>
#include "hexDump.hpp"


void
hexdump(const void *buf,
        size_t bufLen,
        const char *header)
{
    const uint8_t *ptr = static_cast<const uint8_t *>(buf);
    const uint8_t *start = static_cast<const uint8_t *>(buf);
    
    while (bufLen > 0) {
        uint32_t i;
        
        char line[80];
        char *end = &line[sizeof(line)];
        char *lineptr = line;
        
        lineptr += snprintf(lineptr, end - lineptr, "%08x: ", static_cast<unsigned>(ptr - start));
        assert(lineptr < end);
        
        const uint8_t *tmpptr = ptr;
        for (i = 0; i < std::min(bufLen, size_t(16)); i++) {
            lineptr += snprintf(lineptr, end - lineptr, "%02x ", *tmpptr);
            assert(lineptr < end);
            if (i == 7) {
                lineptr += snprintf(lineptr, end - lineptr, " ");
                assert(lineptr < end);
            }
            tmpptr++;
        }
        for (; i < 16; i++) {
            lineptr += snprintf(lineptr, end - lineptr, "   ");
            assert(lineptr < end);
            if (i == 7) {
                lineptr += snprintf(lineptr, end - lineptr, " ");
                assert(lineptr < end);
            }
        }
        lineptr += snprintf(lineptr, end - lineptr, " | ");
        assert(lineptr < end);
        for (i = 0; i < std::min(bufLen, size_t(16)); i++) {
            char c = *ptr;
            lineptr += snprintf(lineptr, end - lineptr, "%c", (c > 32 && c < 127) ? c : '.');
            assert(lineptr < end);
            if (i == 7) {
                lineptr += snprintf(lineptr, end - lineptr, " ");
                assert(lineptr < end);
            }
            ptr++;
        }
        
        if (header) {
            printf("%s: %s\n", header, line);
        } else {
            printf("%s\n", line);
        }
        
        if (bufLen < 16) break;
        bufLen -= 16;
    }
}
