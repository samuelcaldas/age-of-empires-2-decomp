#include <assert.h>
#include <stdio.h>

int func_0012CBF8(const unsigned char *data);
const unsigned char *func_0012CC48(const unsigned char *data);
int func_0012CC58(const char *data);
int func_0012CC78(const char *data);

int main(void) {
    const unsigned char data[] = {0, 0, 0x12, 0x34};
    const char zero[] = "0";
    const char at[] = "@";
    const char other[] = "A";

    assert(func_0012CBF8(NULL) == 0);
    assert(func_0012CBF8(data) == 0x3412);
    assert(func_0012CC48(0) == 0);
    assert(func_0012CC48(data) == data + 4);
    assert(func_0012CC58(0) == 0);
    assert(func_0012CC58(zero) == 1);
    assert(func_0012CC58(at) == 0);
    assert(func_0012CC78(0) == 0);
    assert(func_0012CC78(at) == 1);
    assert(func_0012CC78(other) == 0);

    puts("All native kt_libcdvd_server tests passed successfully.");
    return 0;
}
