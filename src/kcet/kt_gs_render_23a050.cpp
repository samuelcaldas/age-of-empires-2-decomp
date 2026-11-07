#include "kt_gs_render_23a050.h"

extern "C" {
char *strcpy(char *dest, const char *src);

void func_0023A050(Struct23A050 *self, const char *str) {
    if (str != 0) {
        strcpy(self->field_1050, str);
    } else {
        self->field_1050[0] = 0;
    }
}

int func_0023A080(Struct23A050 *self) {
    return self->field_1054;
}

}
