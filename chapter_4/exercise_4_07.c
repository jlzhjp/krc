#include <limits.h>
#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

int getch(void);
void ungetch(int c);
void ungets(char s[], int maxlen);

int main()
{
    ungets("input your content: ", INT_MAX);
    char ch;
    while ((ch = getch()) != EOF) {
        putchar(ch);
    }

    return 0;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

void ungets(char s[], int maxlen)
{
    int len = strnlen(s, maxlen);
    for (int i = len - 1; i >= 0; --i) {
        ungetch(s[i]);
    }
}