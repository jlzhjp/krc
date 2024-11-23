#include <stdio.h>

#define MAXLINE 1000

int _getline(char line[], int maxline);
void reverse(char s[], int len);

int main()
{
    char line[MAXLINE];
    int len = 0;
    while ((len = _getline(line, MAXLINE)) > 0) {
        if (line[len - 1] == '\n') line[--len] = '\0';
        reverse(line, len);
        printf("%s\n", line);
    }

    return 0;
}

/* _getline: read a line into s, return length */
int _getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

void reverse(char s[], int len)
{
    int i = 0, j = len - 1;
    while (i < j) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        ++i;
        --j;
    }
}