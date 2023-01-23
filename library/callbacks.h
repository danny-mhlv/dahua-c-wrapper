#ifndef CWRAP_CALLBACKS_H
#define CWRAP_CALLBACKS_H

#include <stdbool.h>
#include <stdio.h>
#include "structs.h"

// Types of callbacks
typedef void(disconnect_cb_t)(long login_id, char *dvr_ip, long dvr_port, long user_param);

typedef int(download_data_cb_t)(long handle, unsigned int data_type, unsigned char *buff, unsigned int buff_size,
                                long user_param);

typedef void(download_pos_cb_t)(long handle, unsigned int total_size, unsigned int download_size, int index,
                                struct recfile_info file_info, long user_param);

// Default callback implementation
void cb_default_download_pos(long handle,
                             unsigned int total_sz,
                             unsigned int download_sz,
                             int index,
                             struct recfile_info recFile_info,
                             long loading);

int cb_default_download_buff(long handle,
                             unsigned int data_type,
                             unsigned char* buff,
                             unsigned int buff_sz,
                             long data_buff);

#endif //CWRAP_CALLBACKS_H
