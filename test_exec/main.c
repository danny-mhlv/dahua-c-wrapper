#include "../wrapper/dh-wrap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc < 5) {
        printf("Not enough arguments to connect!\n");
        return 11;
    }

    if (!DH_SDK_Init(NULL, 0)) {
        printf("Error initializing SDK!\n");
        return 1;
    }

    /**
     * Login into DVR/NVR
     */
    struct login_info info = {};
    strncpy(info.ip, argv[1], 64);
    info.port = atoi(argv[2]);
    strncpy(info.username, argv[3], 64);
    strncpy(info.password, argv[4], 64);

    long login_id = DH_Login(&info);
    if (!login_id) {
        printf("%x", DH_GetLastError());
        return 2;
    }

    struct dh_getcam_out* output = NULL;
    output = DH_GetCameras(login_id, 30);

    if (!output) {
        return 3;
    }

    /**
     * List all received cameras
     */
    if (output) {
        for (int i = 0; i < output->totalCamsReturned; i++) {
            printf("IP: %s\n", output->cameras[i].remoteDevInfo.ip);
            printf("Camera name: %s\n", output->cameras[i].remoteDevInfo.name);
            printf("Class: %s\n", output->cameras[i].remoteDevInfo.devClass);
            printf("Type: %s\n", output->cameras[i].remoteDevInfo.devType);
            printf("Type: %d\n", output->cameras[i].vidStreamType);
            printf("--------------------------------------------------------\n");
        }
    }

    /**
     * Login into camera
     */
    struct login_info camera_info = {};
    strncpy(camera_info.ip, output->cameras[0].remoteDevInfo.ip, 64);
    camera_info.port = output->cameras[0].remoteDevInfo.port;
    strncpy(camera_info.username, output->cameras[0].remoteDevInfo.user, 64);
    strncpy(camera_info.password, argv[4], 64);
    if (strlen(output->cameras[0].remoteDevInfo.pass)) {
        strncpy(camera_info.password, output->cameras[0].remoteDevInfo.pass, 64);
    }

    long cam_login_id = DH_Login(&camera_info);
    if (!cam_login_id) {
        printf("Error: %x\n", DH_GetLastError());
        return 2;
    }

    /**
     * Get device config
     */
    char* x = (char*)calloc(1024*100, sizeof(char));
    DH_GetConfigJSON(login_id, CFG_CMD_RTSP, -1, x, 1024 * 100 * sizeof(char));

    struct config_rtsp data = {};
    data.size = sizeof(struct config_rtsp);
    DH_ParseConfigJSON(CFG_CMD_RTSP, x, &data, data.size);

    DH_SDK_Cleanup();
    return 0;
}