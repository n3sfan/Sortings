#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void writeOutput(int *a, int n){
	ofstream fout("output.txt");
    if (!fout.is_open())
    {
        cout << "Can not read this file!";
        return;
    }
	for(int i = 0; i < n; i++){
		fout << a[i] << " ";
	}
	fout.close();
}

int *readInput(int &n){
    ifstream fin;
    fin.open("output.txt");
    if (!fin.is_open())
    {
        cout << "Can not read this file!";
        return NULL;
    }

    vector<int> result;
    int value;
    while (fin >> value)
    {
        result.push_back(value);
    }
    fin.close();

    n = result.size();
    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        arr[i] = result[i];
    }

    return arr;
}