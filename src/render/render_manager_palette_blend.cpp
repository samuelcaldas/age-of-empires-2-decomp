#pragma exceptions off
#pragma divbyzerocheck on
#pragma inline_depth(8)

#include "render_manager_palette_blend.h"

enum {
    PALETTE_ENTRY_COUNT = 256,
    PALETTE_ENTRY_SIZE = 4,
    PALETTE_RGB_CHANNELS = 3,
    COLOR_COMPONENT_MAXIMUM = 255,
    BRIGHTNESS_SHIFT = 9,
    FULL_BLEND_PERCENT = 100
};

static inline void sort_channels(int *channels) {
    for (int pass = 0; pass < PALETTE_RGB_CHANNELS - 1; pass++) {
        for (int channel = 0; channel < PALETTE_RGB_CHANNELS - 1; channel++) {
            if (channels[channel] < channels[channel + 1]) {
                int temporary = channels[channel];
                channels[channel] = channels[channel + 1];
                channels[channel + 1] = temporary;
            }
        }
    }
}

static inline void copy_entry(const unsigned char *source, unsigned char *destination, int index) {
    destination[index * PALETTE_ENTRY_SIZE + 0] = source[index * PALETTE_ENTRY_SIZE + 0];
    destination[index * PALETTE_ENTRY_SIZE + 1] = source[index * PALETTE_ENTRY_SIZE + 1];
    destination[index * PALETTE_ENTRY_SIZE + 2] = source[index * PALETTE_ENTRY_SIZE + 2];
    destination[index * PALETTE_ENTRY_SIZE + 3] = source[index * PALETTE_ENTRY_SIZE + 3];
}

static inline void blend_entry(const unsigned char *source, unsigned char *destination, int index, unsigned char red, unsigned char blue, unsigned char green, int percent) {
    int channels[PALETTE_RGB_CHANNELS];
    channels[0] = source[index * PALETTE_ENTRY_SIZE + 0];
    channels[1] = source[index * PALETTE_ENTRY_SIZE + 1];
    channels[2] = source[index * PALETTE_ENTRY_SIZE + 2];
    sort_channels(channels);
    int brightness = channels[0] + (((COLOR_COMPONENT_MAXIMUM - channels[0]) * (channels[1] + channels[2])) >> BRIGHTNESS_SHIFT);
    int target_red = (red * brightness) / COLOR_COMPONENT_MAXIMUM;
    destination[index * PALETTE_ENTRY_SIZE + 0] = source[index * PALETTE_ENTRY_SIZE + 0] + ((target_red - source[index * PALETTE_ENTRY_SIZE + 0]) * percent) / FULL_BLEND_PERCENT;
    int target_green = (green * brightness) / COLOR_COMPONENT_MAXIMUM;
    destination[index * PALETTE_ENTRY_SIZE + 1] = source[index * PALETTE_ENTRY_SIZE + 1] + ((target_green - source[index * PALETTE_ENTRY_SIZE + 1]) * percent) / FULL_BLEND_PERCENT;
    int target_blue = (blue * brightness) / COLOR_COMPONENT_MAXIMUM;
    destination[index * PALETTE_ENTRY_SIZE + 2] = source[index * PALETTE_ENTRY_SIZE + 2] + ((target_blue - source[index * PALETTE_ENTRY_SIZE + 2]) * percent) / FULL_BLEND_PERCENT;
    destination[index * PALETTE_ENTRY_SIZE + 3] = source[index * PALETTE_ENTRY_SIZE + 3];
}

static inline void process_entry(const unsigned char *source, unsigned char *destination, int index, unsigned char red, unsigned char blue, unsigned char green, int percent, int skip_first, int skip_second) {
    if (index == skip_first || index == skip_second) {
        copy_entry(source, destination, index);
        return;
    }
    blend_entry(source, destination, index, red, blue, green, percent);
}

extern "C" {
void func_00189260(const unsigned char *source, unsigned char *destination,
                   RenderPaletteColor color, int percent,
                   int skip_first, int skip_second) {
    unsigned char red = color.red;
    unsigned char blue = color.blue;
    unsigned char green = color.green;
    for (int index = 0; index < PALETTE_ENTRY_COUNT; index++) {
        process_entry(source, destination, index, red, blue, green, percent, skip_first, skip_second);
    }
}
}
