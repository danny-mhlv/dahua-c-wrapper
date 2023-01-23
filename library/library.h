#ifndef UNTITLED_LIBRARY_H
#define UNTITLED_LIBRARY_H

#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <dahua/dhnetsdk.h>

#include "structs.h"
#include "mt-funcs.h"
#include "callbacks.h"

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
 * @param info
 * @return Non-zero login ID of the established connection on success
 */
long connect(login_info_t* info);

/**
 * Connect to the specific camera using given credentials
 * @param username User name
 * @param password User password
 * @param ip IP address of the camera
 * @param port Port number
 * @return Non-zero login ID of the established connection on success
 */
long connect_param(const char* username, const char* password, const char* ip, unsigned short port);

/**
 * Close the connection
 * @param login_id
 * @return true on success
 */
long disconnect(long login_id);

/**
 * Get and save time-framed video data to buffer
 * @param login_id Login ID of the active connection
 * @param type Video stream type to get
 * @param start Start timestamp
 * @param end End timestamp
 * @param data_buff Buffer to save to
 */
void get_data(long login_id, enum recstream_type type, timestamp_t* start, timestamp_t* end, buffer* data_buff);

/**
 * Get the last occurred error
 * @return error code
 */
unsigned int get_error();

#endif //UNTITLED_LIBRARY_H
