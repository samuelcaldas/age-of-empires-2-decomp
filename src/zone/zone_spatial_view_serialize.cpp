#pragma exceptions off

#include "zone_spatial_view_serialize.h"

extern "C" {
void func_226F70(void *stream, const void *buf, int size);
void func_1FD120(void *node, void *stream);
}

struct Node {
    char pad[0x4];
    Node *next;
};

struct SpatialViewObj {
    char pad_0[0x4];
    char f4[0x30];
    char f34[0x30];
    char f64[0xC];
    char f70[0xC];
    char f7C[0xC];
    char f88[0xC];
    int f94;
    int f98;
    int f9C;
    int fA0;
    int fA4;
    Node *head_A8;
    int fAC;
    int fB0;
    int fB4;
};

extern "C" void func_001DB120(SpatialViewObj *self, void *stream) {
    func_226F70(stream, self->f4, 0x30);
    func_226F70(stream, self->f34, 0x30);
    func_226F70(stream, self->f64, 0xC);
    func_226F70(stream, self->f70, 0xC);
    func_226F70(stream, self->f7C, 0xC);
    func_226F70(stream, self->f88, 0xC);
    func_226F70(stream, &self->f94, 0x4);
    func_226F70(stream, &self->f98, 0x4);
    func_226F70(stream, &self->f9C, 0x4);
    func_226F70(stream, &self->fA0, 0x4);
    func_226F70(stream, &self->fA4, 0x4);

    int count = 0;
    for (Node *curr = self->head_A8; curr != 0; curr = curr->next) {
        count++;
    }
    func_226F70(stream, &count, 0x4);

    for (int i = 0; i < count; i++) {
        Node *target = self->head_A8;
        for (int j = 0; j < (count - i - 1); j++) {
            target = target->next;
        }
        func_1FD120(target, stream);
    }

    int vAC = self->fAC;
    func_226F70(stream, &vAC, 0x4);
    func_226F70(stream, &self->fB0, 0x4);
    func_226F70(stream, &self->fB4, 0x4);
}
