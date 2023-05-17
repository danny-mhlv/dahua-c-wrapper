#ifndef STATE_CONSTANTS_H
#define STATE_CONSTANTS_H

#define DEV_STATE_COMM_ALARM                  0x0001           // Search general alarm status(including external alarm,video loss, motion detection)
#define DEV_STATE_SHELTER_ALARM               0x0002           // Search camera masking alarm status
#define DEV_STATE_RECORDING                   0x0003           // Search record status
#define DEV_STATE_DISK                        0x0004           // Search HDD information
#define DEV_STATE_RESOURCE                    0x0005           // Search system resources status
#define DEV_STATE_BITRATE                     0x0006           // Search channel bit stream
#define DEV_STATE_CONN                        0x0007           // Search device connection status
#define DEV_STATE_PROTOCAL_VER                0x0008           // Search network protocol version number , pBuf = int*
#define DEV_STATE_TALK_ECTYPE                 0x0009           // Search the audio talk format the device supported. Please refer to structure DHDEV_TALKFORMAT_LIST
#define DEV_STATE_SD_CARD                     0x000A           // Search SD card information(FOR IPC series)
#define DEV_STATE_BURNING_DEV                 0x000B           // Search burner information
#define DEV_STATE_BURNING_PROGRESS            0x000C           // Search burning information
#define DEV_STATE_PLATFORM                    0x000D           // Search the embedded platform the device supported
#define DEV_STATE_CAMERA                      0x000E           // Search camera property information ( for IPC series),pBuf = DHDEV_CAMERA_INFO *,there can be several structure.
#define DEV_STATE_SOFTWARE                    0x000F           // Search device software version information
#define DEV_STATE_LANGUAGE                    0x0010           // Search the audio type the device supported
#define DEV_STATE_DSP                         0x0011           // Search DSP capacity description
#define DEV_STATE_OEM                         0x0012           // Search OEM information
#define DEV_STATE_NET                         0x0013           // Search network running status information
#define DEV_STATE_TYPE                        0x0014           // Search function attributes(for IPC serirs)
#define DEV_STATE_SNAP                        0x0015           // Search snapshot function attribute(For IPC series)
#define DEV_STATE_RECORD_TIME                 0x0016           // Query the first time and the recent video time
#define DEV_STATE_NET_RSSI                    0x0017           // Query the wireless network signal strength,Please refer to structure DHDEV_WIRELESS_RSS_INFO
#define DEV_STATE_BURNING_ATTACH              0x0018           // Burning options inquiry
#define DEV_STATE_BACKUP_DEV                  0x0019           // Query the list of backup device
#define DEV_STATE_BACKUP_DEV_INFO             0x001a           // Query the backup device information
#define DEV_STATE_BACKUP_FEEDBACK             0x001b           // backup rate of progress
#define DEV_STATE_ATM_QUERY_TRADE             0x001c           // Query ATM trade type
#define DEV_STATE_SIP                         0x001d           // Query sip state
#define DEV_STATE_VICHILE_STATE               0x001e           // Query wifi state of mobile DVR
#define DEV_STATE_TEST_EMAIL                  0x001f           // Query Email Function
#define DEV_STATE_SMART_HARD_DISK             0x0020           // Query Hard Disk Information
#define DEV_STATE_TEST_SNAPPICTURE            0x0021           // Query Snap Picture Function
#define DEV_STATE_STATIC_ALARM                0x0022           // Query static alarm state
#define DEV_STATE_SUBMODULE_INFO              0x0023           // Query submodule information
#define DEV_STATE_DISKDAMAGE                  0x0024           // Query hard disk damage ability
#define DEV_STATE_IPC                         0x0025           // Query device supported IPC ability,see struct DH_DEV_IPC_INFO
#define DEV_STATE_ALARM_ARM_DISARM            0x0026           // Query alarm arm disarm state
#define DEV_STATE_ACC_POWEROFF_ALARM          0x0027           // Query ACC power off state(return a DWORD type value, 1 means power off,0 means power on)
#define DEV_STATE_TEST_FTP_SERVER             0x0028           // FTP server connect test
#define DEV_STATE_3GFLOW_EXCEED               0x0029           // Query 3G Flow exceed state info(see struct DHDEV_3GFLOW_EXCEED_STATE_INFO)
#define DEV_STATE_3GFLOW_INFO                 0x002a           // Query 3G Flow info(see struct DH_DEV_3GFLOW_INFO)
#define DEV_STATE_VIHICLE_INFO_UPLOAD         0x002b           // Vihicle information uploading
#define DEV_STATE_SPEED_LIMIT                 0x002c           // Speed limit alarm
#define DEV_STATE_DSP_EX                      0x002d           // Query DSP expended cap(struct DHDEV_DSP_ENCODECAP_EX)
#define DEV_STATE_3GMODULE_INFO               0x002e           // Query 3G module info(struct DH_DEV_3GMODLE_INFO)
#define DEV_STATE_MULTI_DDNS                  0x002f           // Query multi DDNS status(struct DH_DEV_MULTI_DDNS_INFO)
#define DEV_STATE_CONFIG_URL                  0x0030           // Query Device URL info(struct DH_DEV_URL_INFO)
#define DEV_STATE_HARDKEY                     0x0031           // Query Hard key state(struct DHDEV_HARDKEY_STATE)
#define DEV_STATE_ISCSI_PATH                  0x0032           // Query ISCSI path(struct DHDEV_ISCSI_PATHLIST)
#define DEV_STATE_DLPREVIEW_SLIPT_CAP         0x0033           // Query local preview split capability(struct DEVICE_LOCALPREVIEW_SLIPT_CAP)
#define DEV_STATE_WIFI_ROUTE_CAP              0x0034           // Query wifi capablity(struct DHDEV_WIFI_ROUTE_CAP)
#define DEV_STATE_ONLINE                      0x0035           // Query device online state(return a DWORD value, 1-online, 0-offline)
#define DEV_STATE_PTZ_LOCATION                0x0036           // Query ptz state(struct DH_PTZ_LOCATION_INFO)
#define DEV_STATE_MONITOR_INFO                0x0037           // Query monitor state(state DHDEV_MONITOR_INFO)
#define DEV_STATE_SUBDEVICE                   0x0300           // Query subdevcie(fan,cpu...) state(struct CFG_DEVICESTATUS_INFO)
#define DEV_STATE_RAID_INFO                   0x0038           // Query RAID state(struct ALARM_RAID_INFO)
#define DEV_STATE_TEST_DDNSDOMAIN             0x0039           // test DDNS domain enable
#define DEV_STATE_VIRTUALCAMERA               0x003a           // query virtual camera state(struct DHDEV_VIRTUALCAMERA_STATE_INFO)
#define DEV_STATE_TRAFFICWORKSTATE            0x003b           // get device's state of video/coil module(struct DHDEV_TRAFFICWORKSTATE_INFO)
#define DEV_STATE_ALARM_CAMERA_MOVE           0x003c           // get camera move alarm state(struct ALARM_CAMERA_MOVE_INFO)
#define DEV_STATE_ALARM                       0x003e           // get external alarm(struct NET_CLIENT_ALARM_STATE)
#define DEV_STATE_VIDEOLOST                   0x003f           // get video loss alarm(struct NET_CLIENT_VIDEOLOST_STATE)
#define DEV_STATE_MOTIONDETECT                0x0040           // get motion alarm(struct NET_CLIENT_MOTIONDETECT_STATE)
#define DEV_STATE_DETAILEDMOTION              0x0041           // get detailed motion alarm(struct NET_CLIENT_DETAILEDMOTION_STATE)
#define DEV_STATE_VEHICLE_INFO                0x0042           // get vehicle device state(struct DHDEV_VEHICLE_INFO)
#define DEV_STATE_VIDEOBLIND                  0x0043           // get blind alarm(struct NET_CLIENT_VIDEOBLIND_STATE)
#define DEV_STATE_3GSTATE_INFO                0x0044           // Query 3G state(struct DHDEV_VEHICLE_3GMODULE)
#define DEV_STATE_NETINTERFACE                0x0045           // Query net interface(struct DHDEV_NETINTERFACE_INFO)
#define DEV_STATE_PICINPIC_CHN                0x0046           // Query picinpic channel(struct DWORD)
#define DEV_STATE_COMPOSITE_CHN               0x0047           // Query splice screen(struct DH_COMPOSITE_CHANNEL)
#define DEV_STATE_WHOLE_RECORDING             0x0048           // Query whole recording status(struct BOOL),as long as ther is a channel running,it indicates that the overall state
#define DEV_STATE_WHOLE_ENCODING              0x0049           // Query whole encoding(struct BOOL),as long as ther is a channel running,it indicates that the overall state
#define DEV_STATE_DISK_RECORDE_TIME           0x004a           // Query disk record time(pBuf = DEV_DISK_RECORD_TIME*)
#define DEV_STATE_BURNER_DOOR                 0x004b           // whether have pop-up optical dirve(struct NET_DEVSTATE_BURNERDOOR)
#define DEV_STATE_GET_DATA_CHECK              0x004c           // get data validation process(struct NET_DEVSTATE_DATA_CHECK)
#define DEV_STATE_ALARM_IN_CHANNEL            0x004f           // Query alarm input channel information(struct NET_ALARM_IN_CHANNEL)
#define DEV_STATE_ALARM_CHN_COUNT             0x0050           // Query alarm channel number(struct NET_ALARM_CHANNEL_COUNT)
#define DEV_STATE_PTZ_VIEW_RANGE              0x0051           // Query PTZ view range status(struct DH_OUT_PTZ_VIEW_RANGE_STATUS)
#define DEV_STATE_DEV_CHN_COUNT               0x0052           // Query device channel information(struct NET_DEV_CHN_COUNT_INFO)
#define DEV_STATE_RTSP_URL                    0x0053           // Query RTSP URL list supported by device, struct DEV_RTSPURL_LIST
#define DEV_STATE_LIMIT_LOGIN_TIME            0x0054           // Query online overtime of device logging in and return a BYTE, UNIT:MIN ,0 means no limite and The non-zero positive integer means restrictions on the number of minutes
#define DEV_STATE_GET_COMM_COUNT              0x0055           // get com count (struct NET_GET_COMM_COUNT)
#define DEV_STATE_RECORDING_DETAIL            0x0056           // Query recording status detail information(pBuf = NET_RECORD_STATE_DETAIL*)
#define DEV_STATE_PTZ_PRESET_LIST             0x0057           // get state PTZ preset list (struct NET_PTZ_PRESET_LIST)
#define DEV_STATE_EXTERNAL_DEVICE             0x0058           // exteral device information (pBuf = NET_EXTERNAL_DEVICE*)
#define DEV_STATE_GET_UPGRADE_STATE           0x0059           // get device upgrade state(struct DHDEV_UPGRADE_STATE_INFO)
#define DEV_STATE_MULTIPLAYBACK_SPLIT_CAP     0x005a           // get mulipalyback split (struct NET_MULTIPLAYBACK_SPLIT_CAP )
#define DEV_STATE_BURN_SESSION_NUM            0x005b           // get burn session number(pBuf = int*)
#define DEV_STATE_PROTECTIVE_CAPSULE          0x005c           // Search protective capsule status(corresponding structure ALARM_PROTECTIVE_CAPSULE_INFO)
#define DEV_STATE_GET_DOORWORK_MODE           0x005d           // get access controlmode( corresponding NET_GET_DOORWORK_MODE)
#define DEV_STATE_PTZ_ZOOM_INFO               0x005e           // Query PTZ optical zoom value( corresponding to DH_OUT_PTZ_ZOOM_INFO )
#define DEV_STATE_POWER_STATE                 0x0152           // Query power state(struct DH_POWER_STATUS)
#define DEV_STATE_ALL_ALARM_CHANNELS_STATE    0x153      // Query alarm channel state(struct NET_CLIENT_ALARM_CHANNELS_STATE)
#define DEV_STATE_ALARMKEYBOARD_COUNT         0x0154           // Query alarm keyboard count connected on com(struct NET_ALARMKEYBOARD_COUNT)
#define DEV_STATE_EXALARMCHANNELS             0x0155           // Query mapping relationship of extension alarm module channel (struct NET_EXALARMCHANNELS)
#define DEV_STATE_GET_BYPASS                  0x0156           // Query channel bypass state(struct NET_DEVSTATE_GET_BYPASS)
#define DEV_STATE_ACTIVATEDDEFENCEAREA        0x0157           // get active sector information(struct NET_ACTIVATEDDEFENCEAREA)
#define DEV_STATE_DEV_RECORDSET               0x0158           // Query device recording information(struct NET_CTRL_RECORDSET_PARAM)
#define DEV_STATE_DOOR_STATE                  0x0159           // Query door access state(struct NET_DOOR_STATUS_INFO)
#define DEV_STATE_ANALOGALARM_CHANNELS        0x1560           // analog alarm input channel mapping (struct NET_ANALOGALARM_CHANNELS)
#define DEV_STATE_GET_SENSORLIST              0x1561           // Get device supported sensor list(corresponding NET_SENSOR_LIST)
#define DEV_STATE_ALARM_CHANNELS              0x1562           // Search switch alarm template channel mapping relation(corresponding structure  NET_ALARM_CHANNELS)

// If device su not support search extension alarm module channel, may use this function to search extension channel logic channel no. and use as local alarm channel use
#define DEV_STATE_GET_ALARM_SUBSYSTEM_ACTIVATESTATUS    0x1563     // Get current system enabling status( corresponding NET_GET_ALARM_SUBSYSTEM_ACTIVATE_STATUES)
#define DEV_STATE_AIRCONDITION_STATE          0x1564           // Get air conditioning status(corresponding to NET_GET_AIRCONDITION_STATE)
#define DEV_STATE_ALARMSUBSYSTEM_STATE        0x1565           // Get sub system status(corresponding to NET_ALARM_SUBSYSTEM_STATE)
#define DEV_STATE_ALARM_FAULT_STATE           0x1566           // Get failure status(corresponding to NET_ALARM_FAULT_STATE_INFO)
#define DEV_STATE_DEFENCE_STATE               0x1567           // Get zone status(corresponding to NET_DEFENCE_STATE_INFO, and bypass status change event, local alarm event, alarm signal event status description is different, cannot mix, for specific device use only)
#define DEV_STATE_CLUSTER_STATE               0x1568           // Get collection status(corresponding to NET_CLUSTER_STATE_INFO)
#define DEV_STATE_SCADA_POINT_LIST            0x1569           // Get spot chart path info(corresponding to NET_SCADA_POINT_LIST_INFO)
#define DEV_STATE_SCADA_INFO                  0x156a           // Get monitor spot info(corresponding to NET_SCADA_INFO)
#define DEV_STATE_SCADA_CAPS                  0x156b           // Get SCADA capacityset(corresponding to NET_SCADA_CAPS)
#define DEV_STATE_GET_CODEID_COUNT            0x156c           // Get successful code item number(corresponding  NET_GET_CODEID_COUNT)
#define DEV_STATE_GET_CODEID_LIST             0x156d           // Search code info(corresponding  NET_GET_CODEID_LIST)
#define DEV_STATE_ANALOGALARM_DATA            0x156e           // Search analog channel data(corresponding  NET_GET_ANALOGALARM_DATA)
#define DEV_STATE_VTP_CALLSTATE               0x156f           // Access the call state of the video phone (Corresponding to NET_GET_VTP_CALLSTATE)
#define DEV_STATE_SCADA_INFO_BY_ID            0x1570           // query point info by device id(corresponding to NET_SCADA_INFO_BY_ID)
#define DEV_STATE_SCADA_DEVICE_LIST           0x1571           // query scada device id(corresponding to NET_SCADA_DEVICE_LIST)
#define DEV_STATE_DEV_RECORDSET_EX            0x1572           // Search device record set info (with binary data) (Corresponding to NET_CTRL_RECORDSET_PARAM)
#define DEV_STATE_ACCESS_LOCK_VER             0x1573           // Get door locker software version (Corresponding to NET_ACCESS_LOCK_VER)
#define DEV_STATE_MONITORWALL_TVINFO          0x1574           // get monitorwall TV info(Corresponding to NET_CTRL_MONITORWALL_TVINFO)
#define DEV_STATE_GET_ALL_POS                 0x1575           // get all configuration of users's Pos devices (Corresponding to NET_POS_ALL_INFO)
#define DEV_STATE_GET_ROAD_LIST               0x1576           // get city and road code info(Corresponding to NET_ROAD_LIST_INFO)
#define DEV_STATE_GET_HEAT_MAP                0x1577           // get heatmap information(Corresponding to NET_QUERY_HEAT_MAP)
#define DEV_STATE_GET_WORK_STATE              0x1578           // get device work state (Corresponding to NET_QUERY_WORK_STATE)
#define DEV_STATE_GET_WIRESSLESS_STATE        0x1579           // get wireless device work state(Corresponding to NET_GET_WIRELESS_DEVICE_STATE)
#define DEV_STATE_GET_REDUNDANCE_POWER_INFO   0x157a      // get redundance power info(Corresponding to NET_GET_REDUNDANCE_POWER_INFO)
#define DEV_STATE_GET_ACCESSORY_STATUS        0x157b           // get accessory status(corresponding to NET_GET_ACCESSORY_STATUS)
#define DEV_STATE_GET_PTZ_TOURS	  	        0x157c		   // get ptz tours list(corresponding to NET_GET_PTZ_TOURS_INFO)
#define DEV_STATE_GET_DEVWIRELESSSIGNAL_LIST	0x157d		   // get wireless device signal strength(corresponding to NET_GET_DEVWIRELESSSIGNAL_LIST)


#endif // STATE_CONSTANTS_H
