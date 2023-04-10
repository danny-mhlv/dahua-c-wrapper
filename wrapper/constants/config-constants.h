#ifndef CONFIG_CONSTANTS_H
#define CONFIG_CONSTANTS_H

#define DEV_CONFIG_DEVICE                   0x0001        // Device property setup
#define DEV_CONFIG_NET                      0x0002        // Network setup
#define DEV_CONFIG_CHANNEL                  0x0003        // Video channel setup
#define DEV_CONFIG_PREVIEW                  0x0004        // Preview parameter setup
#define DEV_CONFIG_RECORD                   0x0005        // Record setup
#define DEV_CONFIG_COMM                     0x0006        // COM property setup
#define DEV_CONFIG_ALARM                    0x0007        // Alarm property setup
#define DEV_CONFIG_TIME                     0x0008        // DVR time setup
#define DEV_CONFIG_TALK                     0x0009        // Audio talk parameter setup
#define DEV_CONFIG_AUTOMT                   0x000A        // Auto matrix setup
#define DEV_CONFIG_VEDIO_MARTIX             0x000B        // Local matrix control strategy setup
#define DEV_CONFIG_MULTI_DDNS               0x000C        //  Multiple DDNS setup
#define DEV_CONFIG_SNAP                     0x000D        // Snapshot corresponding setup
#define DEV_CONFIG_WEB_URL                  0x000E        // HTTP path setup
#define DEV_CONFIG_FTP_PROTO                0x000F        // FTP upload setup
#define DEV_CONFIG_INTERVIDEO               0x0010        // Plaform embedded setup. Now the channel parameter represents the platform type.
// channel=4:Bell alcatel;channel=10:ZTE Netview;channel=11:U CNC  channel = 51 AMP
#define DEV_CONFIG_VIDEO_COVER              0x0011        // Privacy mask setup
#define DEV_CONFIG_TRANS_STRATEGY           0x0012        // Transmission strategy. Video quality\Fluency
#define DEV_CONFIG_DOWNLOAD_STRATEGY        0x0013        //  Record download strategy setup:high-speed\general download
#define DEV_CONFIG_WATERMAKE                0x0014        // Video watermark setup
#define DEV_CONFIG_WLAN                     0x0015        // Wireless network setup
#define DEV_CONFIG_WLAN_DEVICE              0x0016        // Search wireless device setup
#define DEV_CONFIG_REGISTER                 0x0017        // Auto register parameter setup
#define DEV_CONFIG_CAMERA                   0x0018        // Camera property setup
#define DEV_CONFIG_INFRARED                 0x0019        // IR alarm setup
#define DEV_CONFIG_SNIFFER                  0x001A        // Sniffer setup
#define DEV_CONFIG_MAIL                     0x001B        // Mail setup
#define DEV_CONFIG_DNS                      0x001C        // DNS setup
#define DEV_CONFIG_NTP                      0x001D        // NTP setup
#define DEV_CONFIG_AUDIO_DETECT             0x001E        // Audio detection setup
#define DEV_CONFIG_STORAGE_STATION          0x001F        // Storage position setup
#define DEV_CONFIG_PTZ_OPT                  0x0020        // PTZ operation property(It is invalid now. Please use CLIENT_GetPtzOptAttr to get PTZ operation property.)
#define DEV_CONFIG_DST                      0x0021        // Daylight Saving Time (DST)setup
#define DEV_CONFIG_ALARM_CENTER             0x0022        // Alarm center setup
#define DEV_CONFIG_VIDEO_OSD                0x0023        // VIdeo OSD setup
#define DEV_CONFIG_CDMAGPRS                 0x0024        // CDMA\GPRS configuration
#define DEV_CONFIG_IPFILTER                 0x0025        // IP Filter configuration
#define DEV_CONFIG_TALK_ENCODE              0x0026        // Talk encode configuration
#define DEV_CONFIG_RECORD_PACKET            0x0027        // The length of the video package configuration
#define DEV_CONFIG_MMS                      0x0028        // SMS MMS configuration
#define DEV_CONFIG_SMSACTIVATION            0x0029        // SMS to activate the wireless connection configuration
#define DEV_CONFIG_DIALINACTIVATION         0x002A        // Dial-up activation of a wireless connection configuration
#define DEV_CONFIG_SNIFFER_EX               0x0030        // Capture network configuration
#define DEV_CONFIG_DOWNLOAD_RATE            0x0031        // Download speed limit
#define DEV_CONFIG_PANORAMA_SWITCH          0x0032        // Panorama switch alarm configuration
#define DEV_CONFIG_LOST_FOCUS               0x0033        // Lose focus alarm configuration
#define DEV_CONFIG_ALARM_DECODE             0x0034        // Alarm decoder configuration
#define DEV_CONFIG_VIDEOOUT                 0x0035        // Video output configuration
#define DEV_CONFIG_POINT                    0x0036        // Preset enable configuration
#define DEV_CONFIG_IP_COLLISION             0x0037        // IP conflication configurationIp
#define DEV_CONFIG_OSD_ENABLE               0x0038        // OSD overlay enable configuration
#define DEV_CONFIG_LOCALALARM               0x0039        // Local alarm configuration(Structure DH_ALARMIN_EX)
#define DEV_CONFIG_NETALARM                 0x003A        // Network alarm configuration(Structure DH_ALARMIN_EX)
#define DEV_CONFIG_MOTIONALARM              0x003B        // Motion detection configuration(Structure DH_MOTION_DETECT_EX)
#define DEV_CONFIG_VIDEOLOSTALARM           0x003C        // Video loss configuration(Structure DH_VIDEO_LOST_EX)
#define DEV_CONFIG_BLINDALARM               0x003D        // Camera masking configuration(Structure DH_BLIND_EX)
#define DEV_CONFIG_DISKALARM                0x003E        // HDD alarm configuration(Structure DH_DISK_ALARM_EX)
#define DEV_CONFIG_NETBROKENALARM           0x003F        // Network disconnection alarm configuration(Structure DH_NETBROKEN_ALARM_EX)
#define DEV_CONFIG_ENCODER                  0x0040        // Digital channel info of front encoders(Hybrid DVR use,Structure DEV_ENCODER)
#define DEV_CONFIG_TV_ADJUST                0x0041        // TV adjust configuration(Now the channel parameter represents the TV numble(from 0), Structure DHDEV_TVADJUST)
#define DEV_CONFIG_ABOUT_VEHICLE            0x0042        // about vehicle configuration
#define DEV_CONFIG_ATM_OVERLAY_ABILITY      0x0043        // ATM ability information
#define DEV_CONFIG_ATM_OVERLAY              0x0044        // ATM overlay configuration
#define DEV_CONFIG_DECODER_TOUR             0x0045        // Decoder tour configuration
#define DEV_CONFIG_SIP                      0x0046        // SIP configuration
#define DEV_CONFIG_VICHILE_WIFI_AP          0x0047        // wifi ap configuration
#define DEV_CONFIG_STATICALARM              0x0048        // Static
#define DEV_CONFIG_DECODE_POLICY            0x0049        // decode policy configuration(Structure DHDEV_DECODEPOLICY,channel start with 0)
#define DEV_CONFIG_MACHINE                  0x004A        // Device relative config (Structure DHDEV_MACHINE)
#define DEV_CONFIG_MAC_COLLISION            0x004B        // MACconflication configuration(Structure ALARM_MAC_COLLISION)
#define DEV_CONFIG_RTSP                     0x004C        // RTSP configuration(structure DHDEV_RTSP)
#define DEV_CONFIG_232_COM_CARD             0x004E        // 232 com card signal event configuration(structure COM_CARD_SIGNAL_LINK)
#define DEV_CONFIG_485_COM_CARD             0x004F        // 485 com card signal event configuration(structure COM_CARD_SIGNAL_LINK)
#define DEV_CONFIG_FTP_PROTO_EX             0x0050        // extend FTP upload setup(Structure DHDEV_FTP_PROTO_EX)
#define DEV_CONFIG_SYSLOG_REMOTE_SERVER     0x0051        // SYSLOG remote server config (Structure DHDEV_SYSLOG_REMOTE_SERVER)
#define DEV_CONFIG_COMM_EX                  0x0052        // Extended com configuration(structure DHDEV_COMM_EX)
#define DEV_CONFIG_NETCARD                  0x0053        // net card configuration(structure DHDEV_NETCARD)
#define DEV_CONFIG_BACKUP_VIDEO_FORMAT      0x0054        // Video backup format(structure DHDEV_BACKUP_VIDEO_FORMAT)
#define DEV_CONFIG_STREAM_ENCRYPT           0x0055        // stream encrypt configuration(structure DHEDV_STREAM_ENCRYPT)
#define DEV_CONFIG_IPFILTER_EX              0x0056        // IP filter extended configuration(structure DHDEV_IPIFILTER_EX)
#define DEV_CONFIG_CUSTOM                   0x0057        // custom configuration(structure DHDEV_CUSTOM)
#define DEV_CONFIG_WLAN_DEVICE_EX           0x0058        // Search wireless device extended setup(structure DHDEV_WLAN_DEVICE_LIST_EX)
#define DEV_CONFIG_ACC_POWEROFF             0x0059        // ACC power off configuration(structure DHDEV_ACC_POWEROFF)
#define DEV_CONFIG_EXPLOSION_PROOF          0x005a        // explosion proof alarm configuration(structure DHDEV_EXPLOSION_PROOF)
#define DEV_CONFIG_NET_EX                   0x005b        // Network extended setup(struct DHDEV_NET_EX)
#define DEV_CONFIG_LIGHTCONTROL             0x005c        // light control config(struct DHDEV_LIGHTCONTROL)
#define DEV_CONFIG_3GFLOW                   0x005d        // 3G flow info config(struct DHDEV_3GFLOW_INFO)
#define DEV_CONFIG_IPV6                     0x005e        // IPv6 config(struct DHDEV_IPV6)
#define DEV_CONFIG_SNMP                     0x005f        // Snmp config(struct DHDEV_NET_SNMP)
#define DEV_CONFIG_SNAP_CONTROL             0x0060        // snap control config(struct DHDEV_SNAP_CONTROL)
#define DEV_CONFIG_GPS_MODE                 0x0061        // GPS mode config(struct DHDEV_GPS_MODE)
#define DEV_CONFIG_SNAP_UPLOAD              0x0062        // Snap upload config(struct DHDEV_SNAP_UPLOAD)
#define DEV_CONFIG_SPEED_LIMIT              0x0063        // Speed limit config(struct DHDEV_SPEED_LIMIT)
#define DEV_CONFIG_ISCSI                    0x0064        // iSCSI config(struct DHDEV_ISCSI), need reboot
#define DEV_CONFIG_WIRELESS_ROUTING         0x0065        // wifi config(struc DHDEV_WIRELESS_ROUTING)
#define DEV_CONFIG_ENCLOSURE                0x0066        // enclosure config(stuct DHDEV_ENCLOSURE)
#define DEV_CONFIG_ENCLOSURE_VERSION        0x0067        // enclosure version config(struct DHDEV_ENCLOSURE_VERSION)
#define DEV_CONFIG_RIAD_EVENT               0x0068        // Raid event config(struct DHDEV_RAID_EVENT)
#define DEV_CONFIG_FIRE_ALARM               0x0069        // fire alarm config(struct DHDEV_FIRE_ALARM)
#define DEV_CONFIG_LOCALALARM_NAME          0x006a        // local alarm name config(string like "Name1&&name2&&name3...")
#define DEV_CONFIG_URGENCY_RECORD           0x0070        // urgency storage config(struct DHDEV_URGENCY_RECORD)
#define DEV_CONFIG_ELEVATOR_ATTRI           0x0071        // elevator parameter config(struct DHDEV_ELEVATOR_ATTRI)
#define DEV_CONFIG_ATM_OVERLAY_EX           0x0072        // TM overlay function. For latest ATM series product only.  Support devices of 32-channel or higher.( struct DHDEV_ATM_OVERLAY_CONFIG_EX)
#define DEV_CONFIG_MACFILTER                0x0073        // MAC filter config(struct DHDEV_MACFILTER)
#define DEV_CONFIG_MACIPFILTER              0x0074        // MAC,IP filter config(need ip,mac one to one corresponding)(struct DHDEV_MACIPFILTER)
#define DEV_CONFIG_STREAM_ENCRYPT_TIME      0x0075        // stream encrypt(encryot plan)(struct DHEDV_STREAM_ENCRYPT)
#define DEV_CONFIG_LIMIT_BIT_RATE           0x0076        // limit bit rate config(struct DHDEV_LIMIT_BIT_RATE)
#define DEV_CONFIG_SNAP_EX                  0x0077        // snap extern config(struct DHDEV_SNAP_EX)
#define DEV_CONFIG_DECODER_URL              0x0078        // decoder url config(struct DHDEV_DECODER_URL)
#define DEV_CONFIG_TOUR_ENABLE              0x0079        // toyr enable config(struct DHDEV_TOUR_ENABLE)
#define DEV_CONFIG_VICHILE_WIFI_AP_EX       0x007a        // wifi ap extern config(struct DHDEV_VEHICLE_WIFI_AP_EX)
#define DEV_CONFIG_ENCODER_EX               0x007b        // encoder extern config(struct DEV_ENCODER_EX)

// Here are some ITC_HWS000 configurations 
#define DEV_CONFIG_ITC_HWS000_RA            0x007c      // ITC_HWS000 RA config(corresponding int value)
#define DEV_CONFIG_ITC_HWS000_HS            0x007d      // ITC_HWS000 HS config(corresponding int value)
#define DEV_CONFIG_ITC_HWS000_LS            0x007e      // ITC_HWS000 LS config(corresponding int value)
#define DEV_CONFIG_ITC_HWS000_FL            0x007f      // ITC_HWS000 FL config(corresponding int value)
#define DEV_CONFIG_ITC_HWS000_OC            0x0080      // ITC_HWS000 OC config(corresponding int value)
#define DEV_CONFIG_ITC_HWS000_LC            0x0081      // ITC_HWS000 LC config(corresponding int value)
#define DEV_CONFIG_ITC_HWS000_AC            0x0082      // ITC_HWS000 AC config(corresponding int value)
#define DEV_CONFIG_ITC_HWS000_FC            0x0083      // ITC_HWS000 FC config(corresponding int value)
#define DEV_CONFIG_ITC_HWS000_ALL           0x0084      // Query all the values (corresponding struct DEV_ITC_HWS000_ALL)
#define DEV_CONFIG_ITC_HWS000_CLEAR_COUNT   0x0085      // Clear the counts(OC,LC,AC,FC corresponding int value)

#define DEV_CONFIG_IPV4					  	0x0086		// IPV4 config(corresponding struct  DEV_IPV4)
#define DEV_CONFIG_ENCODER_EX2				0x0087		// encoder extern config(struct DEV_ENCODER_EX2)
#define DEV_CONFIG_WLAN_DEVICE_EX2			0x0088        // Search wireless device extended setup(structure DHDEV_WLAN_DEVICE_LIST_EX2)

#define DEV_CONFIG_USER_END                 1000
#define DEV_CONFIG_ITC_HWS000_ITEM_NUM      8           // the max count of ITC_HWS000's config item

#endif // CONFIG_CONSTANTS_H
