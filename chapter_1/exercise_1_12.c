#include <stdio.h>

#define IN  1
#define OUT 0

/* Write a program that prints its input one word per line. */
int main()
{
    int state = OUT;

    int c = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (state == IN) putchar('\n');
            state = OUT;
        } else {
            putchar(c);
            state = IN;
        }
    }
}