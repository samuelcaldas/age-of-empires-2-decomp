#include "resfile_stream.h"
#include <string.h>

extern "C" {

void resfile_context_init(ResfileContext *ctx) {
    if (ctx == NULL) {
        return;
    }
    memset(ctx, 0, sizeof(ResfileContext));
}

int resfile_register_stream(ResfileContext *ctx, int stream_id, unsigned int lba, unsigned int offset, unsigned int len, void *buf) {
    int idx;
    if (ctx == NULL || ctx->stream_count >= RESFILE_MAX_STREAMS) {
        return -1;
    }
    idx = ctx->stream_count;
    ctx->streams[idx].active = 1;
    ctx->streams[idx].stream_id = stream_id;
    ctx->streams[idx].lba_start = lba;
    ctx->streams[idx].byte_offset = offset;
    ctx->streams[idx].byte_length = len;
    ctx->streams[idx].buffer = buf;
    ctx->stream_count++;
    return idx;
}

int resfile_find_stream(const ResfileContext *ctx, int stream_id) {
    int i;
    if (ctx == NULL) {
        return -1;
    }
    for (i = 0; i < ctx->stream_count; ++i) {
        if (ctx->streams[i].active && ctx->streams[i].stream_id == stream_id) {
            return i;
        }
    }
    return -1;
}

int resfile_load_resource(ResfileContext *ctx, int stream_id, unsigned int res_id, const DrsResourceRecord *record, void *dest, unsigned int max_bytes) {
    int stream_idx;
    const char *src_ptr;
    (void)res_id;

    if (ctx == NULL || record == NULL || dest == NULL) {
        return -1;
    }
    if (record->size > max_bytes) {
        ctx->error_code = -2; /* Overflow detected */
        return -1;
    }
    stream_idx = resfile_find_stream(ctx, stream_id);
    if (stream_idx < 0) {
        ctx->error_code = -1;
        return -1;
    }
    if (record->offset + record->size > ctx->streams[stream_idx].byte_length) {
        ctx->error_code = -3;
        return -1;
    }
    src_ptr = (const char *)ctx->streams[stream_idx].buffer;
    memcpy(dest, src_ptr + record->offset, record->size);
    ctx->total_bytes_streamed += record->size;
    return (int)record->size;
}

}
