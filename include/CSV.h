
#ifndef CSV_H
#define CSV_H

#include "PdfGraphTypes.h"
#include <string>
#include <vector>

using namespace std;

class CSV{
	private:
		string name;
		vector<string> headers;
		vector<string> labels;
		vector<vector<double>> data;
	public:
		CSV(string n);
		csvContent get();
};

#endif

