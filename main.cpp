#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

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
    if (strcmp(argv[0], "-a") == 0) {
        char *algo = argv[1];

        if ('0' <= argv[2][0] && argv[2][0] <= '9') { // input size
            int size = stoi(string(argv[2]));
        } else { // input file
            char *inputFile = argv[3];
        }
    } else {

    }

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