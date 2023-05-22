#ifndef COMMON_STRUCTS_H
#define COMMON_STRUCTS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../constants/common-constants.h"
#include "../enums.h"

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

///@brief card no. record info

/**
 * Card info
 * @dahua_name NET_RECORD_CARD_INFO
 * @associated_structure find_file_in
 * @param size - Struct size
 * @param type - Type. Card (0), field (1)
 * @param cardNumber - Card number
 * @param tradeType - Transaction type
 * @param amount - Transaction amount. If string is null - means no-limit amount
 * @param error - Error code. All errors (0), retain cash (1), retain card (2)
 * @param fieldCount - ?
 * @param fields - ?
 * @param change - Change
 */
struct card_info {
    unsigned int                size;
    int                         type;
    char                        cardNumber[DH_MAX_CARD_INFO_LEN];
    enum atm_transaction_type   tradeType;
    char                        amount[64];
    int                         error;
    int                         fieldCount;    				// domain quantity, by domain search is valid
    char                        fields[MAX_CARD_RECORD_FIELD_NUM][256];   // domain info, by domain search is valid
    char				        change[32];
};

#ifdef __cplusplus
}
#endif

#endif // COMMON_STRUCTS_H
