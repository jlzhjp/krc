#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_LIMIT 64

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

bool is_paired(char left, char right);

/* Write a program to check a C program for rudimentary syntax
   errors like unbalanced parentheses, brackets and braces. Don't forget about
   quotes, both single and double, escape sequences, and comments. (This program
   is hard if you do it in full generality). */
int main()
{
    enum State s = INIT;
    char stack[STACK_LIMIT];
    int stack_top = 0;

    int ch;
    while ((ch = getchar()) != EOF) {
        switch (s) {
        case INIT:
            if (ch == '/') {
                s = WAITING_ASTERISK;
            } else if (ch == '"') {
                s = IN_STRING;
            } else if (ch == '\'') {
                s = IN_CHAR;
            } else if (ch == '(' || ch == '[' || ch == '{') {
                stack[stack_top++] = ch;
            } else if (ch == ')' || ch == ']' || ch == '}') {
                char left_pair = stack[--stack_top];
                if (!is_paired(left_pair, ch)) {
                    fprintf(stderr, "unbalanced\n");
                    exit(1);
                }
            }
            break;
        case WAITING_ASTERISK:
            if (ch == '*') {
                s = IN_COMMENT;
            } else if (ch == '/') {
            } else {
                s = INIT;
            }
            break;
        case IN_COMMENT:
            if (ch == '*') {
                s = WAITING_SLASH;
            } else if (ch == '/') {
                s = IN_COMMENT_WAITING_ASTERISK;
            }
            break;
        case IN_COMMENT_WAITING_ASTERISK:
            if (ch == '*') {
                fprintf(stderr, "comments do not nest");
                exit(1);
            } else if (ch == '/') {
            } else {
                s = IN_COMMENT;
            }
        case WAITING_SLASH:
            if (ch == '/') {
                s = INIT;
            } else if (ch == '*') {
            } else {
                s = IN_COMMENT;
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
    }

    if (stack_top != 0) {
        fprintf(stderr, "unbalanced\n");
        exit(1);
    }

    return 0;
}

bool is_paired(char left_pair, char right_pair)
{
    if (left_pair == '(' && right_pair == ')') return true;
    if (left_pair == '[' && right_pair == ']') return true;
    if (left_pair == '{' && right_pair == '}') return true;
    return false;
}