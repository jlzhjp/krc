#include <stdio.h>

unsigned invert(unsigned x, int p, int n)
{
    unsigned mask = ~(~(unsigned)0 >> n) >> p;
    return x ^ mask;
}

int main()
{
    printf("%x\n", invert(0xffffffff, 4, 8));

    return 0;
}