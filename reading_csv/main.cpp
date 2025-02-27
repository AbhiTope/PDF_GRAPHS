#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

struct csvContent{
	string name;
	vector<string> headers;
	vector<string> labels;
	vector<vector<double>> data;
};

class inputFile{
	private:
		string name;
		vector<string> headers;
		vector<string> labels;
		vector<vector<double>> data;
	public:
		inputFile(string n){
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
		csvContent get(){
			csvContent result;
			result.name = name;
			result.headers = headers;
			result.labels = labels;
			result.data = data;
			return result;
		}
};

int main(){
	cout << "reading csv file" << endl;
	string filename = "test.csv";
	cout << "Enter File Name : ";
	cin >> filename;
	inputFile file(filename);
	
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
