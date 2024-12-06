#include <stdbool.h>
#include <stdio.h>

int any(char s1[], char s2[])
{
    bool t[128];

    for (int i = 0; i < 128; ++i) {
        t[i] = false;
    }

    for (int i = 0; s2[i] != '\0'; ++i) {
        t[(int)s2[i]] = true;
    }

    for (int i = 0; s1[i] != '\0'; ++i) {
        if (t[(int)s1[i]]) {
            return i;
        }
    }

    return -1;
}

/** Write the function any(s1, s2), which returns the first location
    in the string s1 where any character from the string s2 occurs, or -1 if s1
    contains no characters from s2. (The standard library function strpbrk does
    the same job but return a pointer to the location.) */
int main()
{
    printf("%d\n", any("abcde", "eb"));
    printf("%d\n", any("abcde", "fg"));

    return 0;
}