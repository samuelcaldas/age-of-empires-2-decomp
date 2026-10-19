#ifndef ZONE_PATH_QUERIES_H
#define ZONE_PATH_QUERIES_H

struct MasterInfo {
    char pad[0x20];
    float rx;
    float ry;
};

extern "C" {

void func_001C8490(void *obj, char val);
int func_001C84B0(MasterInfo *master, float *p_x, float *p_y, void *map, int snap);
int func_001C8780(
    MasterInfo *master,
    void *map,
    short *out0,
    short *out1,
    short *out2,
    short *out3,
    short *out4,
    short *out5,
    short *out6,
    short *out7,
    float x,
    float y
);
void func_001C8A50();
void *func_001C8C00(void *self);
void *func_001C8C10(void *self);

}

#endif // ZONE_PATH_QUERIES_H
