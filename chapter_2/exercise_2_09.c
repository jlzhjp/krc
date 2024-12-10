#include <stdio.h>

int bitcount(unsigned x)
{
    int b = 0;
    while (x) ++b, x &= (x - 1);
    return b;
}

/** In a two's complement number system, x &= (x - 1) deletes the
    rightmost 1-bit in x. Explain why. Use this observation to write a faster
    version of bitcount */
int main()
{
    //   x: 0x10101000
    //  -1: 0x11111111
    //      0x10100111
    // & x: 0x10101000
    //      0x10100000

    printf("%d", bitcount(0xffff0001));

    return 0;
}