#include "shaker_sort.h"
#include "utils.h"

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void shakerSort(int a[], int n)
{
    bool swapped = true;
    int start = 0;
    int end = n - 1;
 
    while (swapped) {
        swapped = false;
        for (int i = start; i < end; ++i) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
        swapped = false;
        --end;
        for (int i = end - 1; i >= start; --i) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
}

int shakerSortComparisions(int a[], int n)
{
    int comparisions = 0;

    bool swapped = true;
    int start = 0;
    int end = n - 1;
 
    while (++comparisions && swapped) {
        swapped = false;
        for (int i = start; ++comparisions && i < end; ++i) {
            if (++comparisions && a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        if (++comparisions && !swapped)
            break;
        swapped = false;
        --end;
        for (int i = end - 1; ++comparisions && i >= start; --i) {
            if (++comparisions && a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
    return comparisions;
}
