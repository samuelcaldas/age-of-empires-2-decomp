struct InfantryAI {
    void *m_vtable;
};

extern "C" {

void *func_001452B0(void *self, const char *name, int id, void *p2, void *p1);
extern const char D_490F90[];
extern char D_4D7780[];

InfantryAI *func_1446A0(InfantryAI *self, void *p1, void *p2) {
    func_001452B0(self, D_490F90, 0x3ED, p2, p1);
    self->m_vtable = D_4D7780;
    return self;
}

}
