#ifndef COMMON_STRUCTS_H
#define COMMON_STRUCTS_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Represents date-time point
 * @dahua_name NET_TIME
 */
struct time_stamp {
    unsigned int    year;
    unsigned int    month;
    unsigned int    day;
    unsigned int    hour;
    unsigned int    minute;
    unsigned int    second;
};

/**
 * Represents bare-minimum data for successful login
 */
struct login_info {
    char ip[64];
    int port;
    char username[64];
    char password[64];
};

#ifdef __cplusplus
}
#endif

#endif // COMMON_STRUCTS_H
