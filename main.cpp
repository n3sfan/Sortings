#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <chrono>

#include "utils.h"
#include "files.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "bubble_sort.h"
#include "shaker_sort.h"
#include "shell_sort.h"
#include "heap_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "counting_sort.h"
#include "radix_sort.h"
#include "flash_sort.h"
#include "data_generator.h"

using namespace std;

void printSeparator() {
    for (int i = 0; i < 20; ++i) {
        cout << '-';
    }
    cout << '\n';
}

long long benchmarkSortTime(const char *algo, int *b, int n, bool printOutput) {
    int *a = new int[n];
    memcpy(a, b, n*sizeof(int));

    long long ans = -1;
    if (strcmp(algo, "selection-sort") == 0) {
        ans = benchmark(a, n, selectionSort);
    } else if (strcmp(algo, "insertion-sort") == 0) {
        ans = benchmark(a, n, insertionSort);
    } else if (strcmp(algo, "bubble-sort") == 0) {
        ans = benchmark(a, n, bubbleSort);
    } else if (strcmp(algo, "shaker-sort") == 0) {
        ans = benchmark(a, n, shakerSort);
    } else if (strcmp(algo, "shell-sort") == 0) {
        ans = benchmark(a, n, shellSort);
    } else if (strcmp(algo, "heap-sort") == 0) {
        ans = benchmark(a, n, heapSort);
    } else if (strcmp(algo, "merge-sort") == 0) {
        ans = benchmark(a, n, mergeSort);
    } else if (strcmp(algo, "quick-sort") == 0) {
        ans = benchmark(a, n, quickSort);
    } else if (strcmp(algo, "counting-sort") == 0) {
        ans = benchmark(a, n, countingSort);
    } else if (strcmp(algo, "radix-sort") == 0) {
        ans = benchmark(a, n, radixSort);
    } else if (strcmp(algo, "flash-sort") == 0) {
        ans = benchmark(a, n, flashSort);
    }

    if (printOutput) {
        string output_file = "output.txt";
        writeOutput(output_file.c_str(), a, n);
    }

    delete[] a;
    return ans;
}

long long benchmarkSortComparisons(char *algo, int *b, int n, bool printOutput) {
    int *a = new int[n];
    memcpy(a, b, n*sizeof(int));

    long long ans = -1;
    if (strcmp(algo, "selection-sort") == 0) {
        ans = selectionSortComparisons(a, n);
    } else if (strcmp(algo, "insertion-sort") == 0) {
        ans = insertionSortComparisons(a, n);
    } else if (strcmp(algo, "bubble-sort") == 0) {
        ans = bubbleSortComparisons(a, n);
    } else if (strcmp(algo, "shaker-sort") == 0) {
        ans = shakerSortComparisions(a, n);
    } else if (strcmp(algo, "shell-sort") == 0) {
        ans = shellSortComparisons(a, n);
    } else if (strcmp(algo, "heap-sort") == 0) {
        ans = heapSortComparisons(a, n);
    } else if (strcmp(algo, "merge-sort") == 0) {
        ans = mergeSortComparisons(a, n);
    } else if (strcmp(algo, "quick-sort") == 0) {
        ans = quickSortComparisons(a, n);
    } else if (strcmp(algo, "counting-sort") == 0) {
        ans = countingSortComparisons(a, n);
    } else if (strcmp(algo, "radix-sort") == 0) {
        ans = radixSortComparisions(a, n);
    } else if (strcmp(algo, "flash-sort") == 0) {
        ans = flashSortComparisions(a, n);
    }

    if (printOutput) {
        string output_file = "output.txt";
        writeOutput(output_file.c_str(), a, n);
    }

    delete[] a;
    return ans;
}

void algorithmModeOrder(char *algo, int n, int order, bool output_time, bool output_comp, int command) {
    cout << "Input order: " << getDataOrderDisplay((DataOrder) order) << "\n";
    printSeparator();
    int *a;
    GenerateData(a, n, order);

    bool printOutput = false;
    if (command == 2) {
        string input_file = "input.txt";
        writeOutput(input_file.c_str(), a, n);
        printOutput = true;
    } else if (command == 3) {
        string input_file;
        if (order == 0) input_file = "input_1.txt"; // random
        else if (order == 3) input_file = "input_2.txt"; //nearly sorted
        else if (order == 1) input_file = "input_3.txt"; //sort
        else input_file = "input_4.txt"; // reverse
        writeOutput(input_file.c_str(), a, n);
    }

    if (output_time) {
        cout << "Running time (nanosec): " << benchmarkSortTime(algo, a, n, printOutput) << "\n";
    }
    if (output_comp) {
        cout << "Comparisons: " << benchmarkSortComparisons(algo, a, n, printOutput) << "\n";
    }
    cout << "\n";

    delete[] a;
}

void algorithmMode(int argc, char **argv) {
    char *algo = argv[2];
    // for (int i = 0; i < argc; ++i) {
    //     cout << argv[i] << "\n";
    // }

    if ('1' <= argv[3][0] && argv[3][0] <= '9') { // input size
        int input_size = stoi(string(argv[3]));
        cout << "ALGORITHM MODE\n";
        cout << "Algorithm: " << convertToReadable(algo) << "\n";
       
        if (argc == 5) {
            cout << "Input size: " << input_size << "\n"; 
            char *output_param = argv[4]; 
            OutputParam param = parseParam(output_param); 
            cout << "\n";

            bool output_time = false, output_comp = false;
            if (param == TIME) {
                output_time = true; 
            } else if (param == COMP) {
                output_comp = true;
            } else if (param == BOTH) {
                output_time = output_comp = true;
            }

            for (int order = RANDOM; ; ++order) { 
                algorithmModeOrder(algo, input_size, order, output_time, output_comp, 3);

                if (order == NEARLY_SORTED) {
                    break;
                }   
            }          
        } else {
            char *input_order = argv[4];
            DataOrder order = parseOrder(input_order);
            char *output_param = argv[5];
            OutputParam param = parseParam(output_param);
            bool output_time = false, output_comp = false;
            if (param == TIME) {
                output_time = true; 
            } else if (param == COMP) {
                output_comp = true;
            } else if (param == BOTH) {
                output_time = output_comp = true;
            }

            cout << "Input size: " << input_size << "\n"; 
            algorithmModeOrder(algo, input_size, order, output_time, output_comp, 2);
        }
    } else { // input file
        char *input_file = argv[3];
        char *output_param = argv[4];
        OutputParam param = parseParam(output_param); 
        int *a, n;
        a = readInput(input_file, n);

        cout << "Input file: " << input_file << "\n";
        cout << "Input size: " << n << "\n"; 
        printSeparator(); 
        bool printOutput = true;
        if (param == TIME || param == BOTH) {  
            cout << "Running time (nanosec): " << benchmarkSortTime(algo, a, n, printOutput) << "\n";
            printOutput = false;
        }
        if (param == COMP || param == BOTH) {
            cout << "Comparisons: " << benchmarkSortComparisons(algo, a, n, printOutput) << "\n";
        }
        cout << "\n";

        delete[] a;
    }
}

void comparisonMode(int argc, char **argv) {
    char *algo1 = argv[2], *algo2 = argv[3];
    cout << "COMPARE MODE\n";
    cout << "Algorithm: " << convertToReadable(algo1) << " | " << convertToReadable(algo2) << "\n";
        
    if ('0' <= argv[4][0] && argv[4][0] <= '9') { // input size
        int input_size = stoi(string(argv[4]));
        char *input_order = argv[5];

        DataOrder order = parseOrder(input_order);
        cout << "Input size: " << input_size << "\n";
        cout << "Input order: " << getDataOrderDisplay(order) << "\n";
        printSeparator();

        int n = input_size;
        int *a;
        GenerateData(a, n, order);

        string input_file = "input.txt";
        writeOutput(input_file.c_str(), a, n);

        cout << "Running time (nanosec): " << benchmarkSortTime(algo1, a, n, false) << " | " << benchmarkSortTime(algo2, a, n, false) << "\n";
        cout << "Comparisons: " << benchmarkSortComparisons(algo1, a, n, false) << " | " << benchmarkSortComparisons(algo2, a, n, false) << "\n";
        cout << "\n";

        delete[] a;
    } else { // input file
        char *input_file = argv[4];
        int *a, n;
        a = readInput(input_file, n);

        cout << "Input file: " << input_file << "\n";
        cout << "Input size: " << n << "\n";
        printSeparator();
        cout << "Running time (nanosec): " << benchmarkSortTime(algo1, a, n, false) << " | " << benchmarkSortTime(algo2, a, n, false) << "\n";
        cout << "Comparisons: " << benchmarkSortComparisons(algo1, a, n, false) << " | " << benchmarkSortComparisons(algo2, a, n, false) << "\n";
        cout << "\n";
   
        delete[] a;
   }
}

/**
 * argc: arguments count
 * argv: arguments values 
 */
int main(int argc, char **argv) {
    if (strcmp(argv[1], "-a") == 0) {
        algorithmMode(argc, argv);
    } else {
        comparisonMode(argc, argv);
    }

    return 0;
}