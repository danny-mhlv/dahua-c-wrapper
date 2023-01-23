#include "callbacks.h"

void cb_default_download_pos(long handle,
                             unsigned int total_sz,
                             unsigned int download_sz,
                             int index,
                             struct recfile_info file_info,
                             long loading) {
    printf("Progress: %d Kb out of %d Kb", download_sz, total_sz);
    if (download_sz == -1) {
        *((bool*)loading) = false;
    }
}

int cb_default_download_buff(long handle,
                             unsigned int data_type,
                             unsigned char* buff,
                             unsigned int buff_sz,
                             long data_buff) {
    if (buff != NULL && buff_sz > 0) {
        switch (data_type) {
            case 0:
                append_buff((buffer*)data_buff, buff, buff_sz);
                printf("Buff appended by %d bytes", buff_sz);
                break;
                //...    // #TODO cover other types of streams
        }
    }

    return false;
}