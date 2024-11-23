#include <stdio.h>

/* Rewrite the temperature conversion program of Section 1.2 to use a function for conversion. */

float fahr2celsius(float fahr);

int main()
{
    int lower = 0, upper = 300, step = 20;

    printf("%3s %6s\n", "F", "C");

    float fahr = lower;
    while (fahr <= upper) {
        float celsius = fahr2celsius(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

float fahr2celsius(float fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}