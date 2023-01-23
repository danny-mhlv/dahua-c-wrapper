#ifndef UNTITLED_LIBRARY_H
#define UNTITLED_LIBRARY_H

// Defines
#define DEFAULT_CB

#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include "../wrapper/dh-wrap.h"

#include "buffer.h"
#include "mt-funcs.h"

// Structs
typedef struct dtstamp {
    unsigned int year;
    unsigned int month;
    unsigned int day;
    unsigned int hour;
    unsigned int min;
    unsigned int sec;
} dtstamp;

// Default callbacks
download_pos_cb_t x;
DEFAULT_CB void cb_download_pos(long handle,
                                unsigned int total_sz,
                                unsigned int download_sz,
                                int index, struct recfile_info recFile_info,
                                long loading);

DEFAULT_CB int cb_download_data(long handle,
                                unsigned int data_type,
                                unsigned char* buff,
                                unsigned int buff_sz,
                                long data_buff);

/**
 * Default SDK initializer function
 */
bool SDK_init();

/**
 * SDK cleanup
 */
void SDK_cleanup();

/**
 * Connect to the specific camera using given credentials
 * @param username User name
 * @param password User password
 * @param ip IP address of the camera
 * @param port Port number
 * @return Non-zero login ID of the established connection on success
 */
long connect(struct login_info* info);
long connect_param(const char* username, const char* password, const char* ip, unsigned short port);

long disconnect(long login_id);

/**
 * Get and save time-framed video data to buffer
 * @param login_id Login ID of the active connection
 * @param type Video stream type to get
 * @param start Start timestamp
 * @param end End timestamp
 * @param data_buff Buffer to save to
 */
void get_data(long login_id, enum recstream_type type, dtstamp* start, dtstamp* end, buffer* data_buff);

unsigned int get_error();

#endif //UNTITLED_LIBRARY_H
