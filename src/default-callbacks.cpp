#include "../include/callbacks.h"

#include <fstream>

void default_cb_download_pos(long handle, unsigned int total_size, unsigned int download_size, int index,
                             struct record_info file_info, long isLoading) {
    if (download_size == -1) {
        *((bool*)isLoading) = false;
    }
}

void default_cb_download_record_pos(long handle, unsigned int total_size, unsigned int download_size, long isLoading) {
    if (download_size == -1) {
        *((bool*)isLoading) = false;
    }
}

int default_cb_download_data(long handle, unsigned int data_type, unsigned char* buff, unsigned int buff_size,
                             long file_path) {
    std::ofstream file((char*)file_path, std::ios::binary | std::ios::app);
    bool gotData = false;

    if (buff != nullptr && buff_size > 0) {
        switch (data_type) {
            case 0:
                file.write(reinterpret_cast<char*>(buff), buff_size);
                gotData = true;
                break;
        }
    }

    file.close();
    return int(gotData);
}

