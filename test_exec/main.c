#include "../library/library.h"
#include "stdio.h"

int main() {
    if (!SDK_init()) {
        printf("Error initializing SDK!\n");
        return 1;
    }

    long login_id = connect_p("admin", "12345678a", "192.168.1.250", 37777);
    if (!login_id) {
        printf("%x", get_error());
        return 2;
    }

    w_buffer_t buff;
    init_buff(&buff, 2 * 1024 * 1024);
    get_data(login_id,
             BOTH,
             &(w_datetime_t){ .year = 2023, .month = 1, .day = 18, .hour = 12, .minute = 42, .sec = 0 },
             &(w_datetime_t){ .year = 2023, .month = 1, .day = 18, .hour = 12, .minute = 43, .sec = 0 },
             &buff);

    disconnect(login_id);

    FILE* file = fopen("/home/danny/clibgo/test_exec/myvid.dav", "wb");
    if (!file) {
        printf("Failed to open file!\n");
        return 3;
    }

    fwrite(buff.data, sizeof(buff.data[0]), buff.pos, file);
    fclose(file);

    SDK_cleanup();
    return 0;
}