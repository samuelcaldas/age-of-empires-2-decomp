#pragma exceptions off

extern "C" {
int func_0021B440(void *palette_obj, int unused, int start_idx, int count, void *dst_buf);
int func_0021B4C0(void *palette_obj, int unused, int start_idx, int count, void *src_buf, int trans_idx);

int func_0021BAE0(void *palette_obj, int start_idx, int count, void *dst_buf) {
    func_0021B440(palette_obj, 0, start_idx, count, dst_buf);
    return count;
}

int func_0021BB20(void *palette_obj, int start_idx, int count, void *src_buf) {
    func_0021B4C0(palette_obj, 0, start_idx, count, src_buf, 0xFF);
    return count;
}

struct PaletteColor {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

int func_0021BB60(void *palette_obj, int target_color) {
    unsigned int best_distance = -1;
    unsigned int target_r = target_color & 0xFF;
    unsigned int target_g = ((unsigned int)target_color >> 8) & 0xFF;
    unsigned int target_b = ((unsigned int)target_color >> 16) & 0xFF;

    PaletteColor palette_buffer[256];
    func_0021B440(palette_obj, 0, 0, 256, palette_buffer);

    int best_index = 0;
    int dr, dg, db;
    for (int i = 0; i < 256; i++) {
        dr = target_r - palette_buffer[i].r;
        dg = target_g - palette_buffer[i].g;
        db = target_b - palette_buffer[i].b;
        unsigned int dist = dr * dr;
        dist += dg * dg;
        dist += db * db;
        if (dist < best_distance) {
            best_distance = dist;
            best_index = i;
        }
    }
    return best_index;
}
}
