#include <ctype.h>
#include <stdio.h>

double dpow(double base, int exp);

/* convert string s to double */
double atof(char s[]);

int main()
{
    printf("%.8lf\n", atof("123.45e-6"));

    return 0;
}

double atof(char s[])
{
    int i;
    for (i = 0; isspace(s[i]); i++) {
    }

    int sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        ++i;

    int val;
    for (val = 0.0; isdigit(s[i]); ++i)
        val = 10.0 * val + (s[i] - '0');

    if (s[i] == '.')
        ++i;

    int power;
    for (power = 1.0; isdigit(s[i]); ++i) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    int esign = 1, eval = 0;
    if (toupper(s[i]) == 'E') {
        ++i;

        if (s[i] == '-') esign = -1;
        if (s[i] == '+' || s[i] == '-') ++i;

        for (eval = 0; isdigit(s[i]); ++i) {
            eval = eval * 10 + (s[i] - '0');
        }
    }

    if (esign > 0) {
        return sign * val / (double)power * dpow(10, eval);
    }
    return sign * val / (double)power * dpow(0.1, eval);
}

double dpow(double base, int exp)
{
    if (exp < 0) return 1 / dpow(base, -exp);
    if (exp == 0) return 1;

    if (exp % 2 == 0) return dpow(base * base, exp / 2);
    return base * dpow(base, exp - 1);
}
