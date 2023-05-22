#ifndef VIDEO_STRUCTS_H
#define VIDEO_STRUCTS_H

#include "common-structs.h"
#include "event-structs.h"

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
 * @param channel - Channel ID. <i>Note: starts from 0</i>.
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
    int						queryByTime;
    int						useRealUTC;
    struct time_stamp		startTimeRealUTC;
    struct time_stamp		endTimeRealUTC;
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
 * @associated_structure query_record_file_out
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

/**
 * Input parameter to be filled to find files
 * @dahua_name tagNET_IN_MEDIA_QUERY_FILE
 * @associated_method DH_FindFiles(...)
 * @param size - Struct size
 * @param directories - Working directory list.
 * Directories are separated by ";". Example "/mnt/dvr/sda0;/mnt/dvr/sda1".
 * If <b>directories</b> is null or an empty string - SDK will perform the search in all directories.
 * @param mediaType - Media type to search for. Any type (0), JPG (1), DAV(2)
 * @param channel - Channel ID. <i>Note: starts from 0. Value of -1 forces SDK to search all channels</i>.
 * @param startTime - Start time
 * @param endTime - End time
 * @param eventList - List of event types to search with (Intelligent analysis event [IVS])
 * @param eventNum - Number of events
 * @param videoStream - Video stream type. Unknown (0), main (1),
 * sub-stream 1 (2), sub-stream 2 (3), sub-stream 3 (4), ExtraX (5)
 * @param flagList - Flag list to search with
 * @param flagNum - Number of flags
 * @param cardInfo - ?
 * @param userNum - Number of users
 * @param userNames - ?
 * @param order - Result order
 * @param findByTime - Flag that indicates whether to search by time or not
 * @param combine - Flag that indicates whether to combine found files or not
 * @param eventInfo - ?
 * @param eventInfoNum -Number of events
 * @param findByRealUTC - Flag to skip timestamps <b>startTime</b> and <b>endTime</b>,
 * and use <b>startTimeRealUTC</b> and <b>endTimeRealUTC</b>
 * @param startTimeRealUTC - Start time
 * @param endTimeRealUTC - End time
 */
struct find_file_in {
    unsigned int              		size;
    char*               			directories;
    int								mediaType;
    int                 			channel;
    struct time_stamp            	startTime;
    struct time_stamp            	endTime;
    int                 			eventList[MAX_IVS_EVENT_NUM];
    int                 			eventNum;
    unsigned char                	videoStream;
    unsigned char               	RESERVED[3];
    enum record_metamark_type		flagList[METAMARK_TYPE_MAX];
    int                 			flagNum;
    struct card_info 			    cardInfo; // card no. record info, emFalgLists including card no. video is valid
    int                 			userNum;             // user total
    char                			userNames[MAX_QUERY_USER_NUM][DH_NEW_USER_NAME_LENGTH]; // user name
    enum result_order 			    order;
    int                			    findByTime;
    enum file_combination_mode		combine;
    struct event_info				eventInfo[16];		// event info(customized),when query type in EM_FILE_QUERY_TYPE is DH_FILE_QUERY_FILE_EX valid
    int								eventInfoNum;
    int							    findByRealUTC;
    struct time_stamp				startTimeRealUTC;
    struct time_stamp				endTimeRealUTC;
};

///@brief record info, corresponde to CLIENT_FindFileEx, search result
/**
 * @dahua_name NET_FILE_SUMMARY_INFO
 * @associated_structure find_file_out
 * @param key - Key
 * @param value - Value
 */
struct file_summary {
    char key[64];
    char value[512];
    unsigned char RESERVED[256];
};

/**
 * Output parameter to be filled by SDK when finding files
 * @dahua_name NET_OUT_MEDIA_QUERY_FILE
 * @associated_method DH_FindFiles(...)
 * @param size - Struct size
 * @param channel - Channel ID
 * @param startTime - Start time
 * @param endTime - End time
 * @param fileType - File type. JPG (1), DAV(2)
 * @param partition - Partition number
 * @param videoStream - Video stream type. Unknown (0), main (1),
 * sub-stream 1 (2), sub-stream 2 (3), sub-stream 3 (4), ExtraX (5)
 * @param cluster - Cluster
 * @param filePath - File path
 * @param eventList - List of event types received (Intelligent analysis event [IVS])
 * @param eventNum - Number of events received
 * @param flagList - Flag list received
 * @param flagNum - Number of flags received
 * @param driveNumber - Drive number
 * @param synopsisPicPath - Synopsis snapshot file path ?
 * @param synopsisMaxTime - Video synopsis maximum time in seconds ?
 * @param synopsisMinTime - Video synopsis minimum time in seconds ?
 * @param fileSummaryNum - File summary number
 * @param fileSummary - File summary list
 * @param fileSize - File size in bytes
 * @param frameNum - Number of frames
 * @param fileState - File state. Unknown (0), temporary (1), complete (2)
 * @param workDir - Storage directory of video files
 * @param thumbnailPath - Thumbnail path
 * @param useRealUTC - Flag to skip timestamps <b>startTime</b> and <b>endTime</b>,
 * and use <b>startTimeRealUTC</b> and <b>endTimeRealUTC</b>
 * @param startTimeRealUTC - Start time
 * @param endTimeRealUTC - End time
 * @deprecated
 * nFileSize - File size. Should not be used, marked as deprecated by SDK.
 * Use <b>fileSize</b> instead.\n\n
 * byDriveNo - Drive number. Should not be used, marked as deprecated by SDK.
 * Use <b>driveNumber</b> instead.\n\n
 */
struct find_file_out {
    unsigned int                size;
    int					        channel;
    struct time_stamp           startTime;
    struct time_stamp	        endTime;
    unsigned int		        nFileSize;
    unsigned char               fileType;
    unsigned char               byDriveNo;
    unsigned char               partition;
    unsigned char               videoStream;
    unsigned int                cluster;
    char				        filePath[MAX_PATH];
    int                         eventList[MAX_IVS_EVENT_NUM];
    int                         eventNum;
    enum record_metamark_type   flagList[METAMARK_TYPE_MAX];
    int                         flagNum;
    unsigned int                driveNumber;
    char                        synopsisPicPath[512];
    int                         synopsisMaxTime;
    int                         synopsisMinTime;
    int                         fileSummaryNum;
    struct file_summary         fileSummary[MAX_FILE_SUMMARY_NUM];
    long long                   fileSize;
    unsigned int			    frameNum;
    enum video_file_state       fileState;
    char                        workDir[256];
    char					    thumbnailPath[260];
    int					        useRealUTC;
    struct time_stamp           startTimeRealUTC;
    struct time_stamp           endTimeRealUTC;
};

#ifdef __cplusplus
}
#endif

#endif // VIDEO_STRUCTS_H
