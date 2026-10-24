#include "network_join_request_338fa0.h"

extern "C" {
    int func_00338350(void *direct_play);
    void *func_003382D0(void *direct_play, int unused);
    void *func_11B170(void *destination, const void *source, int size);
    int func_00335A20(void);
    void *func_117AF8(void *destination, const void *source, int size);
    int func_003383B0(void *direct_play, int a1, int a2, const void *buffer, int a4);
}

extern "C" int func_00338FA0(void *direct_play, void **player_record,
                             const NetworkJoinSession *session) {
    char *dp = static_cast<char *>(direct_play);
    char *record;
    char buffer[1024];

    *reinterpret_cast<int *>(dp) = func_00338350(direct_play);
    *reinterpret_cast<int *>(player_record) = *reinterpret_cast<int *>(dp);
    record = static_cast<char *>(func_003382D0(direct_play, 0));
    func_11B170(record + 24, session->player_name, 16);
    func_11B170(record + 40, session->session_name, 32);
    *reinterpret_cast<int *>(record + 4) = *reinterpret_cast<int *>(dp);
    *reinterpret_cast<int *>(record) = func_00335A20();

    if (*reinterpret_cast<int *>(dp + 1312) == 0) {
        int *msg = reinterpret_cast<int *>(buffer);
        msg[0] = 3;
        msg[1] = 1;
        msg[2] = *reinterpret_cast<int *>(dp);
        *reinterpret_cast<int *>(dp + 1136) += 1;
        msg[3] = *reinterpret_cast<int *>(dp + 1136);
        func_117AF8(msg + 6, session, 16);
        char *names = reinterpret_cast<char *>(msg + 12);
        func_11B170(names, session->player_name, 16);
        names[15] = 0;
        func_11B170(names + 16, session->session_name, 32);
        names[47] = 0;
        *reinterpret_cast<int *>(names + 48) = *reinterpret_cast<int *>(record);
        func_003383B0(direct_play, 0, 0, buffer, 100);
    }
    return 0;
}
