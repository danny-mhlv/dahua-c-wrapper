#include <dahua/dhnetsdk.h>
#include <dahua/dhconfigsdk.h>
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

long DH_Login(struct login_info* info) {
    auto* in = new NET_IN_LOGIN_WITH_HIGHLEVEL_SECURITY();
    in->dwSize = sizeof(*in);
    in->nPort = info->port;
    std::strcpy(in->szIP, info->ip);
    std::strcpy(in->szUserName, info->username);
    std::strcpy(in->szPassword, info->password);

    auto* out = new NET_OUT_LOGIN_WITH_HIGHLEVEL_SECURITY();
    out->dwSize = sizeof(*out);

    return CLIENT_LoginWithHighLevelSecurity(in, out);
}

int DH_Logout(long login_id) {
    return CLIENT_Logout(login_id);
}

// Device interaction

int DH_SetDeviceMode(long login_id, use_device_mode mode, void* value) {
    return CLIENT_SetDeviceMode(login_id, (EM_USEDEV_MODE)mode, value);
}

int DH_StopDownload(long download_handle) {
    return CLIENT_StopDownload(download_handle);
}

unsigned int DH_GetLastError() {
    return CLIENT_GetLastError();
}

dh_getcam_out* DH_GetCameras(long login_id, int max_cameras) {
    auto* in = new dh_getcam_in;
    in->size = sizeof(dh_getcam_in);

    auto* out = new dh_getcam_out;
    out->size = sizeof(dh_getcam_out);

    out->maxCameras = max_cameras;
    dh_camera_info arr[max_cameras];
    std::memset(arr, 0, sizeof(dh_camera_info)*max_cameras);
    out->cameras = arr;

    for (int i = 0; i < out->maxCameras; i++) {
        out->cameras[i].size = sizeof(dh_camera_info);
        out->cameras[i].remoteDevInfo.size = sizeof(remote_device);

        out->cameras[i].remoteDevInfo.pstuVideoInputs = new video_inputs();
        out->cameras[i].remoteDevInfo.pstuVideoInputs->size = sizeof(video_inputs);
    }

    if(CLIENT_MatrixGetCameras(login_id, (DH_IN_MATRIX_GET_CAMERAS*)in, (DH_OUT_MATRIX_GET_CAMERAS*)out)) {
        if (!CLIENT_GetLastError()) {
            return out;
        }
    }

    return nullptr;
}

int DH_GetDevConfig(long login_id, unsigned int command, int channel, void* outBuff,
                    unsigned int outBuffSize) {
    unsigned int bytesReturned = 0;
    if(CLIENT_GetDevConfig(login_id, command, channel, outBuff, outBuffSize, &bytesReturned, 5000)) {
        return (int)bytesReturned;
    }

    unsigned long x = sizeof(DHDEV_DECODER_URL_CFG);
    return 0;
}

int DH_GetConfigJSON(long login_id, char* command, int channel, char* outBuff,
                     unsigned int outBuffSize) {
    int error = 0;
    if(CLIENT_GetNewDevConfig(login_id, command, channel, outBuff, outBuffSize, &error, 5000)) {
        return 1;
    }

    return 0;
}

int DH_ParseConfigJSON(char* command, char* inBuff, void* outBuffer, unsigned int outBuffSize) {
    unsigned int bytesReturned = 0;
    if (CLIENT_ParseData(command, inBuff, outBuffer, outBuffSize, &bytesReturned)) {
        return 1;
    }

    return 0;
}


int DH_QueryDevState(long login_id, int command, void* outBuff, int outBuffSize) {
    int bytesReturned = 0;
    if(CLIENT_QueryDevState(login_id, command, (char*)outBuff, outBuffSize, &bytesReturned, 5000)) {
        return bytesReturned;
    }

    return 0;
}

int DH_DownloadByTime(long login_id, int channel_id, enum query_record_type type, struct time_stamp *from,
                       struct time_stamp *to, char *save_path) {
    int streamType = 0;
    bool loading = true;

    DH_SetDeviceMode(login_id, MODE_RECORD_STREAM_TYPE, &streamType);
    long handle = CLIENT_DownloadByTimeEx(login_id, channel_id, (EM_QUERY_RECORD_TYPE)type,
                            (NET_TIME*)from, (NET_TIME*)to, nullptr,
                            (fTimeDownLoadPosCallBack)default_cb_download_pos, (long)&loading,
                            (fDataCallBack) default_cb_download_data, (long)save_path);

    if (handle) {
        while (loading) {}
        DH_StopDownload(handle);
    }

    if (DH_GetLastError() != 0) return 0;

    return 1;
}

void DH_SetEventListener(event_listen_cb_t callback, long user_param) {
    CLIENT_SetDVRMessCallBackEx2((fMessCallBackEx2)callback, user_param);
}

int DH_StartEventListen(long login_id) {
    return CLIENT_StartListenEx(login_id);
}

int DH_StopEventListen(long login_id) {
    return CLIENT_StopListen(login_id);

}