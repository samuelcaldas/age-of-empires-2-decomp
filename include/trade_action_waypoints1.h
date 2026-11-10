#ifndef TRADE_ACTION_WAYPOINTS1_H
#define TRADE_ACTION_WAYPOINTS1_H

class TargetObj;

struct TradeAction {
    char pad_00[0x38];
    TargetObj *m_target;
    char pad_3C[0x0C];
    short m_field48;
};

extern "C" {
int func_00149FE0(TradeAction *self, short target_id, int flag);
int func_0014A0D0(TradeAction *self, short target_id, int flag);
int func_0014A1C0(TradeAction *self, short target_id, int flag);
int func_0014A2B0(TradeAction *self, short target_id, int flag);
}

#endif // TRADE_ACTION_WAYPOINTS1_H
