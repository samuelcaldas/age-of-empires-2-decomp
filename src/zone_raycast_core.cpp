#pragma exceptions off
#include "sub_list.h"
#include "zone_raycast_core.h"

extern "C" {

int func_123350(float val);

int func_001C8C20(void *self, void *param, int i, void *arr) {
    arr = *(void **)((char *)param + 0xF0);
    float sum = 0.0f;

    if (arr) {
        short count = *(short *)((char *)param + 0xF4);
        for (i = 0; i < count; i++) {
            float fval = (float)*(short *)((char *)arr + i * 4 + 2);
            if (fval > 0.0f) {
                sum += fval;
            }
        }
    }

    if (sum < 1.0f) {
        sum = 1.0f;
    }

    return func_123350(sum);
}

void func_001C8CA0() {}
void func_001C8FF0() {}

}
