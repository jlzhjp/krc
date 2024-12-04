#include <stdio.h>

#define MAXLINE 32

int _getline(char line[], int maxline);

/* Write a loop equivalent to the for loop above without using && or ||. */
int main()
{
    char s[MAXLINE];
    while (_getline(s, MAXLINE)) {
        printf("%s", s);
    }
    return 0;
}

int _getline(char s[], int lim)
{
    int c, i;

    i = 0;
    for (;;) {
        if (i < lim - 1) {
            if ((c = getchar()) != EOF) {
                if (c != '\n') {
                    s[i] = c;
                    ++i;
                    continue;
                }
            }
        }
        break;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}