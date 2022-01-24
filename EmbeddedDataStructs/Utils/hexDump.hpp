//
//  hexDump.hpp
//  EmbeddedDataStructs
//
//  Created by Aravind Sridhar on 1/23/22.
//

#ifndef hexDump_hpp
#define hexDump_hpp

#include <stdio.h>
#include <cstdlib>

void
hexdump(const void *buf,
        size_t bufLen,
        const char *header = nullptr);

#endif /* hexDump_hpp */
