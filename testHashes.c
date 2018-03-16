#include "common.h"
#include "hash.h"
#include <klee/klee.h>

void get_hashes(char * message, uint8_t suffix, uint16_t prefix)
{
    /*char message[] = "Hello Bitcoin!";*/
    /*uint16_t prefix = 0xd17f;*/
    /*uint8_t suffix = 0x8c;*/
    /*uint8_t suffix = s;*/
    /*uint16_t prefix = p;*/

    uint8_t digest[32];
    uint8_t ser[35];

    const char sha256_exp[] = "518ad5a375fa52f84b2b3df7933ad685eb62cf69869a96731561f94d10826b5c";
    const char hash256_exp[] = "90986ea4e28b847cc7f9beba87ea81b221ca6eaf9828a8b04c290c21d891bcda";
    const char ser_exp[] = "7fd190986ea4e28b847cc7f9beba87ea81b221ca6eaf9828a8b04c290c21d891bcda8c";

    /* */

    /* SHA-2 digest is big-endian */

    bbp_sha256(digest, (uint8_t *)message, strlen(message));
    bbp_print_hex("SHA256(message)      ", digest, 32);
    printf("SHA256(message) (exp): %s\n", sha256_exp);

    bbp_sha256(digest, digest, 32);
    bbp_print_hex("hash256(message)      ", digest, 32);
    printf("hash256(message) (exp): %s\n", hash256_exp);

    *(uint16_t *)(ser) = bbp_eint16(BBP_LITTLE, prefix);
    memcpy(ser + 2, digest, 32);
    *(ser + 2 + 32) = suffix;

    bbp_print_hex("ser      ", ser, sizeof(ser));
    printf("ser (exp): %s\n", ser_exp);
}

int main(int argc, char *argv[])
{
    /*The input regular expression.*/
    char message[32];
    klee_make_symbolic(message, sizeof message, "message");
    /*message[32 - 1] = '\0';*/

    uint8_t s;
    klee_make_symbolic(&s, sizeof(s), "s");

    uint16_t p;
    klee_make_symbolic(&p, sizeof(p), "p");

    get_hashes(message, s, p);

    return 0;
}
