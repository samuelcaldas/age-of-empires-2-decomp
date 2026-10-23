#include <assert.h>
#include <stdio.h>
#include <string.h>

/* Declarations for MSL string routines */
char *msl_strcpy(char *dest, const char *src);
char *msl_strcat(char *dest, const char *src);
int msl_strcmp(const char *s1, const char *s2);

int main(int argc, char **argv) {
    char buf[256];
    char *ret;

    /* --- msl_strcpy tests --- */
    /* Empty string */
    buf[0] = 'X';
    ret = msl_strcpy(buf, "");
    assert(ret == buf);
    assert(buf[0] == '\0');

    /* Short string */
    ret = msl_strcpy(buf, "hello");
    assert(ret == buf);
    assert(strcmp(buf, "hello") == 0);

    /* Longer string across 16-byte alignment boundaries */
    ret = msl_strcpy(buf, "The quick brown fox jumps over the lazy dog 1234567890!");
    assert(ret == buf);
    assert(strcmp(buf, "The quick brown fox jumps over the lazy dog 1234567890!") == 0);

    /* Unaligned destination */
    ret = msl_strcpy(buf + 1, "unaligned test");
    assert(ret == buf + 1);
    assert(strcmp(buf + 1, "unaligned test") == 0);

    /* --- msl_strcat tests --- */
    /* Append to empty string */
    buf[0] = '\0';
    ret = msl_strcat(buf, "initial");
    assert(ret == buf);
    assert(strcmp(buf, "initial") == 0);

    /* Append empty string */
    ret = msl_strcat(buf, "");
    assert(ret == buf);
    assert(strcmp(buf, "initial") == 0);

    /* Append second string */
    ret = msl_strcat(buf, " added");
    assert(ret == buf);
    assert(strcmp(buf, "initial added") == 0);

    /* Multiple concatenations across alignment */
    buf[0] = '\0';
    msl_strcat(buf, "12345678");
    msl_strcat(buf, "90abcdef");
    msl_strcat(buf, "ghijklmn");
    assert(strcmp(buf, "1234567890abcdefghijklmn") == 0);

    /* --- msl_strcmp tests --- */
    /* Equal strings */
    assert(msl_strcmp("", "") == 0);
    assert(msl_strcmp("a", "a") == 0);
    assert(msl_strcmp("hello", "hello") == 0);
    assert(msl_strcmp("12345678901234567890", "12345678901234567890") == 0);

    /* Differing at start */
    assert(msl_strcmp("abc", "bbc") < 0);
    assert(msl_strcmp("bbc", "abc") > 0);

    /* Differing at end */
    assert(msl_strcmp("abcd", "abce") < 0);
    assert(msl_strcmp("abce", "abcd") > 0);

    /* Differing lengths / prefixes */
    assert(msl_strcmp("abc", "abcd") < 0);
    assert(msl_strcmp("abcd", "abc") > 0);

    /* Unsigned char distinction: \x80 should be > \x01 */
    assert(msl_strcmp("\x80", "\x01") > 0);
    assert(msl_strcmp("\x01", "\x80") < 0);

    printf("MSL_STRING_TEST_PASSED\n");
    return 0;
}
