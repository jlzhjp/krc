#include <stdio.h>

void reverse(char s[], int len);

int main()
{
    char s[] = "hello";
    reverse(s, 5);
    printf("%s\n", s);
}

void reverse(char s[], int len)
{
    if (len == 0 || len == 1) {
        return;
    }
    int t;
    t = s[0], s[0] = s[len - 1], s[len - 1] = t;
    reverse(s + 1, len - 2);
}