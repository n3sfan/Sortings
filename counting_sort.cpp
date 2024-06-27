#include "counting_sort.h"
#include "utils.h"

void countingSort(int a[], int n){
    int* output = new int[n]; 
    int max = a[0];

    for (int i = 1; i < n; i++) {
      if (a[i] > max)
        max = a[i];
    }
    int *count = new int[max + 1]{0};
    for (int i = 0; i < n; i++) {
        count[a[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }

    for (int i = 0; i < n; i++) {
        a[i] = output[i];
    }

    delete [] count;
    delete [] output;
}

long long countingSortComparisons(int a[], int n) {
    int comparision = 0;
    int* output = new int[n]; 
    int max = a[0];

    for (int i = 1; ++comparision && i < n; i++) {
        if (++comparision && a[i] > max)
        max = a[i];
    }
    int *count = new int[max + 1]{0};

    for (int i = 0; ++comparision && i < n; i++) {
        count[a[i]]++;
    }

    for (int i = 1; ++comparision && i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; ++comparision && i >= 0; i--) {
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }

    for (int i = 0; ++comparision && i < n; i++) {
        a[i] = output[i];
    }

    delete [] count;
    delete [] output;

    return comparision;
}