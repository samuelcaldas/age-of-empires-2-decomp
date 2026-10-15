#ifndef TRADE_ACTION_MARKET_OPS_H
#define TRADE_ACTION_MARKET_OPS_H

struct MarketRouteItem {
    char pad_00[2];
    unsigned char m_res_idx;
    unsigned char m_mode;
    float m_val1;
    float m_val2;
    float m_score1;
    float m_score2;
    float m_score3;
    float m_score4;
    float m_total_score;
};

struct Bounds {
    float min;
    float max;
};

struct MarketScoring {
    Bounds m_bounds[4];
    char pad_20[0x30 - 0x20];
    unsigned char m_count;
    char pad_31[0x78 - 0x31];
    MarketRouteItem m_items[1];
};

extern "C" {
    void func_00149450(MarketScoring *self, const float *weights);
    int func_00149600(const void *a, const void *b);
}

#endif // TRADE_ACTION_MARKET_OPS_H
