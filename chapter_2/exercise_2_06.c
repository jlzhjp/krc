#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned mask = ~(~(unsigned)0 >> n) >> p;
    return (x & ~mask) | (y << (32 - p - n));
}

int main()
{
    printf("%8x\n", setbits(0xffffffff, 4, 12, 0xabc));

    return 0;
}