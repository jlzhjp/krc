#include <stdio.h>
#include <string.h>

/** Write a function escape(s, t) that converts characters like
    newline and tab into visible escape sequences like \n and \t as it copies the
    string t to s. */
void escape(char s[], char t[], int maxlen);

int main()
{
    char s[1024] = "\tABC\n\tDEF\n\tGHI";
    char t[1024];
    escape(s, t, 1024);
    printf("%s", t);

    return 0;
}

void escape(char s[], char t[], int maxlen)
{
    int len = strnlen(s, maxlen);

    int j = 0;
    for (int i = 0; i < len; ++i) {
        switch (s[i]) {
        case '\n':
            t[j++] = '\\';
            t[j++] = 'n';
            break;
        case '\t':
            t[j++] = '\\';
            t[j++] = 't';
            break;
        default:
            t[j++] = s[i];
        }
    }
    t[j] = '\0';
}