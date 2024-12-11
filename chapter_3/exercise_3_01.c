#include <bits/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n - 1] */
int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);
void genrandseq(int v[], int n);
void test(char fname[], int (*f)(int x, int v[], int n), int v[], int n);

int main()
{
    const int n = (int)1e4;
    int *v = malloc(sizeof(int) * n);

    test("binsearch", binsearch, v, n);
    test("binsearch2", binsearch2, v, n);

    return 0;
}

int binsearch(int x, int v[], int n)
{
    int mid = 0;
    int low = 0, high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid - 1;
        } else if (x > v[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int binsearch2(int x, int v[], int n)
{
    int mid = 0;
    int low = 0, high = n - 1;
    while (low < high) {
        mid = (low + high) / 2;

        if (x <= v[mid]) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    if (v[low] == x) return low;
    return -1;
}

void genrandseq(int v[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        int base = 0;
        if (i > 0) base = v[i - 1];
        v[i] = base + rand() / (RAND_MAX / 3);
    }
}

void test(char fname[], int (*f)(int x, int v[], int n), int v[], int n)
{
    const int run = (int)1e4;
    struct timespec start, stop;
    int tsum = 0;

    for (int i = 0; i < run; ++i) {
        genrandseq(v, n);
        int target = v[rand() % n];
        clock_gettime(CLOCK_MONOTONIC_RAW, &start);
        f(target, v, n);
        clock_gettime(CLOCK_MONOTONIC_RAW, &stop);
        int elapse = (stop.tv_sec - start.tv_sec) * 1e6 + (stop.tv_nsec - start.tv_nsec) / 1e3;
        tsum += elapse;
    }

    printf("`%s` used %d ms\n", fname, tsum);
}