#include <ctype.h>
#include <stdio.h>

enum State {
    INIT,
    START,
    DASH_ACC,
    END,
};

void expand(char s1[], char s2[])
{
    int j = 0;
    enum State state = INIT;
    char start, end;

    for (int i = 0; s1[i] != '\0'; ++i) {
        switch (state) {
        case INIT:
            if (isalnum(s1[i])) {
                start = s1[i];
                state = START;
            } else {
                state = INIT;
            }
            break;
        case START:
            if (isalnum(s1[i])) {
                start = s1[i];
                state = START;
            } else if (s1[i] == '-') {
                state = DASH_ACC;
            } else {
                state = INIT;
            }
            break;
        case DASH_ACC:
            if (isalnum(s1[i])) {
                end = s1[i];
                state = END;
            } else {
                state = INIT;
            }
            break;
        case END:
            j -= 3;
            for (char ch = start; ch <= end; ++ch) {
                s2[j++] = ch;
            }
            state = INIT;
            i -= 1; // do not consume character
            continue;
        }

        s2[j++] = s1[i];
    }
    s2[j] = '\0';
}

// Test from: https://github.com/fool2fish/the-c-programming-language-exercise-answers
int main()
{
    char s1[] = "-a-c, e-c-a, a-a, a-Z, a-9\n-A-C, E-C-a, A-A, A-z, A-9\n-0-2, 4-2-0, 0-0, 0-z, 0-Z\n";
    char s2[1024];
    expand(s1, s2);
    printf("%s", s2);

    return 0;
}