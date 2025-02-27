
#include "Wrapper.h"
#include "CSV.h"
#include <iostream>
#include <vector>

using namespace std;

void process_csv(const char* filename){
	cout << "Reading CSV file : " << filename << endl;
	CSV file(filename);
	
	csvContent fc = file.get();

	cout << endl;
	for(string h : fc.headers)
		cout << h << "..";

	cout << endl;
	for(string l : fc.labels)
		cout << l << "..";
	
	cout << endl;
	for(vector<double> dd : fc.data){
		for(double d : dd)
			cout << d << "||";
		cout << endl;
	}

	cout << endl;

}
