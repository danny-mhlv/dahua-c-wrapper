#ifndef VIDEO_STRUCTS_H
#define VIDEO_STRUCTS_H

#include "common-structs.h"
#include "../constants/common-constants.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Represents video frame that is available via callback to real-time playback
 * @dahua_name tagVideoFrameParam
 * @param encode - frame encoding type
 * @param frametype - 'I' (0), 'P' (1) or 'B' (2) frame
 * @param format - PAL (0) or NTSC (1)
 * @param size - CIF (0), HD1 (1), 2CIF (2), D1 (3), VGA (4), QCIF (5),
 * QVGA (6), SVCD (7), QQVGA (8), SVGA (9), XVGA (10), WXGA (11),SXGA (12),
 * WSXGA (13),UXGA (14),WUXGA (15); LFT (16), 720 (17), 1080 (18),
 * @param fourcc - If it's H.264 encoding (0), Fill in FOURCC('X','V','I','D') in MPEG 4;
 * @param width - frame width
 * @param height - frame height
 * @param time - frame time information
 */
struct video_frame_info {
    unsigned char				encode;					// Encode type
    unsigned char				frametype;				// I = 0, P = 1, B = 2...
    unsigned char				format;					// PAL - 0, NTSC - 1
    unsigned char				size;					// CIF - 0, HD1 - 1, 2CIF - 2, D1 - 3, VGA - 4, QCIF - 5, QVGA - 6 ,
    // SVCD - 7,QQVGA - 8, SVGA - 9, XVGA - 10,WXGA - 11,SXGA - 12,WSXGA - 13,UXGA - 14,WUXGA - 15; LFT - 16, 720 - 17, 1080 - 18,
    // 1_3M-19, 2M-20, 5M-21;when size equal to 255, width and height valid
    unsigned int				fourcc;					//
    unsigned short 				width;					// width pixel, valid when struct member "size"  equal to 255
    unsigned short 				height;					// height pixel, valid when struct member "size"  equal to 255
    struct time_stamp			time;				// Time information
};

/**
 * @dahua_name tagNET_IN_QUERY_RECORD_FILE_EX
 * @associated_method DH_QueryRecordFiles(...)
 * @param size - Struct size
 * @param channel - Channel ID
 * @param recordFileType - Record file type
 * @param startTime - Start time
 * @param endTime - End time
 * @param cardId - Card ID
 * @param queryByTime - Flag that indicates whether to query by time or not
 * @param useRealUTC - Flag to skip timestamps <b>startTime</b> and <b>endTime</b>,
 * and use <b>startTimeRealUTC</b> and <b>endTimeRealUTC</b>
 * @param startTimeRealUTC - Start time
 * @param endTimeRealUTC - End time
 */
struct query_record_file_in {
    unsigned int			size;
    int					    channel;
    enum query_record_type  recordFileType;
    struct time_stamp		startTime;
    struct time_stamp		endTime;
    char*					cardId;
    int						queryByTime;                  // Whether to query by time
    int						useRealUTC;	// TRUE means only deliver stuStartTimeRealUTC and stuEndTimeRealUTC (do not deliver stuStartTime, stuEndTime), FALSE means deliver only stuStartTime, stuEndTime (do not deliver stuStartTimeRealUTC and stuEndTimeRealUTC)
    struct time_stamp		startTimeRealUTC;	// UTC start time (standard UTC time), paired with stuEndTimeRealUTC, mutually exclusive with (stuStartTime, stuEndTime)
    struct time_stamp		endTimeRealUTC;		// UTC end time (standard UTC time), paired with stuStartTimeRealUTC, mutually exclusive with (stuStartTime, stuEndTime)
};

/**
 * @dahua_name tagNET_OUT_QUERY_RECORD_FILE_EX
 * @associated_method DH_QueryRecordFiles(...)
 * @param size - Struct size
 * @param fileInfo - File info array
 * @param maxLength - The size of the requested memory, which is an integer multiple of the size of the NET_RECORDFILE_INFOEX structure
 * @param fileCount - Total number of files queried
 */
struct query_record_file_out {
    unsigned int			        size;
    struct extended_record_info*    fileInfo;
    int					            maxLength;
    int						        fileCount;
};

///@brief Record file information(extend)

/**
 * Record file info
 * @dahua_name tagNET_RECORDFILE_INFO
 * @param channel - Channel number
 * @param fileName - File name
 * @param frameCount - Total number of file frames
 * @param fileSize - File size in bytes
 * @param startTime - Start time
 * @param endTime - End time
 * @param driveNumber - HDD number
 * @param startClusterNumber - Initial cluster number
 * @param recordType - Recorded file type | general (0), alarm (1),
 * motion detection (2), card number record (3), image (4), pos record (19), all (255)
 * @param isImportant - General (0) or important (1)
 * @param hint - Document indexing ?
 * @param streamType - Main-stream (0), sub-stream 1 (1), sub-stream 2 (2), sub-stream 3 (3)
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

/**
 * @dahua_name tagNET_RECORDFILE_INFOEX
 * @param recordFileInfo - Record file information
 * @param eventList - Associated event list [IVS events]
 * @param eventCount - Number of received events
 * @param flagList - Associated flag list
 * @param flagCount - Number of received flags
 * @param useRealUTC - Flag to swap timestamps in <b>recordFileInfo</b> with startTimeRealUTC and endTimeRealUTC
 * @param startTimeRealUTC - Start time
 * @param endTimeRealUTC - End time
 */
struct extended_record_info {
    struct record_info          recordFileInfo;
    unsigned char               RESERVED[4];
    int                         eventList[256];
    int                         eventNum;
    enum record_metamark_type   flagList[128];
    int                         flagNum;
    int				            useRealUTC;
    struct time_stamp			startTimeRealUTC;
    struct time_stamp			endTimeRealUTC;
    unsigned char               RESERVED[452];
};

#ifdef __cplusplus
}
#endif

#endif // VIDEO_STRUCTS_H
