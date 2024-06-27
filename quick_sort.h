#ifndef QUICK_SORT_H_
#define QUICK_SORT_H_

int partitionComparisons(int a[], int l, int r, int &comparisions);
long long quickSortComparisons(int a[], int l, int r);
long long quickSortComparisons(int a[], int n);
int partition(int a[], int l, int r);
void quickSort(int a[], int l, int r);
void quickSort(int a[], int n);

#endif
