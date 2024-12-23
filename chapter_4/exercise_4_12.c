#include <stdio.h>

void itoa(int n, char s[]);

int main()
{
    char s[100];
    itoa(12345, s);
    printf("%s\n", s);
    itoa(-12345, s);
    printf("%s\n", s);
    return 0;
}

void itoa_inner(int n, char **s)
{
    if (n / 10) {
        itoa_inner(n / 10, s);
    }

    *((*s)++) = n % 10 + '0';
}

void itoa(int n, char s[])
{
    char *p = s;
    if (n < 0) {
        *p++ = '-';
        n = -n;
    }
    itoa_inner(n, &p);
}