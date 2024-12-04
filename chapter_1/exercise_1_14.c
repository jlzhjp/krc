#include <ctype.h>
#include <stdio.h>

/* Write a program to print a histogram of the
   frequencies of different characters in its input. */
int main()
{
    int count[26];

    for (int i = 0; i < 26; ++i)
        count[i] = 0;

    int c;
    while ((c = getchar()) != EOF)
        if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
            ++count[tolower(c) - 'a'];

    for (int i = 0; i < 26; ++i) {
        printf("%c", 'a' + i);
        for (int j = 0; j < count[i]; ++j)
            printf("-");
        printf("\n");
    }
}