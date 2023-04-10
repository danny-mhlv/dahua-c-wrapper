#ifndef COMMON_STRUCTS_H
#define COMMON_STRUCTS_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Represents date-time point
 * @dahua_name NET_TIME
 */
struct time_stamp {
    unsigned int    year;
    unsigned int    month;
    unsigned int    day;
    unsigned int    hour;
    unsigned int    minute;
    unsigned int    second;
};

/**
 * Represents bare-minimum data for successful login
 */
struct login_info {
    char ip[64];
    int port;
    char username[64];
    char password[64];
};

/**
 * @dahua_name
 */
struct recfile_info {
    unsigned int ch;                        // Channel number
    char filename[124];            // File name
    unsigned int framenum;               // the total number of file frames
    unsigned int size;                    // File length, unit: Kunsigned char
    struct time_stamp starttime;                // Start time
    struct time_stamp endtime;                // End time
    unsigned int driveno;                // HDD number
    unsigned int startcluster;            // Initial cluster number
    unsigned char nRecordFileType;        // Recorded file type  0:general record;1:alarm record ;2:motion detection;3:card number record ;4:image ; 19:Pos record ;255:all
    unsigned char bImportantRecID;        // 0:general record 1:Important record
    unsigned char bHint;                    // Document Indexing
    unsigned char bRecType;               // 0-main stream record 1-sub1 stream record 2-sub2 stream record 3-sub3 stream record
};

#ifdef __cplusplus
}
#endif

#endif // COMMON_STRUCTS_H
