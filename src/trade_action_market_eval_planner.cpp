#pragma exceptions off
#include "sub_list.h"

class TargetObj {
public:
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual void vfn30();
    virtual void vfn31();
    virtual void vfn32();
    virtual void vfn33();
    virtual void vfn34();
    virtual void vfn35();
    virtual void vfn36();
    virtual void vfn37();
    virtual void vfn38();
    virtual void vfn39();
    virtual void vfn40();
    virtual void vfn41();
    virtual void vfn42();
    virtual void vfn43();
    virtual void vfn44();
    virtual void vfn45();
    virtual void vfn46();
    virtual void vfn47();
    virtual void vfn48();
    virtual void vfn49();
    virtual void vfn50();
    virtual void vfn51();
    virtual void vfn52();
    virtual void vfn53();
    virtual void vfn54();
    virtual void vfn55();
    virtual void vfn56();
    virtual void vfn57();
    virtual void vfn58();
    virtual void vfn59();
    virtual void vfn60();
    virtual void vfn61();
    virtual void vfn62();
    virtual void vfn63();
    virtual void vfn64();
    virtual void vfn65();
    virtual void vfn66();
    virtual void vfn67();
    virtual void vfn68();
    virtual void vfn69();
    virtual void vfn70();
    virtual void vfn71();
    virtual void vfn72();
    virtual void vfn73();
    virtual void vfn74();
    virtual void vfn75();
    virtual void vfn76();
    virtual void vfn77();
    virtual void vfn78();
    virtual void vfn79();
    virtual void vfn80();
    virtual void vfn81();
    virtual void vfn82();
    virtual void vfn83();
    virtual void vfn84();
    virtual void vfn85();
    virtual void vfn86();
    virtual void vfn87();
    virtual void vfn88();
    virtual void vfn89();
    virtual void vfn90();
    virtual void vfn91();
    virtual void vfn92();
    virtual void vfn93();
    virtual void vfn94();
    virtual void vfn95();
    virtual void vfn96();
    virtual void vfn97();
    virtual void vfn98();
    virtual void vfn99();
    virtual void vfn100();
    virtual void vfn101();
    virtual void vfn102();
    virtual void vfn103();
    virtual void vfn104();
    virtual void vfn105();
    virtual void vfn106();
    virtual void vfn107();
    virtual void vfn108();
    virtual void vfn109();
    virtual int Method1B8(int id, int a2, int a3, int a4, int flag, float f12 = 0.0f); // index 110 -> offset 0x1B8 (440)

    void *m_vtable;     // 0x00
    void *m_field04;    // 0x04
    void *m_world;      // 0x08
    char pad_0C[0x18];  // 0x0C
    short m_action;     // 0x24
    char pad_26[0x12];  // 0x26
    unsigned char m_field38; // 0x38
    unsigned char m_field39; // 0x39
    unsigned char m_field3A; // 0x3A
    char pad_3B[0x09];  // 0x3B
    float pos_x;        // 0x44
    float pos_y;        // 0x48
    float pos_z;        // 0x4C
};

class TradeAction {
public:
    void *m_vtable;
    char pad_04[0x34];
    TargetObj *m_target; // 0x38
};

struct CandidateNode {
    int m_id;           // 0x00
    unsigned char m_dist; // 0x04
};

extern "C" {
extern void *D_004E3244;
void *func_332e60(void *mgr, int id);
int func_269FF0(void *obj);
void func_1E9130(void *mgr);
long long func_123350(float coord);
CandidateNode *func_3283C0(void *map, int x, long long y, int team, int a4, int *visited, int count);
int func_001510D0(TradeAction *self, int id);

int func_0014EE80(TradeAction *self, int a1, int target_node_id, int limit, int *out_dist) {
    TargetObj *s0 = self->m_target;
    TradeAction *s1 = self;
    int s4 = target_node_id;
    int s7 = limit;
    int s2 = 2;

    void *world = s0->m_world;
    void *game_mgr = *(void **)((char *)world + 0xB98);
    TargetObj *s3 = (TargetObj *)func_332e60(game_mgr, s4);

    if (s4 != -1 && s3 != 0) {
        if ((func_269FF0(s3) & 0xFF) == (func_269FF0(s1->m_target) & 0xFF)) {
            s0 = s3;
            s2 = 0;
        }
    }

    if (s7 == -1) {
        if (s2 != 0) {
            s2 = 1;
        }
        if (s2 == 2) {
            s2 = 3;
        }
    }

    void *mgr_obj = *(void **)((char *)D_004E3244 + 0x130000 - 0x4A90);
    func_1E9130(mgr_obj);

    int visited[100];
    int count = 0;
    int tested = 0;
    int fp_flag = 0;

    while (s2 < 4 && count < 100 && tested < 30) {
        int x = (int)func_123350(s0->pos_x);
        long long y = func_123350(s0->pos_y);
        int team = func_269FF0(s0) & 0xFF;

        void *search_mgr = *(void **)((char *)s1->m_target->m_world + 0xC64);
        CandidateNode *cand = func_3283C0(search_mgr, x, y, team, a1, visited, count);

        if (!cand) {
            goto L_advance;
        }

        if (!func_001510D0(s1, cand->m_id)) {
            visited[count++] = cand->m_id;
            goto L_check_loop;
        }

        if (s1->m_target == s0) {
            float max_d = 5.0f + *(float *)((char *)s1->m_target->m_field04 + 0x1C);
            if ((float)cand->m_dist > max_d) {
                goto L_advance;
            }
        }

        if (s3 == s0) {
            float max_d = 10.0f + *(float *)((char *)s3->m_field04 + 0x1C);
            if ((float)cand->m_dist > max_d) {
                goto L_advance;
            }
        }

        if (s1->m_target->m_field39 < 2) {
            visited[count++] = cand->m_id;
            tested++;
            goto L_check_loop;
        }

        if (s7 != -1 && (s2 == 0 || s2 == 2)) {
            if ((int)s0->m_field3A < s7) {
                visited[count++] = cand->m_id;
                tested++;
                goto L_check_loop;
            }
        }

        if (s1->m_target->Method1B8(cand->m_id, 0, 0.0f, fp_flag, -1) == 1) {
            if (out_dist) {
                *out_dist = cand->m_dist;
            }
            return cand->m_id;
        }

        visited[count++] = cand->m_id;
        tested++;
        fp_flag = 1;

    L_check_loop:
        if (count < 100 && tested < 30) {
            continue;
        }

    L_advance:
        if (s2 == 0) {
            s2 = 1;
        } else if (s2 == 1) {
            if (s7 != -1) {
                s0 = s1->m_target;
                s2 = 3;
            } else {
                s2 = 2;
            }
        } else if (s2 == 2) {
            s2 = 3;
        } else {
            return -1;
        }
    }

    return -1;
}

}
