#pragma exceptions off

#include "zone_dispatch_internal.h"

extern "C" void func_001C98A0(void *self, int width, int height) {
    // Zone resize/dispatch: updates zone grid for new width/height dimensions.
    // Saves s0-s6. width=s1, height=s0, self=s2.
    ZoneCellsLayout *zm = (ZoneCellsLayout *)self;

    if (width <= 0) return;
    if (height <= 0) return;

    // --- If zone has existing children, free them first ---
    int child_count = zm->child_count;
    if (child_count != 0) {
        // Load vtable/sub-object from 0x8EE8 region (+0x10000 offset)
        // lw v0, -0x7118(at) where at = self + 0x10000 → offset = 0x10000 - 0x7118 = 0x8EE8
        void *zone_sub = zm->zone_child;
        if (zone_sub != 0) {
            // Iterate child_count times, calling func_1EBA20 on sub-objects
            short sub_count = *(short *)((char *)zone_sub + 0x50);  // lh s4,0x50(v0)
            int i = 0;
            while (i < sub_count) {
                void **sub_arr = *(void ***)((char *)zone_sub + 0x54);  // lw v0,0x54(v0)
                if (sub_arr != 0) {
                    void *child = sub_arr[i];
                    if (child != 0) {
                        func_1EBA20((char *)child + 0x74);
                        sub_arr = *(void ***)((char *)zm->zone_child + 0x54);
                        child = sub_arr[i];
                        func_1EBA20((char *)child + 0x80);
                        sub_arr = *(void ***)((char *)zm->zone_child + 0x54);
                        child = sub_arr[i];
                        func_1EBA20((char *)child + 0x8C);
                    }
                }
                i++;
            }
        }
        func_1D16D0(self);

        // --- Free cell items in old grid ---
        for (int y = 0; y < zm->height; y++) {
            for (int x = 0; x < zm->width; x++) {
                ZoneCell *cell = (ZoneCell *)((char *)zm->cells_ptr[y] + x * 0x1C);
                void *item = cell->f_10;
                if (item != 0) {
                    func_25DE30(item, 1);
                    cell->f_10 = 0;
                }
            }
        }
        func_1D06A0(self);
    }

    // --- Clamp new width and height to max 200 (0xC8) ---
    int new_width = (width < 200) ? width : 200;
    zm->width = new_width;
    int new_height = (height < 200) ? height : 200;
    zm->height = new_height;

    // --- Clear/reset internal grid state fields ---
    // sw zero, -0x7170(at) → offset 0x10000-0x7170 = 0x8E90
    zm->f_8E90 = 0;
    // sw zero, -0x716C(at) → offset 0x8E94
    zm->f_8E94 = 0;

    // --- Convert width/height to float, store, compute width+1 and height+1 ---
    float fwidth = (float)zm->width;
    zm->width_f = fwidth;
    float fheight = (float)zm->height;
    zm->height_f = fheight;
    zm->width_plus_1 = 1.0f + fwidth;
    zm->height_plus_1 = 1.0f + fheight;

    // --- Compute cell counts from short fields (row/col scale factors) ---
    zm->cell_count_x = zm->width * zm->f_8EAE;
    zm->cell_count_y = zm->height * zm->f_8EB0;

    // --- memset/alloc zones for cells: 4 memset calls ---
    void *p_81d = memset((void *)&D_81D120, 0, 0x111700);
    zm->child_count = (int)p_81d;
    zm->f_8EC4 = memset((void *)&D_92E820, 0, 0x9C40);
    zm->cells_ptr = (ZoneCell **)memset((void *)&D_938460, 0, 0x324);
    zm->f_8EC8 = memset((void *)&D_938790, 0, 0x324);

    // --- Outer loop: y from 0 to height-1, compute cell row pointers ---
    for (int y = 0; y < zm->height; y++) {
        int cell_row_stride = (y * zm->width * 8 - y * zm->width) * 4;  // y * width * 0x1C
        zm->cells_ptr[y] = (ZoneCell *)((char *)zm->child_count + cell_row_stride);
        ((char **)zm->f_8EC8)[y] = (char *)zm->f_8EC4 + y * zm->width;
    }

    // --- Set last row sentinel ---
    zm->cells_ptr[zm->height] = (ZoneCell *)zm->child_count;
    ((char **)zm->f_8EC8)[zm->height] = (char *)zm->f_8EC4;

    // --- Nested loop over rows, mark visited (cell->f_6 = 1) ---
    for (int y = 0; y < zm->height; y++) {
        for (int x = 0; x < zm->width; x++) {
            ZoneCell *cell = (ZoneCell *)((char *)zm->cells_ptr[y] + (x * 8 - x) * 4);
            cell->f_6 = 1;
        }
    }

    // --- Call func_001C9FA0 to initialize rect covers (0,0,w-1,h-1) ---
    {
        int w = zm->width;
        int h = zm->height;
        func_001C9FA0(self, 0, 0, w - 1, h - 1);
    }

    // --- Setup vtable/callback pointers in 0x8EE8+ region ---
    {
        // Zone manager group (gp-0x79D0 = D_4E2DF0)
        // sub at field 0x8EEC (-0x7114 from at=self+0x10000)
        void *sub = zm->f_8EEC;
        if (sub != 0) {
            func_335560(D_4E2DF0);
        }
        func_335550(D_4E2DF0, self);
        zm->f_8EEC = &D_6F1AF0;

        // Entity manager group (gp-0x79D8 = D_4E2DE8)
        // sub2 at field 0x8EF0 (-0x7110 from at)
        void *sub2 = zm->f_8EF0;
        if (sub2 != 0) {
            func_001389F0(D_4E2DE8);
        }
        func_001387C0(D_4E2DE8, width, height);
        zm->f_8EF0 = &D_5E90B0;

        // AI manager group (gp-0x79D4 = D_4E2DEC)
        // sub3 at field 0x8EF4 (-0x710C from at)
        void *sub3 = zm->f_8EF4;
        if (sub3 != 0) {
            func_327590(D_4E2DEC);
        }
        // zone_child at 0x8EE8 (-0x7118 from at) — used as a1 arg
        void *zone_ent = zm->zone_child;
        short ent_count = *(short *)((char *)zone_ent + 0x50);
        func_3273E0(D_4E2DEC, (int)ent_count, 0x40);
        zm->f_8EF4 = &D_6101D0;

        // Event manager group (gp-0x79CC = D_4E2DF4)
        // sub4 at field 0x8EE0 (-0x7120 from at)
        void *sub4 = zm->f_8EE0;
        if (sub4 != 0) {
            func_1ED830(sub4);
        }
        func_1ED150(D_4E2DF4);
        // Store &D_6F1B50 both to gp-0x757C and to field 0x8EE0
        D_4E3244 = &D_6F1B50;
        zm->f_8EE0 = &D_6F1B50;

        // zone_child at 0x8EE8 used as a1 for func_1ED3C0
        void *zone_ent2 = zm->zone_child;
        func_1ED3C0(D_4E2DF4, zone_ent2);
        func_1D0430(self);
    }
}
