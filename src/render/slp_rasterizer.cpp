#include "slp_rasterizer.h"
#include <string.h>

extern "C" {

int slp_rasterize_scanline(const unsigned char *cmd_stream,
                           size_t cmd_stream_size,
                           unsigned char *dest_row,
                           int dest_width,
                           int left_padding,
                           const SlpRasterContext *ctx) {
    if (!cmd_stream || !dest_row || dest_width <= 0) {
        return -1;
    }

    const unsigned char *p = cmd_stream;
    const unsigned char *end = cmd_stream + cmd_stream_size;
    int x = (left_padding > 0) ? left_padding : 0;

    while (p < end) {
        unsigned char cmd = *p++;

        if (cmd == 0x0F || cmd == 0xFF) {
            /* End of scanline terminator */
            break;
        }

        /* Test lower 2 bits for Lesser Block Copy (0x00) and Lesser Skip (0x01) */
        unsigned char low2 = (unsigned char)(cmd & 0x03);
        if (low2 == 0x00) {
            /* Lesser Block Copy: count = cmd >> 2 */
            int count = cmd >> 2;
            if (count == 0) {
                if (p >= end) break;
                count = *p++;
            }
            while (count > 0 && p < end) {
                unsigned char val = *p++;
                if (x < dest_width) {
                    dest_row[x] = val;
                }
                x++;
                count--;
            }
            continue;
        }

        if (low2 == 0x01) {
            /* Lesser Skip: count = cmd >> 2 */
            int count = cmd >> 2;
            if (count == 0) {
                if (p >= end) break;
                count = *p++;
            }
            x += count;
            continue;
        }

        /* Test lower 4 bits for specific opcodes */
        unsigned char low4 = (unsigned char)(cmd & 0x0F);
        switch (low4) {
            case 0x02: {
                /* Greater Block Copy: count = ((cmd & 0xF0) << 4) | next_byte */
                if (p >= end) break;
                int count = ((cmd & 0xF0) << 4) | (*p++);
                while (count > 0 && p < end) {
                    unsigned char val = *p++;
                    if (x < dest_width) {
                        dest_row[x] = val;
                    }
                    x++;
                    count--;
                }
                break;
            }

            case 0x03: {
                /* Greater Skip: count = ((cmd & 0xF0) << 4) | next_byte */
                if (p >= end) break;
                int count = ((cmd & 0xF0) << 4) | (*p++);
                x += count;
                break;
            }

            case 0x06: {
                /* Player Color Block Copy */
                int count = cmd >> 4;
                if (count == 0) {
                    if (p >= end) break;
                    count = *p++;
                }
                while (count > 0 && p < end) {
                    unsigned char idx = *p++;
                    if (x < dest_width) {
                        unsigned char color = idx;
                        if (ctx && ctx->player_table) {
                            color = ctx->player_table[idx];
                        } else if (ctx && ctx->player_color_offset) {
                            color = (unsigned char)(idx + ctx->player_color_offset);
                        }
                        dest_row[x] = color;
                    }
                    x++;
                    count--;
                }
                break;
            }

            case 0x07: {
                /* Solid Fill */
                int count = cmd >> 4;
                if (count == 0) {
                    if (p >= end) break;
                    count = *p++;
                }
                if (p >= end) break;
                unsigned char color = *p++;
                while (count > 0) {
                    if (x < dest_width) {
                        dest_row[x] = color;
                    }
                    x++;
                    count--;
                }
                break;
            }

            case 0x0A: {
                /* Fill Player Color */
                int count = cmd >> 4;
                if (count == 0) {
                    if (p >= end) break;
                    count = *p++;
                }
                if (p >= end) break;
                unsigned char idx = *p++;
                unsigned char color = idx;
                if (ctx && ctx->player_table) {
                    color = ctx->player_table[idx];
                } else if (ctx && ctx->player_color_offset) {
                    color = (unsigned char)(idx + ctx->player_color_offset);
                }
                while (count > 0) {
                    if (x < dest_width) {
                        dest_row[x] = color;
                    }
                    x++;
                    count--;
                }
                break;
            }

            case 0x0B: {
                /* Shadow / Dither */
                int count = cmd >> 4;
                if (count == 0) {
                    if (p >= end) break;
                    count = *p++;
                }
                while (count > 0) {
                    if (x < dest_width) {
                        if (ctx && ctx->shadow_table) {
                            dest_row[x] = ctx->shadow_table[dest_row[x]];
                        } else {
                            dest_row[x] = 0;
                        }
                    }
                    x++;
                    count--;
                }
                break;
            }

            case 0x0E: {
                /* Extended Commands */
                switch (cmd) {
                    case 0x4E: {
                        /* Outline Player Color pixel */
                        if (x < dest_width) {
                            unsigned char color = 0;
                            if (ctx && ctx->player_table) {
                                color = ctx->player_table[1];
                            } else if (ctx && ctx->player_color_offset) {
                                color = (unsigned char)(1 + ctx->player_color_offset);
                            }
                            dest_row[x] = color;
                        }
                        x++;
                        break;
                    }
                    case 0x5E: {
                        /* Fill Player Color Extended */
                        if (p >= end) break;
                        int count = *p++;
                        if (p >= end) break;
                        unsigned char idx = *p++;
                        unsigned char color = idx;
                        if (ctx && ctx->player_table) {
                            color = ctx->player_table[idx];
                        } else if (ctx && ctx->player_color_offset) {
                            color = (unsigned char)(idx + ctx->player_color_offset);
                        }
                        while (count > 0) {
                            if (x < dest_width) {
                                dest_row[x] = color;
                            }
                            x++;
                            count--;
                        }
                        break;
                    }
                    default:
                        /* Other hints (0x0E, 0x1E, 0x2E, 0x3E, etc.): no pixels emitted */
                        break;
                }
                break;
            }

            default:
                break;
        }
    }

    return (int)(p - cmd_stream);
}

int slp_rasterize_frame(const unsigned char *slp_data,
                        size_t slp_size,
                        const unsigned int *cmd_offsets,
                        const unsigned short *outline_table,
                        int width,
                        int height,
                        SlpRasterContext *ctx) {
    if (!slp_data || !cmd_offsets || !ctx || !ctx->dest_buffer) {
        return -1;
    }
    if (width <= 0 || height <= 0 || ctx->dest_stride <= 0) {
        return -2;
    }

    for (int y = 0; y < height; ++y) {
        unsigned int offset = cmd_offsets[y];
        if (offset >= slp_size) {
            return -3;
        }

        int left_pad = 0;
        if (outline_table) {
            left_pad = (int)outline_table[y * 2];
        }

        unsigned char *row_dest = ctx->dest_buffer + (y * ctx->dest_stride);
        int consumed = slp_rasterize_scanline(slp_data + offset,
                                              slp_size - offset,
                                              row_dest,
                                              width,
                                              left_pad,
                                              ctx);
        if (consumed < 0) {
            return -4;
        }
    }

    return 0;
}

} /* extern "C" */
