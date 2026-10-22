#include "network_join_request_338fa0.h"

extern "C" {
    int func_00338350(void *direct_play, void *output);
    int func_003382D0(void *direct_play, int unused);
    void func_0011B170(void *destination, const void *source, int size);
    int func_00335A20(int player_id);
    void *func_00117AF8(void *destination, const void *source, int size);
    int func_003383B0(void *direct_play, int first, int second,
                      const void *entry, int fifth_argument);
}

struct NetworkPlayerRecord {
    int identity;
    int network_identity;
    unsigned char unused[16];
    char player_name[16];
    char session_name[32];
};

struct NetworkDirectPlayState {
    int player_id;
    unsigned char before_count[1132];
    int player_count;
    unsigned char before_host_flag[172];
    int is_host;
};

struct NetworkJoinAnnouncement {
    int type;
    int reserved;
    int player_id;
    int player_count;
    unsigned char unused_before_copy[8];
    char player_copy[16];
    unsigned char unused_before_name[8];
    char player_name[16];
    char session_name[32];
    int identity;
    unsigned char trailing[12];
};

union NetworkJoinStorage {
    unsigned char bytes[1024];
    NetworkJoinAnnouncement announcement;
};

extern "C" int func_00338FA0(void *direct_play, void **player_record,
                             const NetworkJoinSession *session) {
    NetworkDirectPlayState *state = (NetworkDirectPlayState *)direct_play;
    NetworkPlayerRecord *record;
    NetworkJoinStorage storage;
    NetworkJoinAnnouncement *announcement = &storage.announcement;
    int identity;

    state->player_id = func_00338350(direct_play, player_record);
    record = (NetworkPlayerRecord *)func_003382D0(direct_play, 0);
    *player_record = record;
    func_0011B170(record->player_name, session->player_name, 16);
    func_0011B170(record->session_name, session->session_name, 32);
    identity = func_00335A20(state->player_id);
    record->network_identity = identity;
    record->identity = identity;
    if (state->is_host != 1) {
        state->player_count += 1;
        announcement->type = 3;
        announcement->reserved = 1;
        announcement->player_id = state->player_id;
        announcement->player_count = state->player_count;
        func_00117AF8(announcement->player_copy, session, 16);
        func_0011B170(announcement->player_name, session->player_name, 16);
        announcement->player_name[15] = 0;
        func_0011B170(announcement->session_name, session->session_name, 32);
        announcement->session_name[31] = 0;
        announcement->identity = record->identity;
        func_003383B0(direct_play, 0, 0, announcement, 100);
    }
    return 0;
}
