
#include "PDF.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

PDF::PDF(string n){
	name = n;
}

void PDF::create(){
	cout << "creating pdf of name: " << name << endl;
}

