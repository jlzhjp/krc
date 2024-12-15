#include <stdio.h>
#include <string.h>

int strrindex(char s[], char t[]);

int main()
{
    printf("%d\n", strrindex("abcabcdabc", "abcd"));

    return 0;
}

int strrindex(char s[], char t[])
{
    int slen = strlen(s);
    int tlen = strlen(t);

    int i, j, k;
    for (i = slen - 1; i >= 0; --i) {
        for (j = i, k = tlen - 1; k >= 0 && s[j] == t[k]; --j, --k) {
        }
        if (k < 0) {
            return j + 1;
        }
    }

    return -1;
}
