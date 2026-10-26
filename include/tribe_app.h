#ifndef TRIBE_APP_H
#define TRIBE_APP_H

#ifdef __cplusplus
extern "C" {
#endif

#define TRIBE_APP_SIZE 0x1948

extern void *g_tribe_app_vtable[64];
extern void *g_pApp;

void *func_184340(void *self, void *cfg, int arg);
int func_00185230(void *self);
void *func_2F61F0(void *obj, void *cfg, int arg);

#ifdef __cplusplus
}
#endif

#endif /* TRIBE_APP_H */
