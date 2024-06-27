#include <chrono>
#include <iostream>
#include <cstring>

#include "utils.h"

using namespace std;

DataOrder parseOrder(char *input_order) {
    DataOrder order;
    if (strcmp(input_order, "-rand") == 0) {
        order = RANDOM;
    } else if (strcmp(input_order, "-nsorted") == 0) {
        order = NEARLY_SORTED;
    } else if (strcmp(input_order, "-sorted") == 0) {
        order = SORTED;
    } else if (strcmp(input_order, "-rev") == 0) {
        order = REVERSE;
    }   
    return order;
}

OutputParam parseParam(char *output_param) {
    OutputParam param = TIME; 
    if (strcmp(output_param, "-time") == 0) {
        param = TIME;
    } else if (strcmp(output_param, "-comp") == 0) {
        param = COMP;
    } else if (strcmp(output_param, "-both") == 0) {
        param = BOTH;
    }
    return param;
}

string convertToReadable(char *algo) {
    string res = "";
    string tmp(algo);

    int i = tmp.find('-');
    string s = tmp.substr(0, i);
    s[0] += 'A'-'a';
    res += s;
    s = tmp.substr(i+1, string::npos);
    s[0] += 'A'-'a';
    res += " " + s;
    return res;
}

string getDataOrderDisplay(DataOrder dataOrder) {
    switch (dataOrder) {
	case RANDOM:	// ngẫu nhiên
        return "Random";
    case SORTED:	// có thứ tự
        return "Sorted";
    case REVERSE:	// có thứ tự ngược
		return "Reverse";
	case NEARLY_SORTED:	// gần như có thứ tự
        return "Nearly sorted";
    default:
        return "";
    }
}

void swap(int &x, int &y) {
    int t = x;
    x = y;
    y = t;
}

long long benchmark(int *a, int n, void (*sort)(int *a, int n)) {
    auto start = chrono::steady_clock::now();
    sort(a, n);
    auto end = chrono::steady_clock::now();
    long long elapsed_time = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    return elapsed_time;
}