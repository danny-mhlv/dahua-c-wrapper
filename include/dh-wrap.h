#ifndef DH_WRAP_H
#define DH_WRAP_H

#include "data-structures/structs.h"
#include "constants/config-commands.h"
#include "enums.h"
#include "callbacks.h"

#ifdef __cplusplus
extern "C" {
#endif

// #TODO remove all out-* params and replace it with proper return type

// Initialization
int DH_SDK_Init(disconnect_cb_t cb_disconnect, long user_param); // #TODO Change long to pointer
void DH_SDK_Cleanup();

// Login and Connection
long DH_Login(struct login_info* in);
int DH_Logout(long login_id);

// Device interaction
int DH_SetDeviceMode(long login_id, enum use_device_mode mode, void* value);

int DH_DownloadByTime(long login_id, int channel_id, enum query_record_type type,
                       struct time_stamp* from, struct time_stamp* to, char* save_path);

int DH_StopDownload(long download_handle);

unsigned int DH_GetLastError();

// DVR functionality
struct dh_getcam_out* DH_GetCameras(long login_id, int max_cameras);

int DH_GetDevConfig(long login_id, unsigned int command, int channel, void* outBuff,
                    unsigned int outBuffSize);

int DH_GetConfigJSON(long login_id, char* command, int channel, char* outBuff, unsigned int outBuffSize);

int DH_ParseConfigJSON(char* command, char* inBuff, void* outBuffer, unsigned int outBuffSize);

int DH_QueryDevState(long login_id, int command, void* outBuff, int outBuffSize);

int DH_QueryRecordFiles(long login_id,  struct query_record_file_in* in, query_record_file_out* out, int timeout);

int DH_FindRecordFiles(long login_id, enum file_query_type type, find_file_in* query, find_file_out* resultList, int resultListLength, int timeout);

void DH_SetEventListener(event_listen_cb_t callback, long user_param);

int DH_StartEventListen(long login_id);

int DH_StopEventListen(long login_id);

#ifdef __cplusplus
}
#endif

#endif //DH_WRAP_H
