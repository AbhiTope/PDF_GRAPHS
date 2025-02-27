
#ifndef PDFGRAPHTYPES_H
#define PDFGRAPHTYPES_H

#include <string>
#include <vector>

using namespace std;

struct csvContent{
	string name;
	vector<string> headers;
	vector<string> labels;
	vector<vector<double>> data;
};

#endif
