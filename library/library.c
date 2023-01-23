#include "library.h"

// Default callbacks
void cb_download_pos(long handle,
                     unsigned int total_sz,
                     unsigned int download_sz,
                     int index, struct recfile_info recFile_info,
                     long loading) {
    printf("Progress: %d Kb out of %d Kb", download_sz, total_sz);
    fflush(stdout);
    if (download_sz == -1) {
        *((bool*)loading) = false;
    }
}

int cb_download_data(long handle,
                     unsigned int data_type,
                     unsigned char* buff,
                     unsigned int buff_sz,
                     long data_buff) {
    if (buff != NULL && buff_sz > 0) {
        switch (data_type) {
            case 0:
                append_buff((buffer*)data_buff, buff, buff_sz);
                printf("Buff appended by %d bytes", buff_sz);
                fflush(stdout);
            break;
            //...    // #TODO cover other types of streams
        }
    }

    return false;
}

bool SDK_init() {
    return DH_SDK_Init(NULL, 0);
}

void SDK_cleanup() {
    DH_SDK_Cleanup();
}

long connect_param(const char* username, const char* password, const char* ip, unsigned short port) {
    struct login_info info;
    memset(info.ip, 0, sizeof(info.ip));
    memset(info.username, 0, sizeof(info.username));
    memset(info.password, 0, sizeof(info.password));

    info.port = port;
    strcpy(info.ip, ip);
    strcpy(info.username, username);
    strcpy(info.password, password);

    pthread_t thread;
    pthread_create(&thread, NULL, th_login, &info);
    pthread_join(thread, NULL);
}

long connect(struct login_info* info) {
    return DH_Login(info);
}

long disconnect(long login_id) {
    DH_Logout(login_id);
}

void get_data(long login_id, enum recstream_type type, dtstamp* start, dtstamp* end, buffer* data_buff) {
    DH_SetDeviceMode(login_id, RECORD_STREAM_TYPE, &type);

    bool loading = true;
    long handle = DH_DownloadByTime(login_id, 0, ALL, (struct timestamp*)start, (struct timestamp*)end, NULL,
                                          cb_download_pos, (long)(&loading),
                                          cb_download_data, (long)(&data_buff));

    while (loading);

    DH_StopDownload(handle);
}

unsigned int get_error() {
    return DH_GetLastError();
}