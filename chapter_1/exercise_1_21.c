#include <stdbool.h>
#include <stdio.h>

#define N  8
#define LF 0
#define IN 1

int entab_stop();
bool entab_line();

/* Write a program entab that replaces strings of blanks by the
   minimum number of tabs and blanks to achieve the same spacing. Use the
   same tab stops for detab. When either a tab or a single blank suffice
   to reach a tab stop, which should be given preference? */
int main(void)
{
    while (entab_line()) {
    }

    return 0;
}

int entab_stop()
{
    char stop_buf[N];
    int cur = 0, i = 0;
    char c;
    for (i = 0; i < N; ++i) {
        c = getchar();
        if (c == '\n' || c == EOF) {
            break;
        }
        stop_buf[cur++] = c;
    }

    int j;
    for (j = 0; j < i && stop_buf[j] != EOF; ++j) {
        putchar(stop_buf[j]);
    }

    if (j != i) putchar('\t');

    if (c == '\n') {
        putchar('\n');
        return LF;
    } else if (c == EOF) {
        return EOF;
    } else {
        return IN;
    }
}

bool entab_line()
{
    int res;
    while ((res = entab_stop()) == IN) {
    }
    if (res == EOF) return false;
    return true;
}
