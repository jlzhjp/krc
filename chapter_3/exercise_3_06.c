#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char s[]);
void itoa(int n, char s[], int minwidth);

int main()
{
    char s[32];
    itoa(INT_MIN, s, 12);
    printf("%s\n", s);
    itoa(72, s, 12);
    printf("%s\n", s);

    return 0;
}

void reverse(char s[])
{
    int c;
    for (int i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
        c = s[i], s[i] = s[j], s[j] = c;
    }
}

void itoa(int n, char s[], int minwidth)
{
    int sign = n;
    int i = 0;
    // at least one character must be installed in the array
    do {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);

    if (sign < 0)
        s[i++] = '-';

    while (i < minwidth) {
        s[i++] = ' ';
    }

    s[i] = '\0';
    reverse(s);
}
