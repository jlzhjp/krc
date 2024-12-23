#include <stdio.h>

#define swap(t, x, y) { t temp = x; x = y; y = temp; }

int main()
{
    int x = 5;
    int y = 10;
    printf("before swap: x: %d, y: %d\n", x, y);
    swap(int, x, y);
    printf("after swap: x: %d, y: %d\n", x, y);
    return 0;
}