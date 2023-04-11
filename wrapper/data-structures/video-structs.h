#ifndef VIDEO_STRUCTS_H
#define VIDEO_STRUCTS_H

#include "common-structs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Represents video frame that is available via callback to real-time playback
 * @dahua_name "tagVideoFrameParam"
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

#ifdef __cplusplus
}
#endif

#endif // VIDEO_STRUCTS_H
