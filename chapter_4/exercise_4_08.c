#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXOP  100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char[]);
void push(double);
double pop(void);

int getch(void);
void ungetch(int);

int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0) {
                push(pop() / op2);
            } else {
                printf("error: zero divisor\n");
            }
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unkown command %s\n", s);
            break;
        }
    }

    return 0;
}

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t') {
    }

    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;

    i = 0;

    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch())) {
        }
    }
    if (c == '.') {
        while (isdigit(s[++i] = c = getch())) {
        }
    }

    s[i] = '\0';

    if (c != EOF) {
        ungetch(c);
    }

    return NUMBER;
}

#define BUFSIZE 100

char buf = -1;

int getch(void)
{
    if (buf == -1) return getchar();
    char res = buf;
    buf = -1;
    return res;
}

void ungetch(int c) /* push character back on input */
{
    if (buf != -1) {
        printf("ungetch: too many characters\n");
    } else {
        buf = c;
    }
}