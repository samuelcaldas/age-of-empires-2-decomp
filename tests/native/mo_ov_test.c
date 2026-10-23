#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "mo_ov_overlay.h"

/* Mock state for tracking component array construction */
static int mock_ctor_call_count = 0;
static struct {
    void *addr;
    void *type_info;
    void *ctor;
    int elem_sz;
    int count;
} mock_calls[10];

static int mock_finalizer_called = 0;
static void *mock_finalizer_addr = NULL;
static void *mock_finalizer_desc = NULL;
static void *mock_finalizer_hook = NULL;

void func_001003B0(void *addr, void *type_info, void *ctor, int elem_sz, int count) {
    if (mock_ctor_call_count < 10) {
        mock_calls[mock_ctor_call_count].addr = addr;
        mock_calls[mock_ctor_call_count].type_info = type_info;
        mock_calls[mock_ctor_call_count].ctor = ctor;
        mock_calls[mock_ctor_call_count].elem_sz = elem_sz;
        mock_calls[mock_ctor_call_count].count = count;
    }
    mock_ctor_call_count++;
}

void func_00100C20(void *addr, void *desc, void *hook) {
    mock_finalizer_called = 1;
    mock_finalizer_addr = addr;
    mock_finalizer_desc = desc;
    mock_finalizer_hook = hook;
}

static void test_mo_ov_base_pointer(void) {
    void *base = mo_ov_func_01ED7000();
    assert(base == (void *)0x01ED7290);
}

static void test_mo_ov_initialization_pipeline(void) {
    mock_ctor_call_count = 0;
    mock_finalizer_called = 0;

    mo_ov_func_01ED700C();

    /* Assert 7 component arrays constructed */
    assert(mock_ctor_call_count == 7);

    /* Verify Component 1 */
    assert(mock_calls[0].addr == (char *)0x01ED7290 + 0x0000);
    assert(mock_calls[0].type_info == (void *)0x0037D310);
    assert(mock_calls[0].ctor == (void *)0x001C6A70);
    assert(mock_calls[0].elem_sz == 0xA4);
    assert(mock_calls[0].count == 0x2C);

    /* Verify Component 2 */
    assert(mock_calls[1].addr == (char *)0x01ED7290 + 0x1C30);
    assert(mock_calls[1].type_info == (void *)0x0037D2F0);
    assert(mock_calls[1].ctor == (void *)0x001C2D50);
    assert(mock_calls[1].elem_sz == 0xA8);
    assert(mock_calls[1].count == 0x34);

    /* Verify Component 7 */
    assert(mock_calls[6].addr == (char *)0x01ED7290 + 0x76C00);
    assert(mock_calls[6].type_info == (void *)0x0037D190);
    assert(mock_calls[6].ctor == (void *)0x002D58E0);
    assert(mock_calls[6].elem_sz == 0x1B8);
    assert(mock_calls[6].count == 0x274);

    /* Verify finalizer registration */
    assert(mock_finalizer_called == 1);
    assert(mock_finalizer_addr == (void *)0x01ED7290);
    assert(mock_finalizer_desc == (void *)0x0037CF60);
    assert(mock_finalizer_hook == (void *)0x01ED7280);
}

static void test_mo_ov_metadata(void) {
    assert(mo_ov_data[0] == (void *)0x01ED7100);
    assert(mo_ov_data[1] == NULL);
}

int main(void) {
    test_mo_ov_base_pointer();
    test_mo_ov_initialization_pipeline();
    test_mo_ov_metadata();
    printf("All native mo_ov tests passed successfully.\n");
    return 0;
}
