#include <cassert>
#include <cstddef>
#include <cstring>
#include "network_join_request_338fa0.h"

enum { CALL_ALLOC_ID = 1, CALL_CREATE_RECORD, CALL_COPY, CALL_IDENTITY, CALL_SEND };

struct DirectPlay {
    unsigned char prefix[1136];
    int player_count;
    unsigned char gap[172];
    int is_host;
};

static DirectPlay direct_play;
static int call_order[16];
static int call_count;
static int next_id;
static int copy_count;
static int send_size;
static int send_player_count;
static char record_buffer[80];
static void *created_record;

extern "C" {
    int func_00338350(void *owner, void *unused) {
        assert(owner == &direct_play);
        (void)unused;
        call_order[call_count++] = CALL_ALLOC_ID;
        return next_id;
    }
    int func_003382D0(void *owner, int unused) {
        assert(owner == &direct_play);
        assert(unused == 0);
        call_order[call_count++] = CALL_CREATE_RECORD;
        return reinterpret_cast<int>(created_record);
    }
    void func_0011B170(void *destination, const void *source, int size) {
        std::memcpy(destination, source, size);
        ++copy_count;
    }
    int func_00335A20(void *owner) {
        assert(owner == &direct_play);
        call_order[call_count++] = CALL_IDENTITY;
        return 0x12345678;
    }
    void *func_00117AF8(void *destination, const void *source, int size) {
        return std::memcpy(destination, source, size);
    }
    int func_003383B0(void *owner, int first, int second, const void *entry, int timeout) {
        assert(owner == &direct_play);
        assert(first == 0 && second == 0);
        const unsigned char *bytes = static_cast<const unsigned char *>(entry);
        send_player_count = *reinterpret_cast<const int *>(bytes + 12);
        send_size = timeout;
        call_order[call_count++] = CALL_SEND;
        return 0;
    }
}

static void reset() {
    std::memset(&direct_play, 0, sizeof(direct_play));
    std::memset(call_order, 0, sizeof(call_order));
    call_count = 0;
    copy_count = 0;
    send_size = 0;
    send_player_count = 0;
    next_id = 42;
}

int main() {
    assert(offsetof(NetworkJoinSession, player_name) == 8);
    assert(offsetof(NetworkJoinSession, session_name) == 12);
    assert(offsetof(DirectPlay, is_host) == 1312);
    assert(offsetof(DirectPlay, player_count) == 1136);
    reset();
    char player_name[16] = "Player";
    char session_name[32] = "Session";
    NetworkJoinSession session = {{0, 0}, player_name, session_name};
    void *player_id = 0;
    void *record = 0;
    created_record = record_buffer;
    assert(func_00338FA0(&player_id, &record, &session) == 0);
    assert(player_id == reinterpret_cast<void *>(42));
    assert(record == created_record);
    assert(call_count == 4);
    assert(call_order[0] == CALL_ALLOC_ID);
    assert(call_order[1] == CALL_CREATE_RECORD);
    assert(call_order[2] == CALL_IDENTITY);
    assert(call_order[3] == CALL_SEND);
    assert(copy_count == 4);
    assert(send_size == 100);
    assert(send_player_count == 1);
    assert(direct_play.player_count == 1);
    assert(std::strcmp(static_cast<char *>(created_record) + 24, "Player") == 0);
    assert(std::strcmp(static_cast<char *>(created_record) + 40, "Session") == 0);
    assert(*reinterpret_cast<int *>(static_cast<char *>(created_record) + 4) == 0x12345678);

    reset();
    direct_play.is_host = 1;
    player_id = 0;
    record = 0;
    assert(func_00338FA0(&player_id, &record, &session) == 0);
    assert(call_count == 3);
    assert(call_order[0] == CALL_ALLOC_ID);
    assert(call_order[1] == CALL_CREATE_RECORD);
    assert(call_order[2] == CALL_IDENTITY);
    assert(copy_count == 2);
    assert(direct_play.player_count == 0);
    return 0;
}
