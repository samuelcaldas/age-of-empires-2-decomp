#include "network_message_handler_3385c0.h"

extern "C" {
    extern const char D_004D1F18[];
    extern const char D_004D1F10[];
    int func_117A64(const char *left, const char *right, int size);
    char *func_11ABBC(char *destination, const char *source);
    void *func_117AF8(void *destination, const void *source, int size);
    void *func_11B170(void *destination, const void *source, int size);
    void *func_117CAC(void *destination, int value, int size);
    int func_00337840(const void *buffer, int size);
    int func_00338470(void *object, void *message, int size);
    void *func_003382D0(void *object, int unused);
    void *func_00338310(void *object, int player_id);
    void func_00338190(void *object, void *player);
}

int func_003385C0(void *object, void *message, int size, int flag) {
    char *base = static_cast<char *>(object);
    char *packet = static_cast<char *>(message);
    char *player;
    char *name;
    char *body;
    char *slot;
    char *record;
    int index;

    if (*reinterpret_cast<int *>(base + 1312) != 0 &&
        *reinterpret_cast<int *>(packet) == 0 &&
        *reinterpret_cast<int *>(packet + 8) == 0 &&
        *reinterpret_cast<int *>(packet + 12) == 0) {
        if (func_117A64(packet + 16, D_004D1F18, 7) == 0) {
            func_11ABBC(base + 3388, D_004D1F18);
            func_117AF8(base + 3396, base + 1092, 216);
            func_00337840(base + 3388, 224);
        }
        if (func_117A64(packet + 16, D_004D1F10, 6) == 0) {
            char records[896];
            slot = base + 4;
            record = records;
            for (index = 0; index < 8; ++index, slot += 136, record += 112) {
                func_117AF8(record, slot, 112);
            }
            func_11ABBC(base + 3388, D_004D1F10);
            func_117AF8(base + 3396, record - 896, 896);
            func_00337840(base + 3388, 456);
        }
        return 1;
    }

    if (*reinterpret_cast<int *>(packet + 4) != 0) {
        func_00338470(object, message, size + 16);
        return 1;
    }

    body = packet + 16;
    switch (*reinterpret_cast<int *>(body)) {
    case 3: {
        if (*reinterpret_cast<int *>(base + 1312) == 0) break;
        player = static_cast<char *>(func_003382D0(object, 0));
        if (player == 0) return 0;
        char *short_name = body + 48;
        name = short_name + 16;
        *reinterpret_cast<void **>(player + 16) = player + 24;
        *reinterpret_cast<void **>(player + 20) = player + 40;
        func_11B170(player + 24, short_name, 16);
        func_11B170(player + 40, name, 32);
        *reinterpret_cast<void **>(body + 32) = player + 24;
        *reinterpret_cast<void **>(body + 36) = player + 40;
        *reinterpret_cast<int *>(player + 4) = *reinterpret_cast<int *>(body + 8);
        *reinterpret_cast<int *>(player) = *reinterpret_cast<int *>(name + 32);
        func_00338470(object, message, size + 16);
        break;
    }
    case 5: {
        player = static_cast<char *>(func_00338310(object, *reinterpret_cast<int *>(body + 8)));
        if (!player) return 0;
        func_00338190(object, player);
        func_117CAC(player, 0, 136);
        func_00338470(object, message, size + 16);
        break;
    }
    case 257:
        func_00338470(object, message, size + 16);
        break;
    case 49:
        func_00338470(object, message, size + 16);
        break;
    case 259: {
        player = static_cast<char *>(func_00338310(object, *reinterpret_cast<int *>(body + 8)));
        if (!player) return 0;
        name = body + 28;
        func_11B170(player + 24, name, 16);
        func_11B170(player + 40, name + 16, 32);
        *reinterpret_cast<void **>(body + 20) = player + 24;
        *reinterpret_cast<void **>(body + 24) = player + 40;
        func_00338470(object, message, size + 16);
        break;
    }
    case 263: case 260: case 264: case 258: case 33: case 7: case 261: case 265:
    default:
        return 1;
    }
    return 1;
}
