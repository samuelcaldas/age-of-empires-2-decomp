#include <cassert>
#include <cstdlib>
#include "zone_spatial_grid_destroy_static_node_pool.h"

char D_9397F0[256 * 0x2C];

static void *g_last_ptr = NULL;
static void *g_last_dtor = NULL;
static unsigned int g_last_size = 0;
static int g_last_count = 0;
static int g_call_count = 0;

extern "C" {
void func_001E4040() {}

void func_00100340(void *ptr, void *dtor, unsigned int size, int count) {
    g_last_ptr = ptr;
    g_last_dtor = dtor;
    g_last_size = size;
    g_last_count = count;
    g_call_count++;
}
}

int main(int argc, char **argv) {
    if (argc < 2) {
        return 1;
    }

    int case_id = std::atoi(argv[1]);

    switch (case_id) {
        case 0: {
            g_call_count = 0;
            func_001EB2A0();
            assert(g_call_count == 1);
            assert(g_last_ptr == (void *)D_9397F0);
            assert(g_last_dtor == (void *)func_001E4040);
            assert(g_last_size == 0x2C);
            assert(g_last_count == 0x100);
            break;
        }
        default:
            return 2;
    }

    return 0;
}
