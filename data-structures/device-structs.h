#ifndef DEVICE_STRUCTS_H
#define DEVICE_STRUCTS_H

#include "../constants/state-constants.h"
#include "../constants/config-constants.h"
#include "../constants/common-constants.h"

#define DEV_SERIAL_NUM_LEN 48
#define DEV_TYPE_LEN 32

#ifdef __cplusplus
extern "C" {
#endif

/**
 * DSP Encoding Info
 * @dahua_name DH_DSP_ENCODECAP
 * @param videoFormatMask - video format mask. Bit stands for the video format device supported.
 * @param imageSizeMask - resolution mask bit. Bit stands for the resolution setup devices supported.
 * @param encodeModeMask - encode mode mask bit. Bit stands for the encode mode devices supported.
 * @param streamCap - The multiple-media function the devices supported
 *  // The first bit:main stream
 *  // The second bit:extra stream 1
 *  // The third bit:extra stream 2
 *  // The fifth bit: snapshot in .jpg format
 * @param imageSizeMaskAssi - When the main stream is the corresponding resolution,
 * the supported extra stream resolution mask.
 * @param maxEncodePower - The highest encode capacity DSP supported
 * @param maxSupportChannel - The max video channel amount each DSP supported.
 * @param channelMaxSetSync - Max encode bit setup in each DSP channel  are synchronized or not ;
 * 0:does not synchronized,1:synchronized
 */
struct device_dsp_encode_info {
    unsigned int				videoFormatMask;
    unsigned int				imageSizeMask;
    unsigned int				encodeModeMask;
    unsigned int				streamCap;
    // The first bit:main stream
    // The second bit:extra stream 1
    // The third bit:extra stream 2
    // The fifth bit: snapshot in .jpg format
    unsigned int				imageSizeMaskAssi[8];
    unsigned int				maxEncodePower;
    unsigned short				maxSupportChannel;
    unsigned short				channelMaxSetSync;
};

/**
 * Device Version Info
 * @dahua_name DH_VERSION_INFO
 * @note
 * 'soft' and 'hard' prefixes resolve to 'software' and 'hardware' respectively
 */
struct device_version_info {
    unsigned int				softVersion;
    unsigned int				softBuildDate;
    unsigned int				dspSoftVersion;
    unsigned int				dspSoftBuildDate;
    unsigned int				panelVersion;
    unsigned int				panelSoftBuildDate;
    unsigned int				hardVersion;
    unsigned int				hardDate;
    unsigned int				webVersion;
    unsigned int				webBuildDate;
};

/**
 * System Attribute Config
 * @dahua_name DHDEV_SYSTEM_ATTR_CFG
 * @param size - struct size
 * \n\n <b>Read-Only</b>
 * @param versionInfo - version info
 * @param dspEncodeInfo - DSP encoding info
 * @param serialNum - serial number
 * @param type - device type (NET_DEVICE_TYPE)
 * @param typeName - device type name
 * @param videoCaptureNum - video port amount
 * @param audioCaptureNum - audio port amount
 * @param talkInChanNum - NSP ?
 * @param talkOutChanNum - NSP ?
 * @param decodeChanNum - NSP ?
 * @param alarmInNum - number of alarm input ports
 * @param alarmOutNum - number of alarm output ports
 * @param netIONum - number of network IO ports
 * @param usbIONum - number of USB ports
 * @param ideIONum - number of IDE ports
 * @param comIONum - number of COM ports
 * @param lptIONum - number of LPT ports
 * @param vgaIONum - NSP ?
 * @param ideControlNum - NSP ?
 * @param ideControlType - NSP ?
 * @param capability - NSP, expansible description ?
 * @param matrixOutNum - number of video-matrix output ports
 * \n\n <b>Read-Write</b>
 * @param overwrite - Operate when HDD is full(overwrite/stop) ?
 * @param recordLen - Video file Package length
 * @param dstEnable - Enable DTS or not 1 - enable, 0 - disable ?
 * @param serialNumCode - serial number (as <code>unsigned short</code>)
 * @param videoFormat - video format
 * @param dateFormat - date format
 * @param fd - date separator '.' (0) '-' (1) '/' (2)
 * @param timeSep - time separator (0-24H,1-12H)
 * @param language - language (DH_LANGUAGE_TYPE)
 */
struct device_attr_config {
    unsigned int                    size;
    /* Following properties are read-only */
    struct device_version_info      versionInfo;
    struct device_dsp_encode_info   dspEncodeInfo;
    unsigned char				    serialNum[DEV_SERIAL_NUM_LEN];
    unsigned char				    type;
    unsigned char				    typeName[DEV_TYPE_LEN];
    unsigned char				    videoCaptureNum;
    unsigned char				    audioCaptureNum;
    unsigned char				    talkInChanNum;
    unsigned char				    talkOutChanNum;
    unsigned char				    decodeChanNum;
    unsigned char				    alarmInNum;
    unsigned char				    alarmOutNum;
    unsigned char				    netIONum;
    unsigned char				    usbIONum;
    unsigned char				    ideIONum;
    unsigned char				    comIONum;
    unsigned char				    lptIONum;
    unsigned char				    vgaIONum;
    unsigned char				    ideControlNum;
    unsigned char				    ideControlType;
    unsigned char				    capability;
    unsigned char				    matrixOutNum;
    /* Following properties are read-write */
    unsigned char				    overwrite;
    unsigned char				    recordLen;
    unsigned char				    dstEnable;
    unsigned short				    serialNumCode;
    unsigned char				    videoFormat;
    unsigned char				    dateFormat;
    unsigned char				    dateSep;
    unsigned char				    timeSep;
    unsigned char				    language;
};

/**
 * Device URL config
 * @dahua_name DHDEV_URL_CFG
 * @config_type -
 * @param size - struct size
 */
struct device_url_config {
    unsigned int size;
    int isSnapshotEnabled;					// Snapshot or not
    int iSnapshotIntervalSet;			    // Snapshot interval
    char hostIP[DH_IPV4_LEN];               // HTTP host IP
    unsigned short hostPort;
    int msgInterval;					    // Message sending out interval
    char urlState[DH_MAX_URL_LEN];          // Status message upload URL
    char urlImage[DH_MAX_URL_LEN];	    // Image upload Url
    char szDevId[DH_MAX_SERIAL_NUM_LEN];    // Device web serial number
    unsigned char byReserved[2];
};

/**
 * Decoder Protocol RTSP URL Configuration
 * @dahua_name DHDEV_DECODER_URL_CFG
 * @config_type DEV_CONFIG_DECODER_URL
 * @param size - struct size
 * @param mainStreamUrl - Main stream URL
 * @param extraStreamUrl - Extra stream URL
 */
struct device_decoder_url_config {
    unsigned int size;
    char mainStreamUrl[DH_MAX_PATH_LEN];
    char extraStreamUrl[DH_MAX_PATH_LEN];
};

/**
 * Device RTSP Port Configuration
 * @dahua_name DHDEV_RTSP_CFG
 * @config_type DEV_CONFIG_RTSP
 * @param port - RTSP port
 */
struct device_rtsp_port_config {
    unsigned short port;
    unsigned char byReserved[62];   // Reserved
};

/** ---------------------------------------------------
 * DEV STATE #TODO separate later
 --------------------------------------------------- */

/**
 * Device RTSP URL info list
 * @dahua_name NET_DEV_RTSPURL_LIST
 * @state_type DEV_STATE_RTSP_URL
 * @param size - struct size
 * @param channel - channel number
 * @param urlNum - URL Address number ?
 * @param urlList - URL Address list
 */
struct device_rtsp_url_list {
    unsigned int size;
    int channel;                                 // Channel number (user input parameters)
    int urlNum;                                    // Url Address Number
    char urlList[DH_MAX_URL_NUM][DH_MAX_URL_LEN];  // UrlAddress List
};

#ifdef __cplusplus
}
#endif

#endif // DEVICE_STRUCTS_H
