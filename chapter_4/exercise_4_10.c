#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER '0' /* signal that a number was found */

double evalline(char *line);
int getop(char **line, char buf[]);
void push(double);
double pop(void);

int main()
{
    char *p = NULL;
    size_t s = 0;

    while (getline(&p, &s, stdin) > 0) {
        printf("\t%.8g\n", evalline(p));
    }

    return 0;
}

double evalline(char *line)
{
    double op2;
    char buf[1024];
    for (;;) {
        int type = getop(&line, buf);
        if (type == '\n') break;

        switch (type) {
        case NUMBER:
            push(atof(buf));
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
        default:
            printf("error: unkown command %s\n", buf);
            break;
        }
    }
    return pop();
}

int getop(char **line, char buf[])
{
    int c;
    char *it = *line;

    while ((buf[0] = c = *(it++)) == ' ' || c == '\t') {
    }

    buf[1] = '\0';

    if (!isdigit(c) && c != '.') {
        *line = it;
        return c;
    }

    int j = 0;
    if (isdigit(c)) {
        while (isdigit(buf[++j] = c = *(it++))) {
        }
    }
    if (c == '.') {
        while (isdigit(buf[++j] = c = *(it++))) {
        }
    }

    buf[j] = '\0';

    *line = --it;

    return NUMBER;
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
