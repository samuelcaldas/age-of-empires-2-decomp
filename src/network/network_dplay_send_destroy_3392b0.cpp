#include "network_dplay_3380e0.h"

extern "C" int func_003392B0(void *self, int player_id) {
    if (player_id != 0) {
        int msg[13];
        int *fields = static_cast<int *>(self);
        fields[284]--;
        msg[0] = 5;
        msg[1] = 1;
        msg[2] = player_id;
        func_003383B0(self, 0, 0, reinterpret_cast<const unsigned char *>(msg), 52);
    }
    return 0;
}
