#include "quick_sort.h"
#include "utils.h"

int partitionComparisons(int a[], int l, int r, long long &comparisions) {
    int pivot = a[(l+r)/2];
    int i = l, j = r;
    while (++comparisions && i < j) {
        while (++comparisions && a[i] < pivot) ++i;
        while (++comparisions && a[j] > pivot) --j;

        if (++comparisions && i < j) {
            swap(a[i], a[j]);
            ++i;
            --j;
        }
    }
    return j;
}

long long quickSortComparisons(int a[], int l, int r) {
    long long comparisions = 0; 
    
    if (++comparisions && l >= r) 
        return comparisions;

    int p = partitionComparisons(a, l, r, comparisions);
    comparisions += quickSortComparisons(a, l, p);
    comparisions += quickSortComparisons(a, p+1, r);
    return comparisions;
}

long long quickSortComparisons(int a[], int n) {
    return quickSortComparisons(a, 0, n - 1);
}

int partition(int a[], int l, int r) {
    int pivot = a[(l+r)/2];
    int i = l, j = r;
    while (i < j) {
        while (a[i] < pivot) ++i;
        while (a[j] > pivot) --j;

        if (i < j) {
            swap(a[i], a[j]);
            ++i;
            --j;
        }
    }
    return j;
}

void quickSort(int a[], int l, int r) { 
    if (l >= r) 
        return;

    int p = partition(a, l, r);
    quickSort(a, l, p);
    quickSort(a, p+1, r);
}

void quickSort(int a[], int n) {
    return quickSort(a, 0, n - 1);
}