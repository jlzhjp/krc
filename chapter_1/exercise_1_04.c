#include <stdio.h>

/* Write a program to print the corresponding Celsius to Fahrenheit table. */
int main()
{
    int lower = 0, upper = 100, step = 10;

    printf("%3s %6s\n", "C", "F");

    float celsius = lower;
    while (celsius <= upper) {
        float fahr = (celsius * 9.0 / 5.0) + 32;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}