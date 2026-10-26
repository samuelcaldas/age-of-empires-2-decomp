#ifndef RESFILE_STREAM_H
#define RESFILE_STREAM_H

#include "drs.h"

#ifdef __cplusplus
extern "C" {
#endif

#define RESFILE_SECTOR_SIZE 2048
#define RESFILE_MAX_STREAMS 8

typedef struct ResfileStreamEntry {
    int active;
    int stream_id;
    unsigned int lba_start;
    unsigned int byte_offset;
    unsigned int byte_length;
    void *buffer;
} ResfileStreamEntry;

typedef struct ResfileContext {
    int stream_count;
    ResfileStreamEntry streams[RESFILE_MAX_STREAMS];
    unsigned int total_bytes_streamed;
    int error_code;
} ResfileContext;

/* RESFILE streaming & sector resolution API */
void resfile_context_init(ResfileContext *ctx);
int resfile_register_stream(ResfileContext *ctx, int stream_id, unsigned int lba, unsigned int offset, unsigned int len, void *buf);
int resfile_find_stream(const ResfileContext *ctx, int stream_id);
int resfile_load_resource(ResfileContext *ctx, int stream_id, unsigned int res_id, const DrsResourceRecord *record, void *dest, unsigned int max_bytes);

#ifdef __cplusplus
}
#endif

#endif /* RESFILE_STREAM_H */
