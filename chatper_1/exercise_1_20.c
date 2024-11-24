#include <stdbool.h>
#include <stdio.h>

#define N 8

bool detab_line(void);

/* Write a program detab that replaces tabs in the input with
   the proper number of blanks to space to he next tab stop.
   Assume a fixed set of tab stops, say every n columns. */
int main(void)
{
    while (detab_line()) {
    }

    return 0;
}

bool detab_line(void)
{
    int c;
    int counter = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        counter = (counter + 1) % N;
        if (c == '\t') {
            for (int i = 0; i < N - counter; ++i) {
                putchar(' ');
            }
        } else {
            putchar(c);
        }
    }
    if (c == '\n') {
        putchar('\n');
        return true;
    } else {
        return false;
    }
}
