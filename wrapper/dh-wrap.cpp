#include <dahua/dhnetsdk.h>
#include <cstring>
#include "dh-wrap.h"

// Initialization
int DH_SDK_Init(disconnect_cb_t cb_disconnect, long user_param) {
    return CLIENT_Init((fDisConnect)cb_disconnect, user_param);
}

void DH_SDK_Cleanup() {
    CLIENT_Cleanup();
}

// Login and Connection
// #TODO test if works with 'auto' and other C++ features
long DH_Login(struct login_info* info) {
    NET_OUT_LOGIN_WITH_HIGHLEVEL_SECURITY out;
    memset(&out, 0, sizeof(out));
    out.dwSize = sizeof(out);

    NET_IN_LOGIN_WITH_HIGHLEVEL_SECURITY in;
    memset(&in, 0, sizeof(in));

    in.dwSize = sizeof(in);
    in.nPort = info->port;
    std::strcpy(in.szIP, info->ip);
    std::strcpy(in.szUserName, info->username);
    std::strcpy(in.szPassword, info->password);

    return CLIENT_LoginWithHighLevelSecurity(&in, &out);
}
int DH_Logout(long login_id) {
    return CLIENT_Logout(login_id);
}

// Device interaction
int DH_SetDeviceMode(long login_id, e_device_mode mode, void* value) {
    return CLIENT_SetDeviceMode(login_id, (EM_USEDEV_MODE)mode, value);
}

long DH_DownloadByTime(long login_id, int channel_id, int recfile_type,
                       struct timestamp* start, struct timestamp* end, char* sfile_path,
                       download_pos_cb_t cb_download_pos, long pos_user_param,
                       download_data_cb_t cb_download_data, long data_user_param) {
    return CLIENT_DownloadByTimeEx(login_id, channel_id, recfile_type,
                                   (NET_TIME*)start, (NET_TIME*)end, sfile_path,
                                   (fTimeDownLoadPosCallBack)cb_download_pos, pos_user_param,
                                   (fDataCallBack)cb_download_data, data_user_param);
}

int DH_StopDownload(long handle) {
    return CLIENT_StopDownload(handle);
}

unsigned int DH_GetLastError() {
    return CLIENT_GetLastError();
}