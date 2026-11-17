typedef unsigned int u32;

struct TargetStruct {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
};

extern "C" void func_0012EF18(TargetStruct *ptr) {
    if (ptr != 0) {
        ptr->field_c = 0;
        ptr->field_0 = 0;
        ptr->field_8 = 0;
    }
}
