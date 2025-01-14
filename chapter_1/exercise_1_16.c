#include <stdio.h>

#define MAXLINE 10

int _getline(char line[], int maxline);
void copy(char to[], char from[]);

/* Revise the main routine of the longest-line program
   so it will correctly print the length of arbitrarily long input lines,
   and as much as possible of the text. */
int main()
{
    char line[MAXLINE];
    char longest[MAXLINE];

    int max = 0, len = 0;
    while ((len = _getline(line, MAXLINE)) > 0) {
        if (line[len - 2] != '\n') {
            int c;
            while ((c = getchar()) != EOF && c != '\n') ++len;
            if (c == '\n') ++len;
        }

        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) printf("text: %s\nlength: %d\n", longest, max);

    return 0;
}

/* _getline: read a line into s, return length */
int _getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

/* copy: copy `from` into `to`; assume to is big enough */
void copy(char to[], char from[])
{
    int i = 0;

    while ((to[i] = from[i]) != '\0') ++i;
}