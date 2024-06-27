#include "insertion_sort.h"
#include "utils.h"

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = a[i], j = i-1;
        while (j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = key;
    }
}

long long insertionSortComparisons(int a[], int n) {
    int comparisons = 0;
    for (int i = 1; ++comparisons && i < n; ++i) {
        int key = a[i], j = i-1;
        while (++comparisons && j >= 0 && ++comparisons && a[j] > key) {
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = key;
    }
    return comparisons;
}