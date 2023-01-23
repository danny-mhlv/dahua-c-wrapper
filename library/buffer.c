#include "buffer.h"

void init_buff(buffer* buff, size_t size) {
    buff->data = malloc(size * sizeof(byte));
    buff->size = size;
    buff->pos = 0;
}

void* append_buff(buffer* buff, void* src, size_t size) {
    memcpy(buff + buff->pos, src, size);
    if (malloc_usable_size(buff->data) == buff->size + size) {
        buff->pos += size;
        buff->size += size;
    }

    return buff;
}