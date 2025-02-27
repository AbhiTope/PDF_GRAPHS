
#include "CSV.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

CSV::CSV(string n){
	name = n;
	fstream fin;
	fin.open(name, ios::in);
	if(!fin.is_open()){
		cerr << "Error opening file!" << endl;
		return;
	}

	string line;
	int i = 0;
	while(getline(fin, line)){
		stringstream ss(line);
		string cell;
		int j = 0;
		vector<double> d;
		while(getline(ss, cell, ',')){
			if(i == 0){
				headers.push_back(cell);
			}
			else if(j == 0){
				labels.push_back(cell);
			}
			else{
				d.push_back(stod(cell));
			}
			j++;
		}
		if(i != 0)
			data.push_back(d);
		i++;
	}

}

csvContent CSV::get(){
	csvContent result;
	result.name = name;
	result.headers = headers;
	result.labels = labels;
	result.data = data;
	return result;
}

