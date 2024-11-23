#include <stdio.h>

#define IN  1
#define OUT 0

/* How would you test the word count program?
   What kind of input are most likely to uncover bugs if there are any? */
int main()
{
    int nl = 0, nw = 0, nc = 0, state = OUT;

    int c = 0;
    while ((c = getchar()) != EOF) {
        ++nc;

        if (c == '\n') ++nl;

        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d", nl, nw, nc);
}