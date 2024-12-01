#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define LIMIT   10
#define MAXLINE 1024

bool fold_line(void)
{
    char line[MAXLINE];
    int break_pos = -1;
    int current_pos = -1;
    int c;
    while ((c = getchar()) != EOF && c != '\n') {
        line[++current_pos] = c;

        if (current_pos > 0 && isspace(c) && !isspace(line[current_pos - 1])) {
            break_pos = current_pos - 1;
        }

        if (current_pos > LIMIT && break_pos > 0) {
            while (current_pos > break_pos) {
                ungetc(line[current_pos--], stdin);
            }
            line[current_pos + 1] = '\0';
            printf("%s\n", line);
            return true;
        }
    }

    if (current_pos > 0) {
        line[current_pos + 1] = '\0';
        printf("%s", line);
    }

    return false;
}

/* Write a program to "fold" long input lines into two or more
   shorter lines after the last non-blank character that occurs before the n-th
   column of input. Make sure your program does something intelligent with very
   long lines, and if there are no blanks or tabs before the specified column. */
int main(void)
{
    while (fold_line()) {
    }

    return 0;
}