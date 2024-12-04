#include <limits.h>
#include <stdio.h>

#define SIGNED_MAX(type)   (signed type)(((unsigned type)1 << (sizeof(signed type) * 8 - 1)) - 1)
#define SIGNED_MIN(type)   (signed type)((unsigned type)1 << (sizeof(signed type) * 8 - 1))
#define UNSIGNED_MAX(type) (~(unsigned type)0)
#define UNSIGNED_MIN(type) (unsigned type)0

/* Write a program to determine ranges of char, short, int,
   and long variables, both signed and unsigned, by printing appropriate
   values from standard headers and by direct computation. Harder if you compute
   them: determine the ranges of the various floating-point types. */
int main()
{
    printf("From Header: \n");
    printf("%14s: [%d, %d]\n", "signed char", SCHAR_MIN, SCHAR_MAX);
    printf("%14s: [%u, %u]\n", "unsigned char", 0, UCHAR_MAX);
    printf("%14s: [%d, %d]\n", "signed short", SHRT_MIN, SHRT_MAX);
    printf("%14s: [%u, %u]\n", "unsigned short", 0, USHRT_MAX);
    printf("%14s: [%d, %d]\n", "signed int", INT_MIN, INT_MAX);
    printf("%14s: [%u, %u]\n", "unsigned int", 0, UINT_MAX);
    printf("%14s: [%ld, %ld]\n", "signed long", LONG_MIN, LONG_MAX);
    printf("%14s: [%lu, %lu]\n", "unsigned long", 0UL, ULONG_MAX);

    putchar('\n');

    printf("Through Calculation: \n");
    printf("%14s: [%d, %d]\n", "signed char", SIGNED_MIN(char), SIGNED_MAX(char));
    printf("%14s: [%u, %u]\n", "unsigned char", UNSIGNED_MIN(char), UNSIGNED_MAX(char));
    printf("%14s: [%d, %d]\n", "signed short", SIGNED_MIN(short), SIGNED_MAX(short));
    printf("%14s: [%u, %u]\n", "unsigned short", UNSIGNED_MIN(short), UNSIGNED_MAX(short));
    printf("%14s: [%d, %d]\n", "signed int", SIGNED_MIN(int), SIGNED_MAX(int));
    printf("%14s: [%u, %u]\n", "unsigned int", UNSIGNED_MIN(int), UNSIGNED_MAX(int));
    printf("%14s: [%ld, %ld]\n", "signed long", SIGNED_MIN(long), SIGNED_MAX(long));
    printf("%14s: [%lu, %lu]\n", "unsigned long", UNSIGNED_MIN(long), UNSIGNED_MAX(long));
    return 0;
}
