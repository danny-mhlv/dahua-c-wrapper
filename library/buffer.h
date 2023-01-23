#ifndef CAMWRAPPER_BUFFER_H
#define CAMWRAPPER_BUFFER_H

#include <stdlib.h>
#include <memory.h>
#include <malloc.h>

// Typedefs
typedef unsigned char byte;

typedef struct buffer {
    byte* data;     // Data
    size_t pos;     // Current position
    size_t size;    // Size of buff
} buffer;

void init_buff(buffer* buff, size_t size);
void* append_buff(buffer* buff, void* src, size_t size);

#endif //CAMWRAPPER_BUFFER_H
