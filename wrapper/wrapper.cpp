#include "wrapper.h"
#include <cstring>
#include <dahua/dhnetsdk.h>
#include <iostream>

// Callbacks
void default_download_pos(long handle,
                          unsigned int total_sz,
                          unsigned int download_sz,
                          int index,
                          NET_RECORDFILE_INFO file_info,
                          long loading) {
    std::cout << "Progress: " << download_sz << " Kb out of " << total_sz << " Kb\n";
    if (download_sz == -1) {
        *((bool*)loading) = false;
    }
}

int default_download_buff(long handle,
                          unsigned int data_type,
                          unsigned char* buff,
                          unsigned int buff_sz,
                          long data_buff) {
    if (buff != NULL && buff_sz > 0) {
        switch (data_type) {
            case 0:
                append_buff((w_buffer_t*)data_buff, buff, buff_sz);
                printf("Buff appended by %d bytes", buff_sz);
                break;
                //...    // #TODO cover other types of streams
        }
    }

    return false;
}

NET_TIME* datetime_to_nettime(w_datetime_t* dt) {
    auto nt = new NET_TIME;

    nt->dwYear = dt->year;
    nt->dwMonth = dt->month;
    nt->dwDay = dt->day;
    nt->dwHour = dt->hour;
    nt->dwMinute = dt->minute;
    nt->dwSecond = dt->sec;
    return nt;
}

NET_IN_LOGIN_WITH_HIGHLEVEL_SECURITY* info_to_netinfo(w_login_info_t* info) {
    auto in = new NET_IN_LOGIN_WITH_HIGHLEVEL_SECURITY;
    in->dwSize = sizeof(*in);
    in->nPort = info->port;
    std::strncpy(in->szIP, info->ip, sizeof(in->szIP));
    std::strncpy(in->szUserName, info->user, sizeof(in->szUserName));
    std::strncpy(in->szPassword, info->pass, sizeof(in->szPassword));

    return in;
}

bool DH_Init(void* disconnect_callback, void* cb_param) {
    return CLIENT_Init(reinterpret_cast<fDisConnect>(disconnect_callback), reinterpret_cast<long>(cb_param));
}

void DH_Cleanup() {
    CLIENT_Cleanup();
}

// LoginWithHighLevelSecurity
long DH_Login(w_login_info_t* info) {
    auto out = new NET_OUT_LOGIN_WITH_HIGHLEVEL_SECURITY;
    out->dwSize = sizeof(*out);

    auto in = info_to_netinfo(info);
    long id = CLIENT_LoginWithHighLevelSecurity(in, out);
    delete out; delete in;

    return id;
}

//long DH_Login(void* in, void* out) {
//    return CLIENT_LoginWithHighLevelSecurity(reinterpret_cast<NET_IN_LOGIN_WITH_HIGHLEVEL_SECURITY*>(in),
//                                             reinterpret_cast<NET_OUT_LOGIN_WITH_HIGHLEVEL_SECURITY*>(out));
//}

bool DH_Logout(long login_id) {
    return CLIENT_Logout(login_id);
}

long DH_Download(long login_id, int channel_id, int file_type,
                 w_datetime_t* start, w_datetime_t* end, char* file_name,
                 e_download_cb_type cb_type,
                 void* get_data_callback, void* get_data_param,
                 void* get_pos_callback, void* get_pos_param) {
    switch (cb_type) {
        case BOTH_DEFAULT:
            return CLIENT_DownloadByTimeEx(login_id, channel_id, file_type,
                                           datetime_to_nettime(start), datetime_to_nettime(end),
                                           file_name,
                                           default_download_pos,
                                           (long)get_pos_param,
                                           default_download_buff,
                                           (long)get_data_param);
    }

    return 0;
}

bool DH_StopDownload(long handle) {
    return CLIENT_StopDownload(handle);
}

bool DH_SetDeviceMode(long login_id, e_device_mode mode, void* value) {
    return CLIENT_SetDeviceMode(login_id, (EM_USEDEV_MODE)mode, value);
}

unsigned int DH_GetLastError() {
    return CLIENT_GetLastError();
}
