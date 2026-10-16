#pragma once

struct Vec3f {
    float x, y, z;
};

struct SpatialViewObj;

extern "C" {
void func_001DAAB0(void *a0, SpatialViewObj *view, void *a2, Vec3f *out, float scale);
}
