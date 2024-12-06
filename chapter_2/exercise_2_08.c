#include <stdio.h>

unsigned rightrot(unsigned x, int n)
{
    n = n % 32;
    unsigned low = x & ~(~(unsigned)0 << n);
    return (x >> n) | (low << (32 - n));
}

int main()
{
    printf("%x", rightrot(0x12345678, 12));

    return 0;
}