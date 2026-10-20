#pragma once

extern "C" {
    void *func_00280770(void *self, short count);
    inline void *func_280770(void *self, short count) {
        return func_00280770(self, count);
    }
}
