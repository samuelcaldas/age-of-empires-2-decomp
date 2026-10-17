#pragma exceptions off
#include "unit_action_build_730.h"
#include "unit_action_build_690.h"

void func_00271730(ActionRebind *self, void *stream) {
    int token = -1;
    void *field = *(void **)((char *)self + 356);
    if (field != nullptr) {
        token = *(short *)((char *)field + 52);
    }
    int local_data = 0;
    char local_flag = 0;

    func_001C4360(self, stream);

    for (int i = 0; i < 3; ++i) {
        func_00226F70(stream, (char *)self + 300 + i * 6, 6);
    }
    func_00226F70(stream, (char *)self + 318, 2);
    func_00226F70(stream, (char *)self + 320, 2);
    func_00226F70(stream, (char *)self + 324, 1);
    func_00226F70(stream, &local_data, 4);
    func_00226F70(stream, &local_data, 4);
    func_00226F70(stream, &local_flag, 1);
    func_00226F70(stream, (char *)self + 352, 1);
    func_00226F70(stream, &token, 4);
    func_00226F70(stream, (char *)self + 328, 4);
    func_00226F70(stream, (char *)self + 325, 1);
    func_00226F70(stream, (char *)self + 332, 4);
    func_00226F70(stream, (char *)self + 336, 4);
    func_00226F70(stream, (char *)self + 340, 4);
    func_00226F70(stream, (char *)self + 344, 4);
    func_00226F70(stream, (char *)self + 348, 4);
    func_00226F70(stream, &local_flag, 1);
    func_00226F70(stream, (char *)self + 322, 2);
}
