#include "common.h"
#include <klee/klee.h>

void get_int(int n)
{
    uint8_t ser[15];

    uint8_t n8;
    srand(n);
    n8 = rand() % 256;
    /*printf("n8 : %02x \n", n8);*/

    uint16_t n16;
    n16 = n8 + n8;
    /*printf("x : %04x \n", x);*/

    uint32_t n32;
    n32 = n16 + n16;
    /*n32 = rand() % 256 * 256 * 256;*/
    /*printf("x : %08x \n", x);*/

    uint64_t n64;
    n64 = n32 + n32;
    /*printf("x : %10x \n", x);*/


    const char ser_exp[] = "0123456789abcdef123456789abcde";

    /* */

    *ser = n8;
    *(uint16_t *)(ser + 1) = bbp_eint16(BBP_LITTLE, n16);
    *(uint32_t *)(ser + 3) = bbp_eint32(BBP_LITTLE, n32);
    *(uint64_t *)(ser + 7) = bbp_eint64(BBP_LITTLE, n64);

    bbp_print_hex("ser      ", ser, sizeof(ser));
    printf("ser (exp): %s\n", ser_exp);
}

int main()
{
    int a;
    klee_make_symbolic(&a, sizeof(a), "a");
    /*
    int b;
    klee_make_symbolic(&b, sizeof(b), "b");

    int c;
    klee_make_symbolic(&c, sizeof(c), "c");

    int d;
    klee_make_symbolic(&d, sizeof(d), "d"); 
*/
    get_int(a);

    return 0;
}
