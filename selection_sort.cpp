#include "selection_sort.h"
#include "utils.h"

void selectionSort(int a[], int n)
{
    int min_idx;
    for (int i = 0; i < n - 1; i++) {
        min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            swap(a[min_idx], a[i]);
    }
}

int selectionSortComparisions(int a[], int n)
{
    int comparision = 0;
    int min_idx;
    for (int i = 0; ++comparision && i < n - 1; i++) {
        min_idx = i;
        for (int j = i + 1; ++comparision && j < n; j++) {
            if (++comparision && a[j] < a[min_idx])
                min_idx = j;
        }
        if (++comparision && min_idx != i)
            swap(a[min_idx], a[i]);
    }
    return comparision;
}