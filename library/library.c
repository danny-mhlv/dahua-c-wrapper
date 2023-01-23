#include "library.h"

bool SDK_init() {
    return CLIENT_Init(NULL, 0);
}

void SDK_cleanup() {
    CLIENT_Cleanup();
}

long connect(login_info_t* info) {
    pthread_t th;
    pthread_create(&th, NULL, th_login, info);
    pthread_join(th, NULL);
}

long connect_param(const char* username, const char* password, const char* ip, unsigned short port) {
    login_info_t info;
    info.port = port;
    strcpy(info.ip, ip);
    strcpy(info.username, username);
    strcpy(info.password, password);

    pthread_t th;
    pthread_create(&th, NULL, th_login, &info);
    pthread_join(th, NULL);
}

long disconnect(long login_id) {
    CLIENT_Logout(login_id);
}

void get_data(long login_id, enum recstream_type type, timestamp_t* start, timestamp_t* end, buffer* data_buff) {
    CLIENT_SetDeviceMode(login_id, RECORD_STREAM_TYPE, &type);

    bool loading = true;
    long handle = CLIENT_DownloadByTimeEx(login_id, 0, ALL, (struct timestamp*)start, (struct timestamp*)end, NULL,
                                          cb_default_download_pos, (long)(&loading),
                                          cb_default_download_buff, (long)(&data_buff));

    while (loading);

    CLIENT_StopDownload(handle);
}

unsigned int get_error() {
    return CLIENT_GetLastError();
}