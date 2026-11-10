#ifndef SLP_RASTERIZER_H
#define SLP_RASTERIZER_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SlpRasterContext {
    unsigned char *dest_buffer;
    int dest_stride;
    int dest_width;
    int dest_height;
    const unsigned char *player_table; /* 256-byte or player color remap */
    int player_color_offset;          /* offset added to player color index */
    const unsigned char *shadow_table; /* 256-byte shadow lookup table */
} SlpRasterContext;

/**
 * Rasterize a single scanline of SLP bytecode into dest_row.
 *
 * @param cmd_stream Pointer to scanline command byte stream
 * @param cmd_stream_size Total bytes available in cmd_stream
 * @param dest_row Destination buffer for this row (8bpp)
 * @param dest_width Width/clipping boundary of dest_row
 * @param left_padding Number of transparent pixels prepended before decoding
 * @param ctx Optional rasterizer context (player tables, shadow table)
 * @return Number of command bytes consumed, or negative on parse error
 */
int slp_rasterize_scanline(const unsigned char *cmd_stream,
                           size_t cmd_stream_size,
                           unsigned char *dest_row,
                           int dest_width,
                           int left_padding,
                           const SlpRasterContext *ctx);

/**
 * Rasterize a full frame of SLP scanlines into ctx->dest_buffer.
 *
 * @param slp_data Pointer to raw frame command data payload
 * @param slp_size Size of slp_data in bytes
 * @param cmd_offsets Array of row command stream byte offsets [height]
 * @param outline_table Array of left and right padding [height * 2] (left, right pairs)
 * @param width Frame width
 * @param height Frame height
 * @param ctx Rasterizer context with destination surface and tables
 * @return 0 on success, negative error code on failure
 */
int slp_rasterize_frame(const unsigned char *slp_data,
                        size_t slp_size,
                        const unsigned int *cmd_offsets,
                        const unsigned short *outline_table,
                        int width,
                        int height,
                        SlpRasterContext *ctx);

#ifdef __cplusplus
}
#endif

#endif /* SLP_RASTERIZER_H */
