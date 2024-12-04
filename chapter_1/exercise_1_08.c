#include <stdio.h>

/* Write a program to count blanks, tabs, and newlines */
int main()
{
    int nb = 0, nt = 0, nn = 0;

    int c = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++nb;
        } else if (c == '\t') {
            ++nt;
        } else if (c == '\n') {
            ++nn;
        }
    }

    int w = 8;
    printf("%*s %*s %*s\n", w, "BLANKS", w, "TABS", w, "NEWLINES");
    printf("%*d %*d %*d\n", w, nb, w, nt, w, nn);
}