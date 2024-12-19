#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP  100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

struct val {
    char type;
    union {
        char var;
        double n;
    } u;
};

int getop(char[]);

void push_n(double n);
void push_var(char var);
struct val pop(void);

double resolve(struct val val);
double assign(char var, struct val val);
void extract();

int getch(void);
void ungetch(int);

struct val op1, op2;
double n1, n2;

int main()
{
    int type;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push_n(atof(s));
            break;
        case '+':
            extract();
            push_n(n1 + n2);
            break;
        case '*':
            extract();
            push_n(n1 * n2);
            break;
        case '-':
            extract();
            push_n(n1 - n2);
            break;
        case '/':
            extract();
            if (n1 != 0.0)
            {
                push_n(n1 / n2);
            }
            else
            {
                printf("error: zero divisor\n");
            }
            break;
        case '=':
            op2 = pop();
            op1 = pop();
            if (op1.type == 'v') {
                assign(op1.u.var, op2);
            } else {
                printf("error: cannot assign to a non-variable\n");
            }
            push_n(resolve(op2));
            break;
        case '\n':
            assign('t', pop());
            struct val t = {'v', {.var = 't'}};
            printf("\t%.8g\n", resolve(t));
            break;
        default:
            if (type >= 'a' && type <= 'z') {
                push_var(type);
                break;
            }
            printf("error: unknown command %s\n", s);
            break;
        }
    }

    return 0;
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

#define MAXVAL 100
int sp = 0;

struct val sval[MAXVAL];

void push_n(double n)
{
    if (sp < MAXVAL) {
        struct val v = {'n', {.n = n}};
        sval[sp++] = v;
    } else {
        printf("error: stack full, can't push %g\n", n);
    }
}

void push_var(char var)
{
    if (sp < MAXVAL) {
        struct val v = {'v', {.var = var}};
        sval[sp++] = v;
    } else {
        printf("error: stack full, can't push %c\n", var);
    }
}

struct val pop(void)
{
    if (sp > 0) {
        return sval[--sp];
    } else {
        printf("error: stack empty\n");
        struct val res = {'n', {.n = 0}};
        return res;
    }
}

double v[26] = {0};

double resolve(struct val val)
{
    if (val.type == 'v') {
        return v[val.u.var - 'a'];
    } else {
        return val.u.n;
    }
}

double assign(char var, struct val val)
{
    v[var - 'a'] = resolve(val);
    return v[var - 'a'];
}

void extract()
{
    op2 = pop();
    op1 = pop();
    n1 = resolve(op1);
    n2 = resolve(op2);
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}