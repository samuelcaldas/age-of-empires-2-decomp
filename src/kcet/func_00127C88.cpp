typedef signed short s16;

struct Vec3s {
    s16 x;
    s16 y;
    s16 z;
};

extern "C" void func_00127C88(Vec3s* v, s16 x, s16 y, s16 z) {
    v->z = z;
    v->x = x;
    v->y = y;
}
