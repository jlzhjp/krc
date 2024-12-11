#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/** Write a function for the other direction as well
    converting escape sequences into the real characters. */

void unescape(char s[], char t[], int maxlen)
{
    bool enter_escape = false;
    int len = strnlen(s, maxlen);
    int j = 0;
    for (int i = 0; i < len; ++i) {
        if (enter_escape) {
            switch (s[i]) {
            case 'n':
                t[j++] = '\n';
                break;
            case 't':
                t[j++] = '\t';
                break;
            }
            enter_escape = false;
            continue;
        }

        switch (s[i]) {
        case '\\':
            enter_escape = true;
            break;
        default:
            t[j++] = s[i];
            break;
        }
    }
}

int main()
{
    char s[1024] = "\\tABC\\n\\tDEF\\n\\tGHI\\n";
    char t[1024];
    unescape(s, t, 1024);
    printf("%s", t);
    return 0;
}