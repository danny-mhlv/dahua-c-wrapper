#ifndef EVENT_STRUCTS_H
#define EVENT_STRUCTS_H

#include "../constants/common-constants.h"
#include "../constants/event-constants.h"

/**
 * Event info structure passed to "event_listen_cb_t" callback
 * @dahua_name tagNET_MESSAGE_CALLBACK_INFO
 * @param event - type of event
 * @param loginId - login ID
 * @param buff - data (should be cast to corresponding struct)
 * @param buffSize - data size
 * @param isEventAck - TRUE,the event is affirmable event;FALSE,the event is not affirmable event ?
 * @param ip - device IP address
 * @param port - device port
 * @param eventId - event ID
 * @param isRestoreEvent - flag that indicates that event is "restore event" ?
 */
struct event_listen_cb_info {
    int				event;
    unsigned char   RESERVED[4];
    long			loginId;
    char*			buff;
    unsigned int	buffSize;
    int			    isEventAck;
    char*			ip;
    int				port;
    int				eventId;
    int 			isRestoreEvent;
    unsigned char	RESERVED[1020];
};

/**
 * New file event
 * @dahua_name tagALARM_NEW_FILE_INFO
 * @param size - struct size
 * @param channel - channel number
 * @param eventId - event ID
 * @param event - event type
 * @param fileSize - size of file in bytes
 * @param index - event source channel
 * @param storagePoint - storage point
 * @param fileName - file name
 */
struct event_new_file {
    unsigned int    size;
    int             channel;
    int             eventId;
    unsigned int    event;
    int             fileSize;
    int             index;
    unsigned int    storagePoint;
    char            fileName[128];
};

/**
 * Event info
 * @dahua_name tagEVENT_INFO
 * @param type - Event type (Intelligent analysis event [IVS])
 * @param objectType - List of objects present in the event
 * @param objectCount - Number of objects present in the event
 */
struct event_info {
    int                 type;
    enum object_type    objectType[16];
    int					objectCount;
    unsigned char		RESERVED[512];
};

#endif // EVENT_STRUCTS_H
