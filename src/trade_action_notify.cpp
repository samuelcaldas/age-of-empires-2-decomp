/*
 * Experimental Trade Action Notification Subsystem (NonMatching / Experimental)
 * VRAM 0x2B9770 - 0x2B9880
 */
#pragma exceptions off
#include "trade_action_notify.h"
#include "trade_action_candidates_access.h"

using namespace trade_action_candidates;

extern "C" {
void *func_00332e60(void *manager, int id);
int func_001471a0(int entity_id);
int func_00147170(int entity_id);
int func_00147190(int entity_id);
int func_0014c430(int entity_id, int code);
int func_002bb100(void *self, int item_id, int action_type);
}

namespace trade_action_candidates {

struct TradeActionState {
    char pad_0[176];
    void *m_mgr;
    char pad_180[3184 - 180];
    int *m_pool;
    int m_count;
    int m_pad_3192;
    int m_capacity;
};

struct ManagerState {
    char pad_0[172];
    void *m_group;
};

struct GroupState {
    char pad_0[2968];
    void *m_root;
};

struct Entity {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual int *get_id();
};

typedef void (*NotifyOrderFn)(void *world, void *ba0, int item_id, int code,
                              int t0, int t1, int t2, int t3,
                              int action_type,
                              float f12, float f13, float f14, float f15);

} // namespace trade_action_candidates

extern "C" {
int func_002B9770(void *self, int item_id, int action_type) {
    void *mgr = *reinterpret_cast<void **>(bytes(self) + 176);
    void *world = *reinterpret_cast<void **>(bytes(mgr) + 172);
    void *ba0 = *reinterpret_cast<void **>(bytes(world) + 2976);
    void *vt = *reinterpret_cast<void **>(bytes(world) + 6960);
    NotifyOrderFn fn = *reinterpret_cast<NotifyOrderFn *>(bytes(vt) + 56);
    fn(world, ba0, item_id, 706,
       -1, -1, 1, 0,
       action_type,
       -1.0f, -1.0f, -1.0f, -1.0f);
    return 1;
}

int func_002B97D0(void *self, int item_id, int action_type, float param) {
    void *mgr = *reinterpret_cast<void **>(bytes(self) + 176);
    void *world = *reinterpret_cast<void **>(bytes(mgr) + 172);
    void *ba0 = *reinterpret_cast<void **>(bytes(world) + 2976);
    void *vt = *reinterpret_cast<void **>(bytes(world) + 6960);
    NotifyOrderFn fn = *reinterpret_cast<NotifyOrderFn *>(bytes(vt) + 56);
    fn(world, ba0, item_id, 710,
       -1, -1, 1, 0,
       action_type,
       -1.0f, -1.0f, 1.0f, param);
    return 1;
}

int func_002B9830(void *self, int a1, int a2, int a3) {
    void *mgr = *reinterpret_cast<void **>(bytes(self) + 176);
    void *world = *reinterpret_cast<void **>(bytes(mgr) + 172);
    void *ba0 = *reinterpret_cast<void **>(bytes(world) + 2976);
    void *vt = *reinterpret_cast<void **>(bytes(world) + 6960);
    NotifyOrderFn fn = *reinterpret_cast<NotifyOrderFn *>(bytes(vt) + 56);
    fn(world, ba0, a1, 724,
       a2, -1, 1, 0,
       a3,
       -1.0f, -1.0f, -1.0f, -1.0f);
    return 1;
}

int func_002B9880(void *self, int item_id, int action_type) {
    TradeActionState *act = reinterpret_cast<TradeActionState *>(self);
    bool matched = false;
    int i = 0;
    int count = act->m_count;
    while (i < count && i < act->m_capacity) {
        if (item_id == act->m_pool[i]) {
            matched = true;
            break;
        }
        i++;
    }
    if (matched) {
        return 0;
    }

    ManagerState *mgr = reinterpret_cast<ManagerState *>(act->m_mgr);
    GroupState *group = reinterpret_cast<GroupState *>(mgr->m_group);
    Entity *item = reinterpret_cast<Entity *>(func_00332e60(group->m_root, item_id));
    if (!item) {
        return 0;
    }

    if (!item->get_id()) {
        return 0;
    }

    if (func_001471a0(*item->get_id()) == 600 || func_001471a0(*item->get_id()) == 613) {
        return 1;
    }
    if (func_001471a0(*item->get_id()) == 602 || func_001471a0(*item->get_id()) == 618) {
        return 1;
    }
    if (func_001471a0(*item->get_id()) == 605) {
        return 1;
    }

    if (!(*reinterpret_cast<float *>(bytes(item) + 64) <= 0.0f)) {
        return 0;
    }

    if (func_00147170(*item->get_id()) == 710) {
        if (func_00147190(*item->get_id()) == 100) {
            return 0;
        }
    }
    if (func_00147170(*item->get_id()) == 702) {
        return 0;
    }

    if (func_0014c430(*item->get_id(), 705) == 1) {
        return 0;
    }

    int res = func_002bb100(self, item_id, action_type);
    return res == 0 ? 0 : 1;
}
}
