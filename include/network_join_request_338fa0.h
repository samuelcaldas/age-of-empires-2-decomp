#ifndef NETWORK_JOIN_REQUEST_338FA0_H
#define NETWORK_JOIN_REQUEST_338FA0_H

struct NetworkJoinSession {
    int reserved[2];
    const char *player_name;
    const char *session_name;
};

extern "C" {
    int func_00338FA0(void **player_id, void **player_record,
                      const NetworkJoinSession *session);
}

#endif
