#ifndef RENDER_MANAGER_STREAM_FIXTURE_H
#define RENDER_MANAGER_STREAM_FIXTURE_H

#include "render_manager_stream.h"
#include <string>

struct StreamScenario {
    int payload_size;
    int payload_read_result;
    int dispatch_result;
    bool fail_buffer;
    bool fail_context;
    int reads;
    void *payload;
    void *context;
    void *parent;
    std::string events;
};

extern StreamScenario scenario;
extern RenderManagerStream manager;
void prepare_stream_scenario(int payload_size);

#endif
