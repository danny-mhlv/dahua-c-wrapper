#ifndef CAMWRAPPER_FUNCS_H
#define CAMWRAPPER_FUNCS_H

#include "data-structures/structs.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void(disconnect_cb_t)(long login_id, char *dvr_ip, long dvr_port, long user_param);

typedef int(download_data_cb_t)(long handle, unsigned int data_type, unsigned char *buff, unsigned int buff_size,
                                long user_param);

typedef void(download_pos_cb_t)(long handle, unsigned int total_size, unsigned int download_size, int index,
                                struct recfile_info file_info, long user_param);

typedef void(video_stream_cb_t)(long handle, unsigned int data_type, unsigned char* buff,
                                unsigned int buff_size, long data, long user_param);

#ifdef __cplusplus
}
#endif

#endif //CAMWRAPPER_FUNCS_H
