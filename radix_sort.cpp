#include "radix_sort.h"
#include "utils.h"

int getMax(int a[], int n)
{
    int mx = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > mx)
            mx = a[i];
    return mx;
}

void countSort(int a[], int n, int exp)
{
    int* output = new int[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = output[i];

    delete [] output;
}

void radixSort(int a[], int n)
{
    int m = getMax(a, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(a, n, exp);
}


int getMaxComparision(int a[], int n, int &comparision)
{
    int mx = a[0];
    for (int i = 1; ++comparision && i < n; i++){
        if (++comparision && a[i] > mx)
            mx = a[i];
    }  
    return mx;
}

void countSortComparision(int a[], int n, int exp, int &comparision)
{
    int* output = new int[n];
    int count[10] = {0};

    for (int i = 0; ++comparision && i < n; i++){
        count[(a[i] / exp) % 10]++;
    }

    for (int i = 1; ++comparision && i < 10; i++){
        count[i] += count[i - 1];
    }

    for (int i = n - 1; ++comparision && i >= 0; i--) {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    for (int i = 0; ++comparision && i < n; i++){
        a[i] = output[i];
    }

    delete [] output;
}

long long radixSortComparisions(int a[], int n)
{
    int comparision = 0;
    int m = getMaxComparision(a, n, comparision);
    for (int exp = 1; ++comparision && m / exp > 0; exp *= 10){
        countSortComparision(a, n, exp, comparision);
    }
    return comparision;
}