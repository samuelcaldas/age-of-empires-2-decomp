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
    if (*reinterpret_cast<int *>(base + 1312) != 0 &&
        *reinterpret_cast<int *>(packet) == 0 &&
        *reinterpret_cast<int *>(packet + 8) == 0 &&
        *reinterpret_cast<int *>(packet + 12) == 0) {
        if (func_117A64(packet + 16, D_004D1F18, 7) == 0) {
            func_11ABBC(base + 3388, D_004D1F18);
            func_117AF8(base + 3396, base + 1092, 216);
            func_00337840(base + 3388, 224);
            return 1;
        }
        if (func_117A64(packet + 16, D_004D1F10, 6) == 0) {
            char records[896];
            char *slot = base + 4;
            char *record = records;
            for (int index = 0; index < 8; ++index) {
                func_117AF8(record, slot, 112);
                slot += 136;
                record += 112;
            }
            func_11ABBC(base + 3388, D_004D1F10);
            func_117AF8(base + 3396, records, 896);
            func_00337840(base + 3388, 456);
            return 1;
        }
        return 1;
    }
    if (*reinterpret_cast<int *>(packet + 4) != 0) {
        func_00338470(object, message, size + 16);
        return 1;
    }
    int type = *reinterpret_cast<int *>(packet + 16);
    if (type == 265 || type == 7 || type == 33 || type == 258 ||
        type == 264 || type == 260 || type == 263) {
        return 1;
    }
    if (type == 261) {
        return 1;
    }
    if (type == 257 || type == 49) {
        func_00338470(object, message, size + 16);
        return 1;
    }
    if (type == 3) {
        if (*reinterpret_cast<int *>(base + 1312) == 0) {
            return 1;
        }
        char *player = static_cast<char *>(func_003382D0(object, 0));
        if (player == 0) {
            return 0;
        }
        char *name = packet + 64;
        *reinterpret_cast<void **>(player + 16) = player + 24;
        *reinterpret_cast<void **>(player + 20) = player + 40;
        func_11B170(player + 24, name, 16);
        func_11B170(player + 40, name + 16, 32);
        *reinterpret_cast<int *>(player + 4) = *reinterpret_cast<int *>(packet + 24);
        *reinterpret_cast<int *>(player) = *reinterpret_cast<int *>(packet + 112);
        func_00338470(object, message, size + 16);
        return 1;
    }
    if (type == 5) {
        void *player = func_00338310(object, *reinterpret_cast<int *>(packet + 24));
        if (player == 0) {
            return 0;
        }
        func_00338190(object, player);
        func_117CAC(player, 0, 136);
        func_00338470(object, message, size + 16);
        return 1;
    }
    if (type == 259) {
        void *player = func_00338310(object, *reinterpret_cast<int *>(packet + 24));
        if (player == 0) {
            return 0;
        }
        char *name = packet + 44;
        func_11B170(static_cast<char *>(player) + 24, name, 16);
        func_11B170(static_cast<char *>(player) + 40, name + 16, 32);
        *reinterpret_cast<void **>(packet + 36) = static_cast<char *>(player) + 24;
        *reinterpret_cast<void **>(packet + 40) = static_cast<char *>(player) + 40;
        func_00338470(object, message, size + 16);
        return 1;
    }
    return 1;
}
