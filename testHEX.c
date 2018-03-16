#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    uint8_t priv_bytes[32];
    int i;
    for(i = 0; i < 32; i++)
    {
        *(priv_bytes + i) = rand() % 256;
        printf("priv_bytes[%d] : %x \n", i, *(priv_bytes + i));
    }

    uint16_t x;
    uint16_t y;
    x = rand() % 256 * 256;
    printf("x : %04x \n", x);

    /*uint8_t priv_bytes[32] = {
        0x16, 0x26, 0x07, 0x83, 0xe4, 0x0b, 0x16, 0x73,
        0x16, 0x73, 0x62, 0x2a, 0xc8, 0xa5, 0xb0, 0x45,
        0xfc, 0x3e, 0xa4, 0xaf, 0x70, 0xf7, 0x27, 0xf3,
        0xf9, 0xe9, 0x2b, 0xdd, 0x3a, 0x1d, 0xdc, 0x42
    };*/

    /*printf("priv_bytes : %x \n", *(priv_bytes + 4));*/

    return 0;
}
