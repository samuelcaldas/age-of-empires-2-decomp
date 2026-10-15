#ifndef TRADE_ACTION_MARKET_EVAL_PLANNER_H
#define TRADE_ACTION_MARKET_EVAL_PLANNER_H

class TargetObj {
public:
    virtual void vfn0(); virtual void vfn1(); virtual void vfn2(); virtual void vfn3();
    virtual void vfn4(); virtual void vfn5(); virtual void vfn6(); virtual void vfn7();
    virtual void vfn8(); virtual void vfn9(); virtual void vfn10(); virtual void vfn11();
    virtual void vfn12(); virtual void vfn13(); virtual void vfn14(); virtual void vfn15();
    virtual void vfn16(); virtual void vfn17(); virtual void vfn18(); virtual void vfn19();
    virtual void vfn20(); virtual void vfn21(); virtual void vfn22(); virtual void vfn23();
    virtual void vfn24(); virtual void vfn25(); virtual void vfn26(); virtual void vfn27();
    virtual void vfn28(); virtual void vfn29(); virtual void vfn30(); virtual void vfn31();
    virtual void vfn32(); virtual void vfn33(); virtual void vfn34(); virtual void vfn35();
    virtual void vfn36(); virtual void vfn37(); virtual void vfn38(); virtual void vfn39();
    virtual void vfn40(); virtual void vfn41(); virtual void vfn42(); virtual void vfn43();
    virtual void vfn44(); virtual void vfn45(); virtual void vfn46(); virtual void vfn47();
    virtual void vfn48(); virtual void vfn49(); virtual void vfn50(); virtual void vfn51();
    virtual void vfn52(); virtual void vfn53(); virtual void vfn54(); virtual void vfn55();
    virtual void vfn56(); virtual void vfn57(); virtual void vfn58(); virtual void vfn59();
    virtual void vfn60(); virtual void vfn61(); virtual void vfn62(); virtual void vfn63();
    virtual void vfn64(); virtual void vfn65(); virtual void vfn66(); virtual void vfn67();
    virtual void vfn68(); virtual void vfn69(); virtual void vfn70(); virtual void vfn71();
    virtual void vfn72(); virtual void vfn73(); virtual void vfn74(); virtual void vfn75();
    virtual void vfn76(); virtual void vfn77(); virtual void vfn78(); virtual void vfn79();
    virtual void vfn80(); virtual void vfn81(); virtual void vfn82(); virtual void vfn83();
    virtual void vfn84(); virtual void vfn85(); virtual void vfn86(); virtual void vfn87();
    virtual void vfn88(); virtual void vfn89(); virtual void vfn90(); virtual void vfn91();
    virtual void vfn92(); virtual void vfn93(); virtual void vfn94(); virtual void vfn95();
    virtual void vfn96(); virtual void vfn97(); virtual void vfn98(); virtual void vfn99();
    virtual void vfn100(); virtual void vfn101(); virtual void vfn102(); virtual void vfn103();
    virtual void vfn104(); virtual void vfn105(); virtual void vfn106(); virtual void vfn107();
    // MWCC's eight-byte vtable header puts this method at byte offset 0x1B8.
    virtual int Method1B8(int identifier, int second, int third, int fourth, bool retry, float coordinate);

    void *m_field04;
    void *m_world;
    char pad_0C[0x18];
    short m_action;
    char pad_26[0x12];
    unsigned char m_field38;
    unsigned char m_field39;
    unsigned char m_field3A;
    char pad_3B[0x09];
    float pos_x;
    float pos_y;
    float pos_z;
};

struct TradeAction {
    void *m_vtable;
    char pad_04[0x34];
    TargetObj *m_target;
};

struct CandidateNode {
    int m_id;
    unsigned char m_dist;
};

struct PlannerManager {
    char pad_00[0x12B570];
    void *m_controller;
};

extern "C" {
    extern PlannerManager *D_004E3244;
    void *func_332e60(void *manager, int identifier);
    int func_269FF0(void *object);
    void func_1E9130(void *manager);
    int func_123350(float coordinate);
    CandidateNode *func_3283C0(void *map, int x, int y, int team, int category, int *visited, int count);
    TargetObj *func_001510D0(TradeAction *self, int identifier);

    /** Return a dispatched candidate identifier, or -1; optionally write its distance. */
    int func_0014EE90(TradeAction *self, int category, int target_identifier, int limit, int *distance);
}

#endif
