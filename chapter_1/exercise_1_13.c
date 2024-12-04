#include <stdio.h>

#define MAXLEN 20
#define IN     0
#define OUT    1

/* Write a program to print a histogram of the lengths of words in its input.
   It is easy to draw the histogram with the bars horizontal;
   a vertical orientation is more challenging. */
int main()
{
    int nlen[MAXLEN];

    for (int i = 0; i < MAXLEN; ++i) nlen[i] = 0;

    int len = 0, c = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == '\t' || c == ' ') {
            if (len != 0) ++nlen[len - 1];
            len = 0;
        } else {
            ++len;
        }
    }

    for (int i = 0; i < MAXLEN; ++i) {
        printf("%2d ", i + 1);
        for (int j = 0; j < nlen[i]; ++j) putchar('-');
        putchar('\n');
    }
}