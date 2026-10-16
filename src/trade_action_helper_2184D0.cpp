#pragma exceptions off
#include "sub_list.h"

extern "C" {
int func_001AC470(void *arg0, void *arg1, void *arg2, int arg3, int arg4);
int func_001AB8F0(void *arg0, int arg1);
int func_0025E640(void *arg0, void *arg1, void *arg2, void *arg3, int arg4, int arg5);
int func_001AB9D0(void *arg0);
int func_001AD650(void *arg0, void *arg1, void *arg2, int arg3, int arg4, int arg5);

typedef void (*VirtualFn)(void *, void *);

/* The live function occupies 0x2184d0..0x218818; the eight trailing bytes are padding. */
static void *read_pointer(void *object, int offset) {
    return *(void **)((char *)object + offset);
}

static int read_word(void *object, int offset) {
    return *(int *)((char *)object + offset);
}

static short read_signed_short(void *object, int offset) {
    return *(short *)((char *)object + offset);
}

static void restore_word(void *self, int offset, int value) {
    void *manager = read_pointer(self, 0x20);
    *(int *)((char *)manager + offset) = value;
}

static short grid_count(short step, int span) {
    if (step >= span) {
        return 1;
    }

    /* BLOCKER: MWCC emits DIV without the original zero check and BREAK 7; keep unregistered. */
    int quotient = span / step;
    short truncated = (short)quotient;
    int product = (int)((unsigned int)(int)truncated * (unsigned int)(int)step);
    if (product < span) {
        truncated = (short)(truncated + 1);
    }
    return truncated;
}

static int add_words(int left, int right) {
    return (int)((unsigned int)left + (unsigned int)right);
}

static int grid_position(int start, short index, short step) {
    unsigned int product = (unsigned int)(int)index * (unsigned int)(int)step;
    return add_words(start, (int)product);
}

static void visit_row(void *self, short row, short columns) {
    for (short column = 0; column < columns; column = (short)(column + 1)) {
        short step_x = read_signed_short(self, 0x184);
        short step_y = read_signed_short(self, 0x186);
        int start_x = read_word(self, 0x0c);
        int start_y = read_word(self, 0x10);
        void *field180 = read_pointer(self, 0x180);
        void *manager = read_pointer(self, 0x20);
        int x = grid_position(start_x, column, step_x);
        int y = grid_position(start_y, row, step_y);
        func_0025E640(field180, manager, (void *)x, (void *)y, 0, 0);
    }
}

static void visit_grid(void *self, short rows, short columns) {
    for (short row = 0; row < rows; row = (short)(row + 1)) {
        visit_row(self, row, columns);
    }
}

static void restore_manager(void *self, int field28, int field2c, int field30, int field34) {
    restore_word(self, 0x28, field28);
    restore_word(self, 0x2c, field2c);
    restore_word(self, 0x30, field30);
    restore_word(self, 0x34, field34);
}

static void dispatch_grid(void *self, int field28, int field2c, int field30, int field34) {
    void *manager = read_pointer(self, 0x20);
    if (func_001AB8F0(manager, 1) == 0) {
        restore_manager(self, field28, field2c, field30, field34);
        return;
    }

    short columns = grid_count(read_signed_short(self, 0x184), read_word(self, 0x14));
    short rows = grid_count(read_signed_short(self, 0x186), read_word(self, 0x18));
    visit_grid(self, rows, columns);
    func_001AB9D0(read_pointer(self, 0x20));
    restore_manager(self, field28, field2c, field30, field34);
}

static void dispatch_rectangle(void *self) {
    void *manager = read_pointer(self, 0x20);
    if (func_001AB8F0(manager, 2) == 0) {
        return;
    }

    int x0 = read_word(self, 0x0c);
    int y0 = read_word(self, 0x10);
    int x1 = add_words(add_words(x0, read_word(self, 0x14)), -1);
    int y1 = add_words(add_words(y0, read_word(self, 0x18)), -1);
    int flag = *(unsigned char *)((char *)self + 0x18c);
    func_001AD650(read_pointer(self, 0x20), (void *)x0, (void *)y0, x1, y1, flag);
    func_001AB9D0(read_pointer(self, 0x20));
}

static void dispatch_fallback(void *self, int state) {
    void *object = read_pointer(self, 0x40);
    if (object == 0) {
        return;
    }

    void **vtable = *(void ***)object;
    if (state >= 2 && state < 8) {
        VirtualFn function = (VirtualFn)*(void **)((char *)vtable + 0x44);
        function(object, (char *)self + 0x24);
        return;
    }

    if (read_word(object, 0x9c) != 0) {
        return;
    }
    VirtualFn function = (VirtualFn)*(void **)((char *)vtable + 0x3c);
    function(object, (char *)self + 0x24);
}

void func_002184D0(void *self) {
    void *field180 = read_pointer(self, 0x180);
    if (field180 != 0) {
        void *manager = read_pointer(self, 0x20);
        int field28 = read_word(manager, 0x28);
        int field2c = read_word(manager, 0x2c);
        int field30 = read_word(manager, 0x30);
        int field34 = read_word(manager, 0x34);
        int start_x = read_word(self, 0x0c);
        int start_y = read_word(self, 0x10);
        int end_x = add_words(add_words(start_x, read_word(self, 0x14)), -1);
        int end_y = add_words(add_words(start_y, read_word(self, 0x18)), -1);
        func_001AC470(manager, (void *)start_x, (void *)start_y, end_x, end_y);
        dispatch_grid(self, field28, field2c, field30, field34);
        return;
    }

    int state = read_word(self, 0x188);
    if (state == 1) {
        dispatch_rectangle(self);
        return;
    }
    if (state == 3) {
        return;
    }
    dispatch_fallback(self, read_word(self, 0x1ac));
}
}
