#include "mt-funcs.h"

void* th_login(void* login_info) {
    const login_info_t* info = (login_info_t*)login_info;

    // Prepare DH structs
    NET_OUT_LOGIN_WITH_HIGHLEVEL_SECURITY out;
    memset(&out, 0, sizeof(out));
    out.dwSize = sizeof(out);
    NET_IN_LOGIN_WITH_HIGHLEVEL_SECURITY in;
    memset(&in, 0, sizeof(in));
    in.dwSize = sizeof(in);

    // Set data
    in.nPort = info->port;
    strcpy(in.szIP, info->ip);
    strcpy(in.szUserName, info->username);
    strcpy(in.szPassword, info->password);

    CLIENT_LoginWithHighLevelSecurity(&in, &out);
}