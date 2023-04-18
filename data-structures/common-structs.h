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
 * Record file info
 * @dahua_name tagNET_RECORDFILE_INFO
 * @param channel - channel number
 * @param fileName - file name
 * @param frameCount - total number of file frames
 * @param fileSize - file size in bytes
 * @param startTime - start time
 * @param endTime - end time
 * @param driveNumber - HDD number
 * @param startClusterNumber - initial cluster number
 * @param recordType - recorded file type | general (0), alarm (1),
 * motion detection (2), card number record (3), image (4), pos record (19), all (255)
 * @param isImportant - general (0) or important (1)
 * @param hint - document indexing ?
 * @param streamType - main-stream (0), sub-stream 1 (1), sub-stream 2 (2), sub-stream 3 (3)
 */
struct record_info {
    unsigned int channel;
    char fileName[124];
    unsigned int frameCount;
    unsigned int fileSize;
    struct time_stamp startTime;
    struct time_stamp endTime;
    unsigned int driveNumber;
    unsigned int startClusterNumber;
    unsigned char recordType;
    unsigned char isImportant;
    unsigned char hint;
    unsigned char streamType;
};

#ifdef __cplusplus
}
#endif

#endif // COMMON_STRUCTS_H
