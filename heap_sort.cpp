#include "heap_sort.h"
#include "utils.h"

void heapify(int a[], int i, int size)
{
    int la = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && a[la] < a[l]){
        la = l;
    }
    if (r < size && a[r] > a[la]){
        la = r;
    }
    if (la != i){
        swap(a[la], a[i]);
        heapify(a, la, size);
    }
}

void heapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, i, n);
    for (int size = n - 1; size > 0; size--){
        swap(a[size], a[0]);
        heapify(a, 0, size);
    }
}

void heapifyComparisions(int a[], int i, int size, int &comparisions)
{
    int la = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (++comparisions && l < size && a[la] < a[l]){
        la = l;
    }
    if (++comparisions && r < size && a[r] > a[la]){
        la = r;
    }
    if (++comparisions && la != i){
        swap(a[la], a[i]);
        heapifyComparisions(a, la, size, comparisions);
    }
}

int heapSortComparisions(int a[], int n)
{
    int comparisions = 0;
    for (int i = n / 2 - 1; ++comparisions && i >= 0; i--){
        heapifyComparisions(a, i, n, comparisions);
    }
    for (int size = n - 1; ++comparisions && size > 0; size--){
        swap(a[size], a[0]);
        heapifyComparisions(a, 0, size, comparisions);
    }
    return comparisions;
}
