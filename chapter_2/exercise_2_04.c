#include <stdio.h>
#include <stdbool.h>

void squeeze(char s1[], char s2[])
{
    bool t[128];

    for (int i = 0; i < 128; ++i) {
        t[i] = false;
    }

    for (int i = 0; s2[i] != '\0'; ++i) {
        t[(int)s2[i]] = true;
    }

        int i, j;
    for (i = j = 0; s1[i] != '\0'; ++i) {
        if (!t[(int)s1[i]]) {
            s1[j++] = s1[i];
        }
    }

    s1[j] = '\0';
}

int main()
{
    char s[16] = "abcabc";
    squeeze(s, "ab");
    printf("%s", s);
}