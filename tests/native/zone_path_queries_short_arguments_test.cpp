#include <cassert>
#include "zone_path_queries.h"

namespace {
const unsigned int RAW_Y_BITS = 0x12348001U;
const unsigned int RAW_TARGET_BITS = 0x5678FEDCU;
long long helper_payloads[5];
int projection_calls;
char zone_buffer[0x100];
char singleton_buffer[0x408];
char manager_buffer[0x40];
char internal_object;
char context_object;
}

extern "C" {
void *D_004E3180;
void *D_4E3400;
void *D_4E3408;

int func_262570(void *, int, int, long long first_y, long long first_target,
                long long second_y, long long second_target, int, float *, int) {
    helper_payloads[0] = first_y;
    helper_payloads[1] = first_target;
    helper_payloads[2] = second_y;
    helper_payloads[3] = second_target;
    return 1;
}

int func_001D0350(void *context, short *output_x, short *output_y,
                  float, float, float, int raw_y, int raw_target) {
    assert(context == &context_object);
    assert(raw_y == 0x12348001);
    assert(raw_target == 0x5678FEDC);
    *output_x = 0;
    *output_y = 0;
    ++projection_calls;
    return 1;
}

int func_326F60(void *, int, long long target, short, short, short, short,
                short, short, short, short, int, unsigned char, int) {
    helper_payloads[4] = target;
    return 1;
}
}

namespace {
void prepare_zone() {
    *reinterpret_cast<void **>(zone_buffer + 0x10) = &internal_object;
    *reinterpret_cast<float *>(zone_buffer + 0x94) = 2.0f;
    *reinterpret_cast<float *>(zone_buffer + 0x98) = 3.0f;
}

void prepare_context() {
    *reinterpret_cast<void **>(singleton_buffer + 0x404) = manager_buffer;
    *reinterpret_cast<void **>(manager_buffer + 0x3C) = &context_object;
    D_004E3180 = singleton_buffer;
}

void invoke_projection() {
    float x = 5.0f;
    float *raw_y = reinterpret_cast<float *>(RAW_Y_BITS);
    void *raw_target = reinterpret_cast<void *>(RAW_TARGET_BITS);
    func_001C8A50(zone_buffer, &x, raw_y, raw_target, 1, 2, 3, 1, 77);
}

void assert_signed_short_payloads() {
    assert(projection_calls == 4);
    assert(helper_payloads[0] == -32767LL);
    assert(helper_payloads[1] == -292LL);
    assert(helper_payloads[2] == -32767LL);
    assert(helper_payloads[3] == -292LL);
    assert(helper_payloads[4] == -292LL);
}
}

int main() {
    static_assert(sizeof(void *) == 4, "requires 32-bit pointers");
    static_assert(sizeof(short) == 2, "requires 16-bit short");
    prepare_zone();
    prepare_context();
    invoke_projection();
    assert_signed_short_payloads();
    return 0;
}
