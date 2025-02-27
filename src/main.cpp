
#include "CSV.h"
#include<iostream>
#include<vector>

using namespace std;

int main(){
	cout << "reading csv file" << endl;
	string filename = "test.csv";
	cout << "Enter File Name : ";
	cin >> filename;
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
	return 0;
}
