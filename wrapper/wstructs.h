#ifndef CWRAP_WSTRUCTS_H
#define CWRAP_WSTRUCTS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "buffer.h"

// #TODO Implement struct with methods in the future?
// Structs
typedef struct {
    unsigned int year;
    unsigned int month;
    unsigned int day;
    unsigned int hour;
    unsigned int minute;
    unsigned int sec;
} w_datetime_t;

typedef struct {
    char ip[64];
    char user[64];
    char pass[64];
    unsigned int port;
} w_login_info_t;

// Enums
typedef enum {
    BOTH_DEFAULT,
    POS_DEFAULT,
    DATA_DEFAULT,
    BOTH_CUSTOM
} e_download_cb_type;

// #TODO Restruct later
typedef enum
{
    TALK_CLIENT_MODE,
    TALK_SERVER_MODE,
    TALK_ENCODE_TYPE,
    ALARM_LISTEN_MODE,
    CONFIG_AUTHORITY_MODE,
    TALK_TALK_CHANNEL,
    RECORD_STREAM_TYPE,
    TALK_SPEAK_PARAM,
    RECORD_TYPE,
    TALK_MODE3,
    PLAYBACK_REALTIME_MODE,
    TALK_TRANSFER_MODE,
    TALK_VT_PARAM,
    TARGET_DEV_ID,
    AUDIO_RECORD_LENGTH = 15,
} e_device_mode;

#ifdef __cplusplus
}
#endif

#endif //CWRAP_WSTRUCTS_H
