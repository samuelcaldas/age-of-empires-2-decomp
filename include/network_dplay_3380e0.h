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
    void func_00338190(void *self, void *slot);
    void func_003381A0(void *self);
    void *func_00338230(void *self);
    void *func_00338260(void *self, int delete_flag);
    DPlayPlayerSlot *func_003382D0(void *self, int unused);
    DPlayPlayerSlot *func_00338310(void *self, int player_id);
    int func_00338350(void *self);
    int func_003383B0(void *self, int from_id, int to_id, const unsigned char *payload, int size);
    int func_003385C0(void *self, const void *packet, int size, int flags);
    int func_00338970(void *self, int player_id, void *out_name, int *size_ptr);
    int func_00338A10(void *self, int player_id, int *out_count, int flags);
    int func_00338A20(void *self, int *from_id, int *to_id, int flags, void *data, int *size);
    int func_00338B90(void *self, int from_id, int to_id, int flags, const unsigned char *data, int size);
    int func_00338C60(void *self);
    int func_00338CB0(void *self);
    int func_00338CC0(void *self, const void *riid, void **ppvObj);
    int func_00338CE0(void *self, const void *desc, int flags);
    int func_00338FA0(void *self, int *out_id, const void *name, void *event, void *data, int size, int flags);
    int func_003390D0(void *self, int player_id, void *caps, int flags);
    int func_00339140(void *self, void *desc, unsigned int *size_ptr);
    int func_003391E0(void *self, void *caps, int flags);
    int func_00339220(void *self);
    int func_00339270(void *self);
    int func_003392B0(void *self, int player_id);
    int func_00339300(void *self, void *desc, int timeout, int (*callback)(const void *, unsigned int *, int, void *), void *context, int flags);
}

#endif
