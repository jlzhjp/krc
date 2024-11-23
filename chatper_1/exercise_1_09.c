#include <stdio.h>

#define IN  1
#define OUT 0

/* Write a program to copy its input to its output,
   replacing each string of one or more blanks by a single blank. */
int main()
{
    int state = OUT;

    int c = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (state == IN) putchar(' ');
            state = OUT;
        } else {
            putchar(c);
            state = IN;
        }
    }
}
