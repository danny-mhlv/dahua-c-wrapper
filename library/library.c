#include "library.h"
#include "malloc.h"

bool SDK_init() {
    return DH_Init((void*)NULL, 0);
}

void SDK_cleanup() {
    return DH_Cleanup();
}

long connect_s(w_login_info_t* info) {
    return DH_Login(info);
}

long connect_p(const char* username, const char* password, const char* ip, unsigned short port) {
    w_login_info_t* const info = (w_login_info_t*)calloc(1, sizeof(w_login_info_t));
    info->port = port;
    strncpy(info->ip, ip, 64);
    strncpy(info->user, username, 64);
    strncpy(info->pass, password, 64);

    long id = DH_Login(info);
    free(info);
    return id;
}

bool disconnect(long login_id) {
    return DH_Logout(login_id);
}

void get_data(long login_id, enum recstream_type type, w_datetime_t* start, w_datetime_t * end, w_buffer_t* data_buff) {
    if(!DH_SetDeviceMode(login_id, RECORD_STREAM_TYPE, &type)) {
        printf("Device Mode not set!\n");
        return;
    }

    bool loading = true;
    long handle = DH_Download(login_id, 0, ALL, start, end, NULL,
                                          BOTH_DEFAULT,
                                          NULL, data_buff,
                                          NULL, &loading);

    while (loading);

    DH_StopDownload(handle);
}

unsigned int get_error() {
    return DH_GetLastError();
}