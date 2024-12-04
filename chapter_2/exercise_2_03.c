#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int htoi(char s[], int limit);

int main()
{
    printf("  0xff - %d\n", htoi("0xff", INT_MAX));
    printf("0x88fe - %d\n", htoi("0x88fe", INT_MAX));
    return 0;
}

int htoi(char s[], int limit)
{
    if (s[0] != '0' || (s[1] != 'x' && s[1] != 'X')) {
        fprintf(stderr, "hex format error\n");
        exit(1);
    }

    int res = 0;
    int base = 1;
    for (size_t i = strnlen(s, limit) - 1; i >= 2; --i, base *= 0x10) {
        if ('0' <= s[i] && s[i] <= '9') {
            res += (s[i] - '0') * base;
        } else if ('a' <= s[i] && s[i] <= 'f') {
            res += (s[i] - 'a' + 10) * base;
        } else if ('A' <= s[i] && s[i] <= 'F') {
            res += (s[i] - 'A' + 10) * base;
        } else {
            fprintf(stderr, "hex format error\n");
            exit(1);
        }
    }

    return res;
}