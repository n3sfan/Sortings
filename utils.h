#ifndef UTILS_H_
#define UTILS_H_

#include <string>

using namespace std;

enum DataOrder {
    RANDOM,
    SORTED,
    REVERSE,
    NEARLY_SORTED
};

enum OutputParam {
    TIME,
    COMP,
    BOTH
};

DataOrder parseOrder(char *input_order);

OutputParam parseParam(char *output_param);

/**
 * e.g. selection-sort replaced with Selection Sort.
 * - replaced with space
 */
string convertToReadable(char *algo);

string getDataOrderDisplay(DataOrder dataOrder);

struct RunInfo {
    long long elapsed_time = 0; // milliseconds. 1s = 1000 ms
    int comparisons = 0;
};

void swap(int &x, int &y);

long long benchmark(int *a, int n, void (*sort)(int *a, int n));

#endif