#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char int2char(int n);
void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
    int x = 255;
    char s[32];
    itob(x, s, 16);
    printf("%s", s);

    return 0;
}

void reverse(char s[])
{
    int c;
    for (int i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
        c = s[i], s[i] = s[j], s[j] = c;
    }
}

void itob(int n, char s[], int b)
{
    if (b < 2 || b > 36) {
        fprintf(stderr, "unsupported base %d", b);
        exit(1);
    }

    int sign = n;
    int i = 0;
    // at least one character must be installed in the array
    do {
        s[i++] = int2char(abs(n % b));
    } while ((n /= b) != 0);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

char int2char(int n)
{
    if (0 <= n && n <= 9) return n + '0';
    return 'A' + n - 10;
}