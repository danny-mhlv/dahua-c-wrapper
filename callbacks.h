#ifndef FUNCS_H
#define FUNCS_H

#include "data-structures/structs.h"

#ifdef __cplusplus
extern "C" {
#endif

// Callback type definitions

/**
 * @dahua_name
 */
typedef void(disconnect_cb_t)(long login_id, char *dvr_ip, long dvr_port, long user_param);

/**
 * @dahua_name fDataCallBack
 */
typedef int(download_data_cb_t)(long handle, unsigned int data_type, unsigned char *buff, unsigned int buff_size,
                                long user_param);

/**
 * @dahua_name fTimeDownLoadPosCallBack
 */
typedef void(download_pos_cb_t)(long handle, unsigned int total_size, unsigned int download_size, int index,
                                struct record_info file_info, long user_param);

/**
 * @dahua_name
 */
typedef void(video_stream_cb_t)(long handle, unsigned int data_type, unsigned char* buff,
                                unsigned int buff_size, long data, long user_param);

// Default callback functions declarations
// Note: "[N/U]" flag indicates that callback definition
// does not use marked parameters

/**
 * Default download position callback
 * @callback_type download_pos_cb_t
 * @param handle - download handle [N/U]
 * @param total_size - total size of file [N/U]
 * @param download_size - size of acquired chunk
 * @param index - ? [N/U]
 * @param file_info - file info [N/U]
 * @param isLoading - flag that indicates active download process
 */
void default_cb_download_pos(long handle, unsigned int total_size, unsigned int download_size, int index,
                             struct record_info file_info, long isLoading);

/**
 * Default download data callback
 * @callback_type download_data_cb_t
 * @param handle - download handle [N/U]
 * @param data_type - data type
 * @param buff - actual received data
 * @param buff_size - size of received data
 * @param file_path - full path to save file at (char*)
 * @return
 */
int default_cb_download_data(long handle, unsigned int data_type, unsigned char *buff, unsigned int buff_size,
                             long file_path);

#ifdef __cplusplus
}
#endif

#endif // FUNCS_H
