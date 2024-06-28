#include "shell_sort.h"
#include "utils.h"

void shellSort(int a[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int key = a[i], j = i - gap;
            while (j >= 0 && a[j] > key) {
                a[j+gap] = a[j];
                j -= gap;
            }
            a[j+gap] = key;
        }
    }
}

long long shellSortComparisons(int a[], int n) {
    long long comparisons = 0;
    for (int gap = n/2; ++comparisons && gap > 0; gap /= 2) {
        for (int i = gap; ++comparisons && i < n; ++i) {
            int key = a[i], j = i - gap;
            while (++comparisons && j >= 0 && ++comparisons && a[j] > key) {
                a[j+gap] = a[j];
                j -= gap;
            }
            a[j+gap] = key;
        }
    }
    return comparisons;
}