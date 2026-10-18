#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_0021DF50(void *obj, int a1, int a2, int a3, int a4);
void *func_221B60(void *obj);
void *func_221AC0(void *obj);

// Original VRAM 0x21DE90 - 0x21DF50
// Calls func_221B60 (at 0x21ded8), func_0021DF50 (at 0x21df0c), func_221B60 (at 0x21df14), func_221AC0 (at 0x21df1c)
void *func_0021DE90(void *obj, int a1, int a2, int a3, int a4) {
    if (obj == 0) {
        return 0;
    }
    func_221B60(obj);
    func_0021DF50(obj, a1, a2, a3, a4);
    func_221B60(obj);
    func_221AC0(obj);
    return obj;
}
}
