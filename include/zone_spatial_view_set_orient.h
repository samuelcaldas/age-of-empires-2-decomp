#pragma once

struct Vec3f {
    float x;
    float y;
    float z;
};

extern "C" {
int func_001D8CA0(void *self, const Vec3f *v1, const Vec3f *v2, int flag);
}
