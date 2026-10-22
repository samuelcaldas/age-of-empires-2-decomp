#include "network_dplay_3380e0.h"

extern char D_01087ED0[];
extern char D_010890A0[];

extern "C" int func_003380E0(void *guid, void **out_interface, void *unknown) {
    *out_interface = D_01087ED0;
    if (D_010890A0[0] == 0) {
        func_003381A0(D_01087ED0);
    }
    D_010890A0[0]++;
    return 0;
}
