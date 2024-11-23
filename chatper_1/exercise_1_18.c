#include <stdio.h>

#define MAXLINE 1000

int _getline(char line[], int maxline);
void copy(char to[], char from[]);

/* Write a program to remove trailing blanks and tabs
   and from each line of input, and to delete entirely blank lines. */
int main()
{
    char line[MAXLINE];
    int len = 0;
    while ((len = _getline(line, MAXLINE)) > 0) {
        while (line[len - 1] == '\n' || line[len - 1] == ' ' || line[len - 1] == '\t') {
            line[--len] = '\0';
        }
        printf("%s\n", line);
    }
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