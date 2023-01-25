#ifndef CWRAP_WRAPPER_H
#define CWRAP_WRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include "wstructs.h"

// Wrapped functions
bool DH_Init(void* disconnect_callback, void* cb_param);
void DH_Cleanup();
long DH_Login(w_login_info_t* info); // LoginWithHighLevelSecurity
//long DH_Login(void* in, void* out);
bool DH_Logout(long login_id);
long DH_Download(long login_id, int channel_id, int file_type,
                 w_datetime_t* start, w_datetime_t* end, char* file_name,
                 e_download_cb_type cb_type,
                 void* get_data_callback, void* get_data_param,
                 void* get_pos_callback, void* get_pos_param);
bool DH_StopDownload(long handle);
unsigned int DH_GetLastError();
bool DH_SetDeviceMode(long login_id, e_device_mode mode, void* value);

#ifdef __cplusplus
}
#endif

#endif //CWRAP_WRAPPER_H
