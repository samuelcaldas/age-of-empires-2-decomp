#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct EmotionalAI {
    void *m_vtable;
    char pad_04[0xA8];
    int m_fieldAC;
    int m_fieldB0[6];
    char m_buf1[30];
    char m_buf2[30];
    char m_buf3[30];
    char m_buf4[30];
    char m_buf5[30];
    char m_buf6[30];

    int Save(void *stream);
};

extern "C" {
    static int s_6f70_called = 0;
    static void *s_6f70_last_stream = 0;
    static int s_6f70_total_bytes = 0;
    static int s_6f70_written_values[6] = {0};

    void func_00226F70(void *stream, void *src, int size) {
        if (s_6f70_called < 6 && size == 4) {
            s_6f70_written_values[s_6f70_called] = *(int*)src;
        }
        s_6f70_called++;
        s_6f70_last_stream = stream;
        s_6f70_total_bytes += size;
    }

    void func_00140670(EmotionalAI *self, int personality);
}

static void reset_mocks() {
    s_6f70_called = 0;
    s_6f70_last_stream = 0;
    s_6f70_total_bytes = 0;
    memset(s_6f70_written_values, 0, sizeof(s_6f70_written_values));
}

static void test_emotional_ai_save_stream_writes() {
    reset_mocks();
    EmotionalAI ai;
    memset(&ai, 0, sizeof(ai));
    for (int i = 0; i < 6; i++) {
        ai.m_fieldB0[i] = 1000 + i * 10;
    }

    int ret = ai.Save((void*)0x8888);

    assert(ret == 1);
    assert(s_6f70_called == 6);
    assert(s_6f70_last_stream == (void*)0x8888);
    assert(s_6f70_total_bytes == 24);
    for (int i = 0; i < 6; i++) {
        assert(s_6f70_written_values[i] == 1000 + i * 10);
    }

    printf("EMOTIONAL_AI_SAVE_TEST_0_STREAM_WRITES_PASSED\n");
}

static void test_emotional_ai_save_personality_0() {
    EmotionalAI ai;
    memset(&ai, 0xFF, sizeof(ai));

    func_00140670(&ai, 0);

    assert(ai.m_fieldB0[0] == 100);
    assert(ai.m_fieldB0[1] == 10);
    assert(ai.m_fieldB0[2] == 0);
    assert(ai.m_fieldB0[3] == 10);
    assert(ai.m_fieldB0[4] == 10);
    assert(ai.m_fieldB0[5] == 70);

    printf("EMOTIONAL_AI_SAVE_TEST_1_PERSONALITY_0_PASSED\n");
}

static void test_emotional_ai_save_personality_1() {
    EmotionalAI ai;
    memset(&ai, 0xFF, sizeof(ai));

    func_00140670(&ai, 1);

    assert(ai.m_fieldB0[0] == 10);
    assert(ai.m_fieldB0[1] == 100);
    assert(ai.m_fieldB0[2] == 50);
    assert(ai.m_fieldB0[3] == 80);
    assert(ai.m_fieldB0[4] == 50);
    assert(ai.m_fieldB0[5] == 0);

    printf("EMOTIONAL_AI_SAVE_TEST_2_PERSONALITY_1_PASSED\n");
}

static void test_emotional_ai_save_personality_2() {
    EmotionalAI ai;
    memset(&ai, 0xFF, sizeof(ai));

    func_00140670(&ai, 2);

    assert(ai.m_fieldB0[0] == 20);
    assert(ai.m_fieldB0[1] == 50);
    assert(ai.m_fieldB0[2] == 100);
    assert(ai.m_fieldB0[3] == 50);
    assert(ai.m_fieldB0[4] == 60);
    assert(ai.m_fieldB0[5] == 10);

    printf("EMOTIONAL_AI_SAVE_TEST_3_PERSONALITY_2_PASSED\n");
}

static void test_emotional_ai_save_personality_3() {
    EmotionalAI ai;
    memset(&ai, 0xFF, sizeof(ai));

    func_00140670(&ai, 3);

    assert(ai.m_fieldB0[0] == 10);
    assert(ai.m_fieldB0[1] == 70);
    assert(ai.m_fieldB0[2] == 50);
    assert(ai.m_fieldB0[3] == 100);
    assert(ai.m_fieldB0[4] == 50);
    assert(ai.m_fieldB0[5] == 20);

    printf("EMOTIONAL_AI_SAVE_TEST_4_PERSONALITY_3_PASSED\n");
}

static void test_emotional_ai_save_personality_4() {
    EmotionalAI ai;
    memset(&ai, 0xFF, sizeof(ai));

    func_00140670(&ai, 4);

    assert(ai.m_fieldB0[0] == 20);
    assert(ai.m_fieldB0[1] == 70);
    assert(ai.m_fieldB0[2] == 60);
    assert(ai.m_fieldB0[3] == 50);
    assert(ai.m_fieldB0[4] == 100);
    assert(ai.m_fieldB0[5] == 0);

    printf("EMOTIONAL_AI_SAVE_TEST_5_PERSONALITY_4_PASSED\n");
}

static void test_emotional_ai_save_personality_5() {
    EmotionalAI ai;
    memset(&ai, 0xFF, sizeof(ai));

    func_00140670(&ai, 5);

    assert(ai.m_fieldB0[0] == 90);
    assert(ai.m_fieldB0[1] == 0);
    assert(ai.m_fieldB0[2] == 50);
    assert(ai.m_fieldB0[3] == 30);
    assert(ai.m_fieldB0[4] == 10);
    assert(ai.m_fieldB0[5] == 100);

    printf("EMOTIONAL_AI_SAVE_TEST_6_PERSONALITY_5_PASSED\n");
}

static void test_emotional_ai_save_personality_out_of_range() {
    EmotionalAI ai;
    memset(&ai, 0, sizeof(ai));
    for (int i = 0; i < 6; i++) {
        ai.m_fieldB0[i] = 777;
    }

    func_00140670(&ai, -1);
    for (int i = 0; i < 6; i++) {
        assert(ai.m_fieldB0[i] == 777);
    }

    func_00140670(&ai, 6);
    for (int i = 0; i < 6; i++) {
        assert(ai.m_fieldB0[i] == 777);
    }

    func_00140670(&ai, 100);
    for (int i = 0; i < 6; i++) {
        assert(ai.m_fieldB0[i] == 777);
    }

    printf("EMOTIONAL_AI_SAVE_TEST_7_PERSONALITY_OUT_OF_RANGE_PASSED\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: test mode selector argument required (0-7)\n");
        return 1;
    }
    char *endptr = 0;
    long mode_l = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Error: invalid test mode format '%s'\n", argv[1]);
        return 1;
    }
    int mode = (int)mode_l;
    if (mode == 0) test_emotional_ai_save_stream_writes();
    else if (mode == 1) test_emotional_ai_save_personality_0();
    else if (mode == 2) test_emotional_ai_save_personality_1();
    else if (mode == 3) test_emotional_ai_save_personality_2();
    else if (mode == 4) test_emotional_ai_save_personality_3();
    else if (mode == 5) test_emotional_ai_save_personality_4();
    else if (mode == 6) test_emotional_ai_save_personality_5();
    else if (mode == 7) test_emotional_ai_save_personality_out_of_range();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
