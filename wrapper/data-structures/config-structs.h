#ifndef CONFIG_STRUCTS_H
#define CONFIG_STRUCTS_H

///@brief RTSP configuration
/**
 * RTSP Configuration Structure [outputted from the end-device]
 * @dahua_name tagCFG_RTSP_INFO_OUT
 * @oaran size - struct size
 * @param isEnabled - is RTSP enabled
 * @param rtspPort - RTSP port
 * @param rtpStartPort - RTP start port range
 * @param rtpEndPort - RTP end port range
 * @param isHttpEnabled - is RTSP over HTTP enabled
 * @param httpPort - RTSP over HTTP port
 */
struct config_rtsp {
    int     size;
    int     isEnabled;
    int     rtspPort;
    int     rtpStartPort;
    int     rtpEndPort;
    int     isHttpEnabled;
    int     httpPort;
};

#endif // CONFIG_STRUCTS_H
