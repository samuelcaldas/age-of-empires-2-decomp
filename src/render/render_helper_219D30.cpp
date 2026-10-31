#pragma exceptions off

class RenderWidget219D30 {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8(int arg);
};

extern "C" {
void func_116F68(void *ptr);
void func_100670(void *ptr);
void func_00217B50(void *self, int arg1);

struct ActionListItem {
    char *text;
    char *extra_text;
    int val_8;
    void *val_c;
    char byte_10;
    char pad_11[3];
    void *val_14;
    void *val_18;
    void *val_1c;
    void *val_20;
    char byte_24;
    char pad_25[3];
    ActionListItem *next;
};

void func_00219D30(RenderWidget219D30 *self) {
    char *self_bytes = (char *)self;
    void *next_sub;
    ActionListItem *curr = *(ActionListItem **)(self_bytes + 0x11C);

    if (curr != 0) {
        while (curr != 0) {
            if (curr->text != 0) {
                func_116F68(curr->text);
            }
            if (curr->extra_text != 0) {
                func_116F68(curr->extra_text);
            }
            while (curr->val_c != 0) {
                void *sub = curr->val_c;
                next_sub = *(void **)((char *)sub + 0x8);
                func_100670(sub);
                curr->val_c = next_sub;
            }
            ActionListItem *to_free = curr;
            curr = curr->next;
            func_116F68(to_free);
        }
        *(ActionListItem **)(self_bytes + 0x11C) = 0;
    }

    *(short *)(self_bytes + 0x120) = 0;
    func_00217B50(self, 1);

    self->m8(1);
}
}
