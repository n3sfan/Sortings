#ifndef UTILS_H_
#define UTILS_H_

struct RunInfo {
    long long elapsed_time = 0; // milliseconds. 1s = 1000 ms
    int comparisons = 0;
};

void swap(int &x, int &y);

RunInfo benchmark(int a[], int n, int (*sort)(int a[], int n));

#endif