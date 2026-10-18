#pragma exceptions off
#include <cstring>
#include "unit_action_build_7b4d0.h"

extern "C" {
    void *func_117CAC(void *dest, int val, unsigned long size);
}

struct EventRecord {
    short x;
    short y;
};

static void compact_event_buffer(void *self) {
    *(int *)((char *)self + 0x5E0) = 0x78;
    int count = *(int *)((char *)self + 0x5DC);
    if (count == 0) {
        func_117CAC(self, 0, 0x1E0);
        return;
    }
    EventRecord *records = (EventRecord *)self;
    int half = count / 2;
    for (int i = 0; i < half; ++i) {
        records[i] = records[i * 2];
    }
    *(int *)((char *)self + 0x5DC) = half;
}

void func_0027B4D0(void *self, int flag, float param1, float param2) {
    (void)flag;
    int count = *(int *)((char *)self + 0x5DC);
    int capacity = *(int *)((char *)self + 0x5E0);
    if (count >= capacity) {
        compact_event_buffer(self);
        count = *(int *)((char *)self + 0x5DC);
    }
    EventRecord *records = (EventRecord *)self;
    records[count].x = (short)param1;
    records[count].y = (short)param2;
    *(int *)((char *)self + 0x5DC) = count + 1;
}
