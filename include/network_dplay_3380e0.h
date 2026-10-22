#ifndef NETWORK_DPLAY_3380E0_H
#define NETWORK_DPLAY_3380E0_H

struct DPlayPlayerSlot {
    int field_0;
    int id;
    char data[128];
};

extern "C" {
    int func_003380E0(void *guid, void **out_interface, void *unknown);
    int func_00338140(int (*callback)(const void *, const char *, int, int, void *), void *context);
    void func_00338180(void *self);
    void func_00338190(void *self);
    void func_003381A0(void *self);
    void *func_00338230(void *self);
    void *func_00338260(void *self, int delete_flag);
    DPlayPlayerSlot *func_003382D0(void *self);
    DPlayPlayerSlot *func_00338310(void *self, int player_id);
    int func_00338350(void *self);
    int func_003383B0(void *self, int from_id, int to_id, const unsigned char *payload, int size);
}

#endif
