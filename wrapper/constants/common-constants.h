#ifndef COMMON_CONSTANTS_H
#define COMMON_CONSTANTS_H

// Macros for numerous "reserved[]" fields in structures
#define CONCAT(x, y) x ## y
#define EXPAND(x, y) CONCAT(x, y)
#define RESERVED EXPAND(reserved, __LINE__)

#define DH_DEVICE_ID_LEN 128
#define DH_DEVICE_NAME_LEN 64

#define DH_USER_NAME_LEN 8
#define DH_USER_PASS_LEN 8
#define DH_USER_NAME_LEN_EX 32
#define DH_USER_PASS_LEN_EX 32

#define DH_DEVICE_TYPE_LEN 32

#define DH_SERIAL_LEN 48

#define DH_CARD_INFO_LEN 256

#define DH_IPV4_LEN 16
#define DH_IPV6_LEN 40

#define DH_MAX_URL_LEN 128
#define DH_MAX_URL_NUM 8
#define DH_MAX_OPTIONAL_URL 8

#define DH_MAX_SERIAL_NUM_LEN 48

#define DH_MAX_PATH_LEN 260

#endif // COMMON_CONSTANTS_H
