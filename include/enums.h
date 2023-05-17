#ifndef ENUMS_H
#define ENUMS_H

/**
 * Type of file to query for downloading
 * @dahua_name tagEmQueryRecordType
 * @param RECORD_TYPE_ALL - all recorded videos
 * @param RECORD_TYPE_ALARM - external alarm video
 * @param RECORD_TYPE_MOTION_DETECT - motion detection alarm
 * @param RECORD_TYPE_ALARM_ALL - all alarm videos
 * @param RECORD_TYPE_CARD - query video by the card number ?
 * @param RECORD_TYPE_CONDITION - query video by condition ?
 * @param RECORD_TYPE_JOIN - combination query ?
 * @param RECORD_TYPE_CARD_PICTURE - query pictures by the card number, used by HB-U,NVS ?
 * @param RECORD_TYPE_PICTURE - query pictures, used by HB-U,NVS ?
 * @param RECORD_TYPE_FIELD = query by field ?
 * @param RECORD_TYPE_INTELLI_VIDEO - smart record search ?
 * @param RECORD_TYPE_NET_DATA - query network data, used by Jinqiao Internet Bar ?
 * @param RECORD_TYPE_TRANS_DATA - query the video of serial data ?
 * @param RECORD_TYPE_IMPORTANT - query important video ?
 * @param RECORD_TYPE_TALK_DATA - query recording file ? (probably audio record?)
 * @param RECORD_TYPE_POS - query pos record ?
 * @param RECORD_TYPE_INVALID - invalid query type ?
 */
enum query_record_type {
    RECORD_TYPE_ALL = 0,
    RECORD_TYPE_ALARM,
    RECORD_TYPE_MOTION_DETECT,
    RECORD_TYPE_ALARM_ALL,
    RECORD_TYPE_CARD,
    RECORD_TYPE_CONDITION,
    RECORD_TYPE_JOIN,

    RECORD_TYPE_CARD_PICTURE = 8,
    RECORD_TYPE_PICTURE,
    RECORD_TYPE_FIELD,
    RECORD_TYPE_INTELLI_VIDEO,

    RECORD_TYPE_NET_DATA = 15,
    RECORD_TYPE_TRANS_DATA,
    RECORD_TYPE_IMPORTANT,
    RECORD_TYPE_TALK_DATA,
    RECORD_TYPE_POS,

    RECORD_TYPE_INVALID = 256,
};

/**
 * @enum Transmission Service Type
 * @param SERVICE_UNKNOWN - Unknown
 * @param SERVICE_TCP - TCP
 * @param SERVICE_UDP - UDP
 * @param SERVICE_MCAST - Multicast
 * @param SERVICE_AUTO - Auto
 */
enum transmission_service_type {
    SERVICE_UNKNOWN,
    SERVICE_TCP,
    SERVICE_UDP,
    SERVICE_MCAST,
    SERVICE_AUTO,
};

/**
 * @enum Stream Type
 * @param STREAM_ERR - Unknown
 * @param STREAM_MAIN - Main stream
 * @param STREAM_EXTRA_1 - Extra stream 1
 * @param STREAM_EXTRA_2 - Extra stream 2
 * @param STREAM_EXTRA_3 - Extra stream 3
 * @param STREAM_SNAPSHOT - Snapshot bit stream
 * @param STREAM_OBJECT - Object stream
 * @param STREAM_AUTO - Auto
 * @param STREAM_PREVIEW - Preview
 * @param STREAM_NONE - No video stream (audio only)
 */
enum net_stream_type {
    STREAM_ERR,
    STREAM_MAIN,
    STREAM_EXTRA_1,
    STREAM_EXTRA_2,
    STREAM_EXTRA_3,
    STREAM_SNAPSHOT,
    STREAM_OBJECT,
    STREAM_AUTO,
    STREAM_PREVIEW,
    STREAM_NONE,
};

/**
 * @enum Video Stream Type
 * @param VIDEO_STREAM_UNKNOWN - Unknown
 * @param VIDEO_STREAM_MAIN - Main stream
 * @param VIDEO_STREAM_EXTRA1 - Extra stream 1
 * @param VIDEO_STREAM_EXTRA2 - Extra stream 2
 * @param VIDEO_STREAM_EXTRA3 - Extra stream 3
 * @param VIDEO_STREAM_AUTO - Auto
 * @param VIDEO_STREAM_PREVIEW - Preview
 * @param VIDEO_STREAM_NO_VIDEO_JUST_AUDIO - No video stream (audio only)
 */
enum video_stream_type {
    VIDEO_STREAM_UNKNOWN,
    VIDEO_STREAM_MAIN,
    VIDEO_STREAM_EXTRA1,
    VIDEO_STREAM_EXTRA2,
    VIDEO_STREAM_EXTRA3,
    VIDEO_STREAM_AUTO,
    VIDEO_STREAM_PREVIEW,
    VIDEO_STREAM_NO_VIDEO_JUST_AUDIO,
};

/**
 * @enum Logic Channel Type
 * @param CHAN_TYPE_UNKNOWN - Unknown
 * @param CHAN_TYPE_LOCAL - Local channel
 * @param CHAN_TYPE_REMOTE - Remote channel
 * @param CHAN_TYPE_COMPOSE - Synthesis of channels (Example:
 * for judicial equipment contains picture-in-picture channel and mixing channel)
 * @param CHAN_TYPE_MATRIX - Matrix channel, including analog-matrix and digital-matrix
 * @param CHAN_TYPE_CASCADE - Cascading channel
 */
enum logic_channel_type {
    CHAN_TYPE_UNKNOWN,
    CHAN_TYPE_LOCAL,
    CHAN_TYPE_REMOTE,
    CHAN_TYPE_COMPOSE,
    CHAN_TYPE_MATRIX,
    CHAN_TYPE_CASCADE,
};

/**
 * @enum Device Protocol
 * @param DEV_PROTOCOL_PRIVATE2 - Second Private protocol
 * @param DEV_PROTOCOL_PRIVATE3 - Third Private protocol
 * @param DEV_PROTOCOL_ONVIF - ONVIF
 * @param DEV_PROTOCOL_VNC - Virtual Network Computing
 * @param DEV_PROTOCOL_TS - Standard TS
 * @param DEV_PROTOCOL_ECLOUD - ECloud
 * @param DEV_PROTOCOL_GENERAL - General
 * @param DEV_PROTOCOL_PRIVATE - Private Protocol
 * @param DEV_PROTOCOL_AEBELL - Aebell Protocol
 * @param DEV_PROTOCOL_PANASONIC - Panasonic Protocol
 * @param DEV_PROTOCOL_SONY - Sony Protocol
 * @param DEV_PROTOCOL_DYNACOLOR - DynaColor Protocol
 * @param DEV_PROTOCOL_TCWS -
 * @param DEV_PROTOCOL_SAMSUNG - Samsung Protocol
 * @param DEV_PROTOCOL_YOKO - YOKO Protocol
 * @param DEV_PROTOCOL_AXIS - AXIS Protocol
 * @param DEV_PROTOCOL_SANYO - SANYO Protocol
 * @param DEV_PROTOCOL_BOSCH - Bosch Protocol
 * @param DEV_PROTOCOL_PELCO - Pelco Protocol
 * @param DEV_PROTOCOL_PROVIDEO -
 * @param DEV_PROTOCOL_ACTI - ACTi Protocol
 * @param DEV_PROTOCOL_VIVOTEK - VIVOTEK Protocol
 * @param DEV_PROTOCOL_ARECONT - Arecont Protocol
 * @param DEV_PROTOCOL_PRIVATEEH -
 * @param DEV_PROTOCOL_IMATEK - IMATEK Protocol
 * @param DEV_PROTOCOL_SHANY - SHANY Protocol
 * @param DEV_PROTOCOL_VIDEOTREC - VIDEOTREC Protocol
 * @param DEV_PROTOCOL_URA -
 * @param DEV_PROTOCOL_BTICINO - Bticino Protocol
 * @param DEV_PROTOCOL_ONVIF2 - Same as <b>DEV_PROTOCOL_ONVIF</b>
 * @param DEV_PROTOCOL_SHEPHERD - Shepherd Protocol (Camera Management Tool [Vivotek])
 * @param DEV_PROTOCOL_YAAN - Yaan Protocol
 * @param DEV_PROTOCOL_AIRPOINT -
 * @param DEV_PROTOCOL_TYCO - Tyco Protocol
 * @param DEV_PROTOCOL_XUNMEI - XUNMEI Protocol
 * @param DEV_PROTOCOL_HIKVISION - Hikvision Protocol
 * @param DEV_PROTOCOL_LG - LG Protocol
 * @param DEV_PROTOCOL_AOQIMAN -
 * @param DEV_PROTOCOL_BAOKANG -
 * @param DEV_PROTOCOL_WATCHNET - WatchNET Protocol
 * @param DEV_PROTOCOL_XVISION - XVISION Protocol
 * @param DEV_PROTOCOL_FUSITSU - ? Probably Fujitsu ?
 * @param DEV_PROTOCOL_CANON - Canon
 * @param DEV_PROTOCOL_GE - GE (General Electronics)
 * @param DEV_PROTOCOL_BASLER - Basler AG
 * @param DEV_PROTOCOL_PATRO -
 * @param DEV_PROTOCOL_CPKNC - CP PLUS (K series) Protocol
 * @param DEV_PROTOCOL_CPRNC - CP PLUS (R series) Protocol
 * @param DEV_PROTOCOL_CPUNC - CP PLUS (U series) Protocol
 * @param DEV_PROTOCOL_CPPLUS - CP PLUS IPC Protocol
 * @param DEV_PROTOCOL_XUNMEIS - XUNMEIS Protocol (ONVIF)
 * @param DEV_PROTOCOL_GDDW - GDDW Protocol
 * @param DEV_PROTOCOL_PSIA - PSIA Protocol
 * @param DEV_PROTOCOL_GB2818 - GB2818 Protocol
 * @param DEV_PROTOCOL_GDYX - GDYX (Baidu disk extraction code)
 * @param DEV_PROTOCOL_OTHER - Other
 * @param DEV_PROTOCOL_MULTICAST - Multicast
 * @param DEV_PROTOCOL_MULTICASTTS - MulticastTs, to achieve TS multicast function
 */
enum device_protocol {
    DEV_PROTOCOL_PRIVATE2,
    DEV_PROTOCOL_PRIVATE3,
    DEV_PROTOCOL_ONVIF,
    DEV_PROTOCOL_VNC,
    DEV_PROTOCOL_TS,
    DEV_PROTOCOL_ECLOUD,
    DEV_PROTOCOL_GENERAL,

    DEV_PROTOCOL_PRIVATE = 100,
    DEV_PROTOCOL_AEBELL,
    DEV_PROTOCOL_PANASONIC,
    DEV_PROTOCOL_SONY,
    DEV_PROTOCOL_DYNACOLOR,
    DEV_PROTOCOL_TCWS,						// tcsw
    DEV_PROTOCOL_SAMSUNG,
    DEV_PROTOCOL_YOKO,
    DEV_PROTOCOL_AXIS,
    DEV_PROTOCOL_SANYO,
    DEV_PROTOCOL_BOSCH,
    DEV_PROTOCOL_PELCO,
    DEV_PROTOCOL_PROVIDEO,					// Provideo
    DEV_PROTOCOL_ACTI,
    DEV_PROTOCOL_VIVOTEK,
    DEV_PROTOCOL_ARECONT,
    DEV_PROTOCOL_PRIVATEEH,			        // PrivateEH
    DEV_PROTOCOL_IMATEK,
    DEV_PROTOCOL_SHANY,
    DEV_PROTOCOL_VIDEOTREC,
    DEV_PROTOCOL_URA,						// Ura
    DEV_PROTOCOL_BITICINO,
    DEV_PROTOCOL_ONVIF2,
    DEV_PROTOCOL_SHEPHERD,
    DEV_PROTOCOL_YAAN,
    DEV_PROTOCOL_AIRPOINT,					// Airpop
    DEV_PROTOCOL_TYCO,
    DEV_PROTOCOL_XUNMEI,
    DEV_PROTOCOL_HIKVISION,
    DEV_PROTOCOL_LG,
    DEV_PROTOCOL_AOQIMAN,					// aoqiman
    DEV_PROTOCOL_BAOKANG,                    // baokang
    DEV_PROTOCOL_WATCHNET,
    DEV_PROTOCOL_XVISION,
    DEV_PROTOCOL_FUSITSU,
    DEV_PROTOCOL_CANON,
    DEV_PROTOCOL_GE,
    DEV_PROTOCOL_BASLER,
    DEV_PROTOCOL_PATRO,						// patro
    DEV_PROTOCOL_CPKNC,
    DEV_PROTOCOL_CPRNC,
    DEV_PROTOCOL_CPUNC,
    DEV_PROTOCOL_CPPLUS,
    DEV_PROTOCOL_XUNMEIS,
    DEV_PROTOCOL_GDDW,						// GDDW
    DEV_PROTOCOL_PSIA,
    DEV_PROTOCOL_GB2818,
    DEV_PROTOCOL_GDYX,
    DEV_PROTOCOL_OTHER,
    DEV_PROTOCOL_MULTICAST = 179,
    DEV_PROTOCOL_MULTICASTTS = 185,
};

/**
 * @enum Encryption Level
 * @param ENCRYPT_LEVEL_UNKNOWN - Unknown
 * @param ENCRYPT_LEVEL_NONE - Not encrypted
 * @param ENCRYPT_LEVEL_IFRAME256 - Encrypted 256 bytes in I-frame
 * @param ENCRYPT_LEVEL_IFRAME_WHOLE - Encrypted whole I-frame
 * @param ENCRYPT_LEVEL_IAXFRAME - Encrypted whole I-frame, audio-frame and other auxiliary frames
 */
enum encrypt_level {
    ENCRYPT_LEVEL_UNKNOWN,
    ENCRYPT_LEVEL_NONE,
    ENCRYPT_LEVEL_IFRAME256,
    ENCRYPT_LEVEL_IFRAME_WHOLE,
    ENCRYPT_LEVEL_IAXFRAME,
};

/**
 * @enum Encryption Algorithm
 * @param ENCRYPT_ALGORITHM_UNKNOWN - Unknown
 * @param ENCRYPT_ALGORITHM_AES - Advanced Encryption Standard
 * @param ENCRYPT_ALGORITHM_DES - Data Encryption Standard
 * @param ENCRYPT_ALGORITHM_3DES - Triple Data Encryption Standard
 */
enum encrypt_algorithm {
    ENCRYPT_ALGORITHM_UNKNOWN,
    ENCRYPT_ALGORITHM_AES,
    ENCRYPT_ALGORITHM_DES,
    ENCRYPT_ALGORITHM_3DES,
};

/**
 * @enum Exchange Key
 * @param KEY_EXCHANGE_UNKNOWN - Unknown
 * @param KEY_EXCHANGE_MIKEY - Multimedia Internet Keying
 * @param KEY_EXCHANGE_PSK - Pre-Shared Key
 * @param KEY_EXCHANGE_PK - Public Key
 * @param KEY_EXCHANGE_DH - Diffie–Hellman Key
 */
enum key_exchange {
    KEY_EXCHANGE_UNKNOWN,
    KEY_EXCHANGE_MIKEY,
    KEY_EXCHANGE_PSK,
    KEY_EXCHANGE_PK,
    KEY_EXCHANGE_DH,
};

// #TODO Decrypt
/**
 * @dahua_name __EM_USEDEV_MODE
 * @enum Use Device Mode
 * @param MODE_TALK_CLIENT - Set client-end mode to begin audio-talk
 * @param MODE_TALK_SERVER - Set server-end mode to begin audio-talk
 * @param MODE_TALK_ENCODE_TYPE - Set encoding format for audio-talk
 * @param MODE_ALARM_LISTEN_TYPE - Set alarm subscribe way
 * @param MODE_AUTH_MANAGE_CONFIG - Set user right to realize configuration management ??????
 * @param MODE_TALK_CHANNEL - Set talking channel(0~MaxChannel-1) ????????
 * @param MODE_RECORD_STREAM_TYPE - Set the stream type of the record for query.
 * Both main- and extra-stream (0), only main-stream (1),only extra-stream (2)
 * @param MODE_TALK_SPEAK_PARAM - Set speaking parameter (NET_SPEAK_PARAM)
 * @param MODE_RECORD_TYPE - Set by time video playback and download the video file TYPE (see.net RECORD TYPE)
 * @param MODE_TALK_MODE3 - Set voice intercom parameters of three generations of equipment and the corresponding
 * structure NET TALK the EX
 * @param MODE_PLAYBACK_REALTIME - set real time playback function(0-off, 1-on)
 * @param MODE_TALK_TRANSFER - Judge the voice intercom if it was a forwarding mode,
 * (corresponding to  NET_TALK_TRANSFER_PARAM)
 * @param MODE_TALK_VT_PARAM - Set VT Talk param (corresponding to  NET_VT_TALK_PARAM)
 * @param MODE_TARGET_DEV_ID - set target device identifier for searching system capacity information,
 * (not zero - locate device forwards the information)
 * @param MODE_AUDIO_RECORD_LENGTH - Set audio record length
 */
enum use_device_mode {
    MODE_TALK_CLIENT,
    MODE_TALK_SERVER,
    MODE_TALK_ENCODE_TYPE,
    MODE_ALARM_LISTEN_TYPE,
    MODE_AUTH_MANAGE_CONFIG,
    MODE_TALK_CHANNEL,
    MODE_RECORD_STREAM_TYPE,
    MODE_TALK_SPEAK_PARAM,
    MODE_RECORD_TYPE,
    MODE_TALK_MODE3,
    MODE_PLAYBACK_REALTIME,
    MODE_TALK_TRANSFER,
    MODE_TALK_VT_PARAM,
    MODE_TARGET_DEV_ID,
    MODE_AUDIO_RECORD_LENGTH = 15,
};

/**
 * Metadata mark of the snapshot/video record file
 * @dahua_name _EM_RECORD_SNAP_FLAG_TYPE
 * @param METAMARK_TYPE_UNKNOWN - Unknown file type
 * @param METAMARK_TYPE_TIMING - ???
 * @param METAMARK_TYPE_MANUAL - Manual ?
 * @param METAMARK_TYPE_IMPORTANT - Marked as "Important"
 * @param METAMARK_TYPE_EVENT - Event
 * @param METAMARK_TYPE_COMBINED - Combined
 * @param METAMARK_TYPE_CUTOUT - Cut
 * @param METAMARK_TYPE_LEAVE_WORD - Message
 * @param METAMARK_TYPE_TALKBACK_LOCAL - Talk local
 * @param METAMARK_TYPE_TALKBACK_REMOTE - Talk remote
 * @param METAMARK_TYPE_COMPRESSED - Compressed video
 * @param METAMARK_TYPE_ORIGINAL - Original video
 * @param METAMARK_TYPE_PROCESSED - Processed
 * @param METAMARK_TYPE_BLACK_PLATE_PIC - Blacklist picture
 * @param METAMARK_TYPE_ORIGINAL_PIC - Original picture
 * @param METAMARK_TYPE_CARD - Card number
 * @param METAMARK_TYPE_MAX - ???
 */
enum record_metamark_type {
    METAMARK_TYPE_UNKNOWN = -1,
    METAMARK_TYPE_TIMING,
    METAMARK_TYPE_MANUAL,
    METAMARK_TYPE_IMPORTANT,
    METAMARK_TYPE_EVENT,
    METAMARK_TYPE_COMBINED,
    METAMARK_TYPE_CUTOUT,
    METAMARK_TYPE_LEAVE_WORD,
    METAMARK_TYPE_TALKBACK_LOCAL,
    METAMARK_TYPE_TALKBACK_REMOTE,
    METAMARK_TYPE_COMPRESSED,
    METAMARK_TYPE_ORIGINAL,
    METAMARK_TYPE_PROCESSED,
    METAMARK_TYPE_BLACK_PLATE_PIC,
    METAMARK_TYPE_ORIGINAL_PIC,
    METAMARK_TYPE_CARD,
    METAMARK_TYPE_MAX = 128,
};

#endif // ENUMS_H
