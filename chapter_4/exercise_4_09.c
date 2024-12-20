#include <limits.h>
#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

int getch(void);
void ungetch(int c);
void ungets(char s[], int maxlen);

int main()
{
    ungetch('d');
    ungetch('l');
    ungetch('r');
    ungetch('o');
    ungetch('w');

    ungetch(EOF);

    ungetch('o');
    ungetch('l');
    ungetch('l');
    ungetch('e');
    ungetch('h');

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
    if (buf[bufp] == EOF) {
        return;
    }

    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}