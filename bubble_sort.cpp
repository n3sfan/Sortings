#include "bubble_sort.h"
#include "utils.h"

void bubbleSort(int a[], int n)
{
    bool swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

int bubbleSortComparisions(int a[], int n)
{
    int comparisions = 0; 

    for (int i = 0; ++comparisions && i < n - 1; i++)
        for (int j = 0; ++comparisions && j < n - i - 1; j++)
            if (++comparisions && a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
    return comparisions;
}
