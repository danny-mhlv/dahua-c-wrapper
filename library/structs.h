#ifndef CWRAP_STRUCTS_H
#define CWRAP_STRUCTS_H

// #TODO Hub for all others struct with their method;
#include "buffer.h"

typedef struct {
    unsigned int year;
    unsigned int month;
    unsigned int day;
    unsigned int hour;
    unsigned int minute;
    unsigned int second;
} timestamp_t;

typedef struct {
    char* ip;
    int port;
    char* username;
    char* password;

    // Get/Set methods
//    void (*setIP)(login_info* s, char* str);
//    void (*setUsername)(login_info* s, char* str);
//    void (*setPassword)(login_info* s, char* str);
//    void (*setPort)(login_info* s, char* str);
} login_info_t;

typedef enum device_mode {
    TALK_CLIENT_MODE,                        // Set client-end mode to begin audio talk
    TALK_SERVER_MODE,                        // Set server mode to begin audio talk
    TALK_ENCODE_TYPE,                        // Set encode format for audio talk
    ALARM_LISTEN_MODE,                        // Set alarm subscribe way
    CONFIG_AUTHORITY_MODE,                    // Set user right to realize configuration management
    TALK_TALK_CHANNEL,                        // set talking channel(0~MaxChannel-1)
    RECORD_STREAM_TYPE,                      // set the stream type of the record for query(0-both main and extra stream,1-only main stream,2-only extra stream)
    TALK_SPEAK_PARAM,                        // set speaking parameter,corresponding to NET_SPEAK_PARAM
    RECORD_TYPE,                             // Set by time video playback and download the video file TYPE (see.net RECORD TYPE)
    TALK_MODE3,                                // Set voice intercom parameters of three generations of equipment and the corresponding structure NET TALK the EX
    PLAYBACK_REALTIME_MODE,                 // set real time playback function(0-off, 1-on)
    TALK_TRANSFER_MODE,                      // Judge the voice intercom if it was a forwarding mode, (corresponding to  NET_TALK_TRANSFER_PARAM)
    TALK_VT_PARAM,                           // Set VT Talk param (corresponding to  NET_VT_TALK_PARAM)
    TARGET_DEV_ID,                           // set target device identifier for searching system capacity information, (not zero - locate device forwards the information)
    AUDIO_RECORD_LENGTH = 15,                // set audio record length, corresponding to a int
} e_device_mode;

typedef enum recstream_type {
    BOTH = 0,
    MAIN,
    SUB
} e_recstream_type;

typedef enum recquery_type {
    ALL = 0,            // All the recorded video
    ALARM = 1,            // The video of external alarm
    MOTION_DETECT = 2,            // The video of dynamic detection alarm
    ALARM_ALL = 3,            // All the alarmed video
    CARD = 4,            // query by the card number
    CONDITION = 5,            // query by condition
    JOIN = 6,            // combination query
    CARD_PICTURE = 8,            // query pictures by the card number, used by HB-U,NVS
    PICTURE = 9,            // query pictures, used by HB-U,NVS
    FIELD = 10,           // query by field
    INTELLI_VIDEO = 11,            // Smart record search
    NET_DATA = 15,           // query network data, used by Jinqiao Internet Bar
    TRANS_DATA = 16,           // query the video of serial data
    IMPORTANT = 17,           // query the important video
    TALK_DATA = 18,           // query the recording file
    POS = 19,            // query the pos record

    INVALID = 256,          // invalid query type

} e_recquery_type;

// INTERNAL - HIDDEN
struct recfile_info {
    unsigned int ch;                        // Channel number
    char filename[124];            // File name
    unsigned int framenum;               // the total number of file frames
    unsigned int size;                    // File length, unit: Kunsigned char
    timestamp_t starttime;                // Start time
    timestamp_t endtime;                // End time
    unsigned int driveno;                // HDD number
    unsigned int startcluster;            // Initial cluster number
    unsigned char nRecordFileType;        // Recorded file type  0:general record;1:alarm record ;2:motion detection;3:card number record ;4:image ; 19:Pos record ;255:all
    unsigned char bImportantRecID;        // 0:general record 1:Important record
    unsigned char bHint;                    // Document Indexing
    unsigned char bRecType;               // 0-main stream record 1-sub1 stream record 2-sub2 stream record 3-sub3 stream record
};

#endif //CWRAP_STRUCTS_H
