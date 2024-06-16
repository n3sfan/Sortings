#include "counting_sort.h"
#include "utils.h"

void countingSort(int a[], int n){
    int output[10];
    int count[10];
    int max = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] > max)
        max = a[i];
    }

    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

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
}

int countingSortComparisions(int a[], int size) {
    int output[10];
    int count[10];
    int max = a[0];
    int comparision = 0;

    for (int i = 1; ++comparision && i < size; i++) {
        if (++comparision && a[i] > max)
        max = a[i];
    }

    for (int i = 0; ++comparision && i <= max; ++i) {
        count[i] = 0;
    }

    for (int i = 0; ++comparision && i < size; i++) {
        count[a[i]]++;
    }

    for (int i = 1; ++comparision && i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; ++comparision && i >= 0; i--) {
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }

    for (int i = 0; ++comparision && i < size; i++) {
        a[i] = output[i];
    }
    return comparision;
}