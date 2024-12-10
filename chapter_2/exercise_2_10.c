#include <stdio.h>

char lower(char x)
{
    return 'A' <= x && x <= 'Z' ? x - 'A' + 'a' : x;
}

int main()
{
    printf("%c, %c", lower('f'), lower('F'));
    return 0;
}