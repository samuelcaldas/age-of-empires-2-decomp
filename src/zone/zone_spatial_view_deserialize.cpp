#pragma exceptions off

#include "zone_spatial_view_deserialize.h"

extern "C" {
void func_226D90(void *stream, void *buf, int size);
void *func_1FC4F0();
void func_1FD230(void *node, void *stream);
extern float D_004E2F24; // -0x789C($gp)
extern float D_004E281C; // -0x7FA4($gp)
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

extern "C" void func_001DB2C0(SpatialViewObj *self, void *stream) {
    func_226D90(stream, self->f4, 0x30);
    func_226D90(stream, self->f34, 0x30);
    func_226D90(stream, self->f64, 0xC);
    func_226D90(stream, self->f70, 0xC);
    func_226D90(stream, self->f7C, 0xC);
    func_226D90(stream, self->f88, 0xC);
    func_226D90(stream, &self->f94, 0x4);
    func_226D90(stream, &self->f98, 0x4);
    func_226D90(stream, &self->f9C, 0x4);
    func_226D90(stream, &self->fA0, 0x4);
    func_226D90(stream, &self->fA4, 0x4);

    int count = 0;
    func_226D90(stream, &count, 0x4);

    Node *head = 0;
    for (int i = 0; i < count; i++) {
        Node *node = (Node *)func_1FC4F0();
        if (node != 0) {
            func_1FD230(node, stream);
            node->next = head;
            head = node;
        }
    }
    self->head_A8 = head;

    int vAC = 0;
    func_226D90(stream, &vAC, 0x4);
    self->fAC = vAC;

    func_226D90(stream, &self->fB0, 0x4);

    if (D_004E2F24 >= D_004E281C) {
        func_226D90(stream, &self->fB4, 0x4);
    }
}
