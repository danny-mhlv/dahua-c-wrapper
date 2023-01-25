#ifndef CWRAP_BUFFER_H
#define CWRAP_BUFFER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stddef.h"

// Typedefs
typedef unsigned char byte;

typedef struct {
    byte *data;     // Data
    size_t pos;     // Current position
    size_t size;    // Size of buff
} w_buffer_t;

void init_buff(w_buffer_t *buff, size_t size);
void *append_buff(w_buffer_t *buff, void *src, size_t size);

#ifdef __cplusplus
}
#endif

#endif //CWRAP_BUFFER_H
