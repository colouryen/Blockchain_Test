#include "common.h"
#include "base58.h"
#include <klee/klee.h>

void get_base58(int n)
{
    /*uint8_t bytes[] = 
    {
        0x73, 0xb7, 0xb2, 0x1c, 0x26, 0xc1, 0x7b, 0x72,
        0x24, 0xdb, 0x60, 0xff, 0x7d, 0xd7, 0xe4, 0xc6,
        0x48, 0xf5, 0x6c, 0x70, 0x24, 0x4e, 0xa6, 0xc4,
        0xb6, 0x94, 0x1c, 0x0c, 0xbd, 0x16, 0x8c, 0x30
    };*/

    int w = n / 1.38;

    uint8_t bytes[w];
    int i;
    for(i = 0; i < n; i++)
    {
        *(bytes + i) = rand() % 256;
    }

    char * base58;

    const char base58_exp[] = "8niM7FzqQeaPANNtRwEtQGi37YRcFwx1UBZMX8214MVq";

    /* */

    base58 = bbp_base58(bytes, sizeof(bytes));
    bbp_print_hex("hex", bytes, sizeof(bytes));
    printf("base58      : %s\n", base58);
    printf("base58 (exp): %s\n", base58_exp);
    free(base58);
}

int main()
{
    int a;
    klee_make_symbolic(&a, sizeof(a), "a");

    get_base58(a);

    return 0;
}
