#ifndef DH_WRAP_H
#define DH_WRAP_H

#include "data-structures/structs.h"
#include "constants/config-commands.h"
#include "enums.h"
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
int DH_SetDeviceMode(long login_id, enum use_device_mode mode, void* value);

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
                       struct time_stamp* start, struct time_stamp* end, char* sfile_path,
                       download_pos_cb_t cb_download_pos, long pos_user_param,
                       download_data_cb_t cb_download_data, long data_user_param);

int DH_StopDownload(long handle);

unsigned int DH_GetLastError();

// DVR functionality
struct dh_getcam_out* DH_GetCameras(long login_id, int max_cameras);

/**
 *
 * @param login_id - Login ID
 * @param command - <a href="config-constants.h">Config Constants Reference</a>
 * @param channel
 * @param outBuff
 * @param outBuffSize
 * @return
 */
int DH_GetDevConfig(long login_id, unsigned int command, int channel, void* outBuff,
                    unsigned int outBuffSize);

//int DH_GetNewDevConfig(long login_id, char* szCommand, int channel,
//                       char* outBuffer, unsigned int outBufferSize, int *error);

int DH_QueryDevState(long login_id, int command, void* outBuff, int outBuffSize);

int DH_GetConfigJSON(long login_id, char* command, int channel, char* outBuff, unsigned int outBuffSize);

int DH_ParseConfigJSON(char* command, char* inBuff, void* outBuffer, unsigned int outBuffSize);

/**
 * FOR WS Messaging about new recordings (test, not sure if this shit works)
 */
/////@brief order record  change port,user malloc memory of pInParam and pOutParam
//CLIENT_NET_API LLONG CALL_METHOD CLIENT_AttachRecordUpdater(LLONG lLoginID, const NET_IN_RECORDUPDATER_DATA* pInParam, NET_OUT_RECORDUPDATER_DATA* pOutParam, int nWaitTime);
//
/////@brief stoporder record  change port
//CLIENT_NET_API BOOL CALL_METHOD CLIENT_DetachRecordUpdater(LLONG lAttachHandle);

#ifdef __cplusplus
}
#endif

#endif //DH_WRAP_H
