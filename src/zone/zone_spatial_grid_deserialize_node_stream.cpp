#pragma exceptions off
#include "zone_spatial_grid_deserialize_node_stream.h"

extern "C" {
int func_226D90(void *stream, void *dst, int size);
void func_001EBCC0(void *self, unsigned char type, void *stream, void *p2);
}

extern "C" void func_001EBC40(void *self, void *stream, void *p2) {
    int v1;
    int v2;
    unsigned char type;

    func_226D90(stream, &v1, 4);
    func_226D90(stream, &v2, 4);

    while (1) {
        func_226D90(stream, &type, 1);
        if (type == 0) {
            break;
        }
        func_001EBCC0(self, type, stream, p2);
    }
}
