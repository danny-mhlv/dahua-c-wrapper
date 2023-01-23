//
// Created by danny on 13.01.23.
//

#include "../library/library.h"

int main() {
    if (!SDK_init()) {
        printf("Error initializing SDK!\n");
        return 1;
    }

    long login_id = connect_param("admin", "12345678a", "192.168.1.250", 37777);
    if (!login_id) {
        printf("%x", get_error());
        return 2;
    }

    buffer buff;
    init_buff(&buff, 2 * 1024 * 1024);
    get_data(login_id,
             BOTH,
             &(dtstamp){ .year = 2023, .month = 1, .day = 17, .hour = 12, .min = 42, .sec = 0 },
             &(dtstamp){ .year = 2023, .month = 1, .day = 17, .hour = 12, .min = 43, .sec = 0 },
             &buff);

    disconnect(login_id);

    FILE* file = fopen("./myvid.dav", "wb");
    fwrite(buff.data, sizeof(byte), buff.size, file);
    fclose(file);


    SDK_cleanup();
    return 0;
}