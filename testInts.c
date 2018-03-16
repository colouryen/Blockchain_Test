#include "common.h"
#include <klee/klee.h>

int main2(uint8_t a, uint16_t b, uint32_t c, uint64_t d) {
    uint8_t n8 = a;
    uint16_t n16 = b;
    uint32_t n32 = c;
    uint64_t n64 = d;
    uint8_t ser[15];

    const char ser_exp[] = "0123456789abcdef123456789abcde";

    /* */

    *ser = n8;
    *(uint16_t *)(ser + 1) = bbp_eint16(BBP_LITTLE, n16);
    *(uint32_t *)(ser + 3) = bbp_eint32(BBP_LITTLE, n32);
    *(uint64_t *)(ser + 7) = bbp_eint64(BBP_LITTLE, n64);

    bbp_print_hex("ser      ", ser, sizeof(ser));
    printf("ser (exp): %s\n", ser_exp);

    return 0;
}



int main() {

    uint8_t a;
    uint16_t b;
    uint32_t c;
    uint64_t d;

    klee_make_symbolic(&a, sizeof(a), "a");
    klee_make_symbolic(&b, sizeof(b), "b");
    klee_make_symbolic(&c, sizeof(c), "c");
    klee_make_symbolic(&d, sizeof(d), "d");

    return main2(a,b,c,d);

}