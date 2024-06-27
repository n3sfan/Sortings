#include "files.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void writeOutput(const char *output_file, int *a, int n) {
	ofstream fout(output_file);
    if (!fout.is_open())
    {
        cout << "Can not read this file!";
        return;
    }
    fout << n << "\n";
	for(int i = 0; i < n; i++){
		fout << a[i] << " ";
	}
	fout.close();
}

int *readInput(const char *input_file, int &n) {
    ifstream fin;
    fin.open(input_file);
    if (!fin.is_open())
    {
        cout << "Can not read this file!";
        return NULL;
    }

    fin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        fin >> arr[i];
    }
    fin.close();
    return arr;
}