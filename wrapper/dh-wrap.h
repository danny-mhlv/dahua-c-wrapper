#ifndef DH_WRAP_H
#define DH_WRAP_H

#include "structs.h"
#include "funcs.h"

#ifdef __cplusplus
extern "C" {
#endif

// Initialization
int DH_SDK_Init(disconnect_cb_t cb_disconnect, long user_param); // #TODO Change long to pointer
void DH_SDK_Cleanup();

// Login and Connection
long DH_Login(struct login_info* in);
int DH_Logout(long login_id);

// Device interaction
int DH_SetDeviceMode(long login_id, e_device_mode mode, void* value);

/**
 *
 * @param login_id Login ID of an active connection
 * @param channel_id
 * @param recfile_type
 * @param start
 * @param end
 * @param sfile_path
 * @param cb_download_pos
 * @param pos_user_param
 * @param cb_download_data
 * @param data_user_param
 * @return Download handle
 */
long DH_DownloadByTime(long login_id, int channel_id, int recfile_type,
                       struct timestamp* start, struct timestamp* end, char* sfile_path,
                       download_pos_cb_t cb_download_pos, long pos_user_param,
                       download_data_cb_t cb_download_data, long data_user_param);

int DH_StopDownload(long handle);

unsigned int DH_GetLastError();

#ifdef __cplusplus
}
#endif

#endif //DH_WRAP_H
