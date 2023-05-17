#ifndef CAMERA_STRUCTS_H
#define CAMERA_STRUCTS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../enums.h"
#include "common-structs.h"
#include "../constants/common-constants.h"


/**
 * @dahua_name tagNET_SOURCE_STREAM_ENCRYPT
 * @param encryptLevel - encryption level
 * @param algorithm - stream encryption algorithm
 * @param exchange - type of exchange key
 * @param isUnvarnished - MTS using scene,true is interacting with MIKEY and than donot encrypt data
 * @param psk - encryption key
 */
struct src_stream_encrypt {
    enum encrypt_level      encryptLevel;
    enum encrypt_algorithm  algorithm;
    enum key_exchange       exchange;
    int                     isUnvarnished;
    char                    psk[1032];
    unsigned char           byReserved[1024];   // Revered
};

/**
 * @dahua_name tagDH_VIDEO_INPUTS
 * @param size - struct size
 * @param chanName - channel name
 * @param isEnabled
 * @param controlID - control ID
 * @param mainStreamUrl - main-stream URL
 * @param extraStreamUrl - extra-stream URL
 * @param optionalMainUrlCount - spare main-stream address quantity
 * @param optionalMainUrls - spare main-stream address list
 * @param optionalExtraUrlCount - spare extra-stream address quantity
 * @param optionalExtraUrls - spare extra-stream address list
 * @param caption - caption
 * @param serviceType - service type
 * @param sourceStreamEncrypt - source stream encryption
 */
struct video_inputs {
    unsigned int		            size;
    char				            chanName[DH_DEVICE_NAME_LEN];
    int				                isEnabled;
    char				            controlID[DH_DEVICE_ID_LEN];
    char				            mainStreamUrl[DH_MAX_PATH_LEN];
    char				            extraStreamUrl[DH_MAX_PATH_LEN];
    int                             optionalMainUrlCount;
    char                            optionalMainUrls[DH_MAX_OPTIONAL_URL][DH_MAX_PATH_LEN];
    int                             optionalExtraUrlCount;
    char                            optionalExtraUrls[DH_MAX_OPTIONAL_URL][DH_MAX_PATH_LEN];
    char                            caption[32];
    enum transmission_service_type  serviceType;
    struct src_stream_encrypt       sourceStreamEncrypt;
};

/**
 * @dahua_name tagNET_REMOTE_DEVICE_EX
 * @param password - device password
 * @param passUsed - flag that indicates if password is used
 */
struct remote_device_pass {
    char password[128];
    int passUsed;
    char szReserved[1020];  // Reserved
};

/**
 * @dahua_name tagDH_REMOTE_DEVICE
 * @param size - struct size
 * @param isEnabled - flag that indicates availability of the device
 * @param ip - device IP address
 * @param user - device account username
 * @param pass - device account password
 * @param port - device port
 * @param definition - device definition setting. Standard (0) and High (1)
 * @param protocol - device protocol type
 * @param name - device name
 * @param videoInputChannels - count channel of video input
 * @param audioInputChannels - count channel of audio input
 * @param class - device class, such as IPC, DVR, NVR
 * @param type - device type, such as IPC-HF3300
 * @param httpPort - device HTTP port
 * @param maxVideoInputCount - max count of video input
 * @param retVideoInputCount - return count of video input
 *
 * @param machineAddress - machine address
 * @param serialNumber - device serial number
 * @param rtspPort - device RTSP port
 *
 * @param vendorAbbr - vendor abbreviation
 * @param softwareVersion - device software version
 * @param activationTime - device activation time
 * @param mac - device MAC address
 * @param httpsPort - device HTTPS port
 */
struct remote_device {
    unsigned int		        size;
    int				            isEnabled;
    char			            ip[DH_IPV4_LEN];
    char			            user[DH_USER_NAME_LEN];
    char			            pass[DH_USER_PASS_LEN];
    int			    	        port;
    int				            definition;
    enum device_protocol        protocol;
    char			            name[DH_DEVICE_NAME_LEN];
    int					        videoInputChannels;
    int					        audioInputChannels;
    char				        devClass[DH_DEVICE_TYPE_LEN];
    char				        devType[DH_DEVICE_TYPE_LEN];
    int					        httpPort;
    int					        maxVideoInputCount;
    int                         retVideoInputCount;
    struct video_inputs*	    pstuVideoInputs;                // max count of audion input, user malloc the memory,apply to sizeof(DH_VIDEO_INPUTS)*nMaxVideoInputCount
    char				        machineAddress[DH_CARD_INFO_LEN];
    char				        szSerialNo[DH_SERIAL_LEN];
    int                         rtspPort;
    char                        szUserEx[DH_USER_NAME_LEN_EX];     // username
    char                        szPwdEx[DH_USER_PASS_LEN_EX];      // password,When the password needs to be greater than or equal to 32 bits, use szpwdex2 in pstuRemoteDevEx
    char				        vendorAbbr[32];
    char                        softwareVersion[64];
    struct time_stamp           activationTime;
    char                        mac[20];
    int                         httpsPort;
    unsigned char               reserved[4];                    // Reserved
    struct remote_device_pass*  pstuRemoteDevEx;                // DH_REMOTE_DEVICE extend,user malloc the memory,apply to sizeof(NET_REMOTE_DEVICE_EX)
};

// DVR GetCameras data-structures

/**
 * @dahua_name tagDH_MATRIX_CAMERA_INFO
 * @param size - struct size
 * @param name - camera name
 * @param deviceID - device ID
 * @param controlID - control ID
 * @param channelID - channel ID
 * @param uniqueChannel - unique channel
 * @param isRemoteDevSupported - flag that indicates support for remote device
 * @param remoteDevInfo - remote device info
 * @param netStreamType - stream type
 * @param chanType - channel type
 * @param isEnabled
 * @param vidStreamType - video stream
 */
struct dh_camera_info {
    unsigned int	    	size;
    char			    	name[DH_DEVICE_ID_LEN];
    char			    	deviceID[DH_DEVICE_ID_LEN];
    char				    controlID[DH_DEVICE_ID_LEN];
    int				    	channelID;
    int				    	uniqueChannel;
    int				        isRemoteDevSupported;
    struct remote_device    remoteDevInfo;
    enum net_stream_type    netStreamType;
    enum logic_channel_type chanType;
    int                     isEnabled;
    enum video_stream_type  vidStreamType;
};

/**
 * @dahua_name tagDH_IN_MATRIX_GET_CAMERAS
 * @param size - struct size
 */
struct dh_getcam_in {
    unsigned int size;
};

/**
 * @dahua_name tagDH_OUT_MATRIX_GET_CAMERAS
 * @param size - struct size
 * @param cameras - array to store output in
 * @param maxCameras - number of cameras in array (size of array element-wise)
 * @param totalCamsReturned - number of cameras actually returned
 */
struct dh_getcam_out {
    unsigned int size;
    struct dh_camera_info* cameras;
    int maxCameras;
    int totalCamsReturned;
};

#ifdef __cplusplus
}
#endif

#endif // CAMERA_STRUCTS_H
