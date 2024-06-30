#include "flash_sort.h"
#include "utils.h"

double kR = 0.1;

void flashSort(int a[], int n) {
    if (n == 0)
        return;

    int m = n * kR;
    int anmin = a[0];
    int anmax = a[0];
    int nmax = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < anmin) {
            anmin = a[i];
        }
        if (a[i] > anmax) {
            anmax = a[i];
            nmax = i;
        }
    }
    
    if (anmin == anmax) 
        return;

    double c1 = 1.0*(m-1)/(anmax - anmin);
    int *l = new int[m]{};
    for (int i = 0; i < n; ++i) {
        int k = (int)(c1 * (a[i] - anmin));
        l[k]++;
    }
    for (int k = 1; k < m; ++k) {
        l[k] += l[k-1];
    }

    // Permutation
    int j = 0;
    int k = m-1;
    int nmove = 0;

    while (nmove < n-1) {
        // std::cout << j << " " << l[k] << "\n";
        while (j >= l[k]) {
            // std::cout << j << " "  << k << " " << nmove << "\n";
            ++j;
            k = (int)(c1 * (a[j] - anmin));   
        }

        int z = a[j];
        while (j != l[k]) {
            // std::cout << j << " " << k << " " << nmove << "\n";
            k = (int)(c1 * (z - anmin));
            int y = a[l[k] - 1];
            a[l[k] - 1] = z;
            z = y;

            l[k]--;
            nmove++;
        }
    }

    // Insertion sort
    for (int i = 1; i < n; ++i) {
        int v = a[i];
        int j = i-1;

        while (j >= 0 && a[j] > v) {
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = v;
    }

    delete[] l;
}

long long flashSortComparisions(int a[], int n) {
    int comparisons = 0;

    if (++comparisons && n == 0)
        return comparisons;

    int m = n * kR;
    int anmin = a[0];
    int anmax = a[0];
    int nmax = 0;
    for (int i = 0; ++comparisons && i < n; ++i) {
        if (++comparisons && a[i] < anmin) {
            anmin = a[i];
        }
        if (++comparisons && a[i] > anmax) {
            anmax = a[i];
            nmax = i;
        }
    }
    
    if (++comparisons && anmin == anmax) 
        return comparisons;

    double c1 = 1.0*(m-1)/(anmax - anmin);
    int *l = new int[m]{};
    for (int i = 0; ++comparisons && i < n; ++i) {
        int k = (int)(c1 * (a[i] - anmin));
        l[k]++;
    }
    for (int k = 1; ++comparisons && k < m; ++k) {
        l[k] += l[k-1];
    }

    // Permutation
    int j = 0;
    int k = m-1;
    int nmove = 0;

    while (++comparisons && nmove < n-1) {
        // std::cout << j << " " << l[k] << "\n";
        while (++comparisons && j >= l[k]) {
            // std::cout << j << " "  << k << " " << nmove << "\n";
            ++j;
            k = (int)(c1 * (a[j] - anmin));   
        }

        int z = a[j];
        while (++comparisons && j != l[k]) {
            // std::cout << j << " " << k << " " << nmove << "\n";
            k = (int)(c1 * (z - anmin));
            int y = a[l[k] - 1];
            a[l[k] - 1] = z;
            z = y;

            l[k]--;
            nmove++;
        }
    }

    // Insertion sort
    for (int i = 1; ++comparisons && i < n; ++i) {
        int v = a[i];
        int j = i-1;

        while (++comparisons && j >= 0 && a[j] > v) {
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = v;
    }

    delete[] l;
    return comparisons;
}