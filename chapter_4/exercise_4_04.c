#include <stdio.h>

void push(double);
double pop(void);
double peek(void);
void clear();

int main()
{
    push(1.0);
    push(2.0);
    push(3.0);
    printf("peek: %f\n", peek());
    clear();
    pop();
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

double peek(void)
{
    if (sp > 0) {
        return val[sp - 1];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void clear(void)
{
    sp = 0;
}