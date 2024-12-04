#include <stdio.h>
#include <stdlib.h>

enum State {
    INIT,
    WAITING_ASTERISK,
    IN_COMMENT,
    IN_COMMENT_WAITING_ASTERISK,
    WAITING_SLASH,
    IN_STRING,
    IN_CHAR,
    CHAR_ESCAPE,
    STRING_ESCAPE,
};

/* Write a program to remove all coments from a C program.
   Don't forget to handle quoted strings and character constants properly.
   C comments do not nest. */
int main()
{
    enum State s = INIT;

    int ch;
    while ((ch = getchar()) != EOF) {
        switch (s) {
        case INIT:
            if (ch == '/') {
                s = WAITING_ASTERISK;
                continue;
            } else if (ch == '"') {
                s = IN_STRING;
            } else if (ch == '\'') {
                s = IN_CHAR;
            }
            break;
        case WAITING_ASTERISK:
            if (ch == '*') {
                s = IN_COMMENT;
                continue;
            } else if (ch == '/') {
                putchar('/');
                continue;
            } else {
                putchar('/');
                s = INIT;
            }
            break;
        case IN_COMMENT:
            if (ch == '*') {
                s = WAITING_SLASH;
                continue;
            } else if (ch == '/') {
                s = IN_COMMENT_WAITING_ASTERISK;
                continue;
            } else {
                continue;
            }
            break;
        case IN_COMMENT_WAITING_ASTERISK:
            if (ch == '*') {
                fprintf(stderr, "comments do not nest\n");
                exit(1);
            } else if (ch == '/') {
                continue;
            } else {
                s = IN_COMMENT;
            }
        case WAITING_SLASH:
            if (ch == '/') {
                s = INIT;
                continue;
            } else if (ch == '*') {
                continue;
            } else {
                s = IN_COMMENT;
                continue;
            }
            break;
        case IN_STRING:
            if (ch == '"') {
                s = INIT;
            } else if (ch == '\\') {
                s = STRING_ESCAPE;
            }
            break;
        case IN_CHAR:
            if (ch == '\'') {
                s = INIT;
            } else if (ch == '\\') {
                s = CHAR_ESCAPE;
            }
            break;
        case CHAR_ESCAPE:
            s = IN_CHAR;
            break;
        case STRING_ESCAPE:
            s = IN_STRING;
            break;
        }

        putchar(ch);
    }
}