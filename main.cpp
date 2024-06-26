#include <iostream>
#include <fstream>

#include "utils.h"
#include "quick_sort.h"
#include "flash_sort.h"
#include "data_generator.h"

using namespace std;

/**
 * argc: arguments count
 * argv: arguments values 
 */
int main(int argc, char **argv) {
    // Vi du chay utils.h#benchmark
    ofstream out("output.txt");

    int *a = new int[500000];
    GenerateRandomData(a, 100);
    for (int i = 0; i < 30; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";
    flashSort(a, 30);

    for (int i = 0; i < 30; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";
    delete[] a;
    out.close();
    return 0;
}