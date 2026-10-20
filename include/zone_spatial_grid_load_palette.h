#ifndef ZONE_SPATIAL_GRID_LOAD_PALETTE_H
#define ZONE_SPATIAL_GRID_LOAD_PALETTE_H

struct ZoneSpatialGrid;
struct Palette;
struct GlobalManager;

extern "C" {
extern GlobalManager *D_004D89C0;

char *func_001AAA70(char *s);
Palette *func_001A6270(const char *path, int key, int policy);
int func_0021BAE0(void *palette_obj, int start_idx, int count, void *dst_buf);
int func_0021BB20(void *palette_obj, int start_idx, int count, void *src_buf);
int func_0021B430(void *palette_obj);

Palette *func_001F2F80(ZoneSpatialGrid *self, const char *name, int flag1, int flag2);
}

#endif // ZONE_SPATIAL_GRID_LOAD_PALETTE_H
