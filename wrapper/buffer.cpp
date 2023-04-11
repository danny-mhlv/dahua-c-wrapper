#include "buffer.h"
#include <cstring>

void init_buff(w_buffer_t* buff, size_t size) {
//    buff->data = (byte*)calloc(1, size * sizeof(byte));
    buff->data = new byte[size];
    buff->size = size;
    buff->pos = 0;
}

void* append_buff(w_buffer_t* buff, void* src, size_t size) {
    std::memcpy(buff->data + buff->pos, src, size);
    buff->pos += size;
    return buff;
}