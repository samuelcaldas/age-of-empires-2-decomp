typedef unsigned int u32;

struct TargetStruct {
    u32 field0;
    u32 field4;
    u32 field8;
};

extern "C" u32 func_0012F6A8(TargetStruct *self) {
    return self->field8;
}
