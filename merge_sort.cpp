#include "merge_sort.h"
#include "utils.h"

void mergeSort(int a[], int n) {
    if (n <= 1) return;

    int m = n >> 1;

    int* b = new int[m];
    for (int i = 0; i < m; ++i) b[i] = a[i];
    int* c = new int[n-m];
    for (int i = m; i < n; ++i) c[i-m] = a[i];

    mergeSort(b, m); mergeSort(c, n-m);

    int i = 0, j = 0;
    while (i < m && j < n-m) {
        if (b[i] <= c[j]) {
            a[i+j] = b[i];
            ++i;
        }
        else {
            a[i+j] = c[j];
            ++j;
        }
    }
    while (i < m) {
        a[i+j] = b[i];
        ++i; 
    }
    while (j < n-m) {
        a[i+j] = c[j];
        ++j; 
    }

    delete [] b;
    delete [] c;
}

int mergeSortComparisons(int a[], int n) {
    int comparisons = 0;

    if (++comparisons && n <= 1) return comparisons;

    int m = n >> 1;

    int* b = new int[m];
    for (int i = 0; ++comparisons && i < m; ++i) b[i] = a[i];
    int* c = new int[n-m];
    for (int i = m; ++comparisons && i < n; ++i) c[i-m] = a[i];

    comparisons += mergeSortComparisons(b, m); 
    comparisons += mergeSortComparisons(c, n-m);

    int i = 0, j = 0;
    while (++comparisons && i < m && ++comparisons && j < n-m) {
        if (++comparisons && b[i] <= c[j]) {
            a[i+j] = b[i];
            ++i;
        }
        else {
            a[i+j] = c[j];
            ++j;
        }
    }
    while (++comparisons && i < m) {
        a[i+j] = b[i];
        ++i; 
    }
    while (++comparisons && j < n-m) {
        a[i+j] = c[j];
        ++j; 
    }

    delete [] b;
    delete [] c;

    return comparisons;
}