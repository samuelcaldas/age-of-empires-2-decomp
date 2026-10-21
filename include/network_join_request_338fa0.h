#ifndef NETWORK_JOIN_REQUEST_338FA0_H
#define NETWORK_JOIN_REQUEST_338FA0_H

struct NetworkJoinSession {
    int reserved[2];
    const char *player_name;
    const char *session_name;
};

extern "C" {
    /**
     * Create a local player record and announce it when this peer is not host.
     * @param direct_play DirectPlay state object.
     * @param player_record Receives the created player record.
     * @param session Supplies the player and session names.
     * @return Zero after setup.
     */
    int func_00338FA0(void *direct_play, void **player_record,
                      const NetworkJoinSession *session);
}

#endif
