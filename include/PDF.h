
#ifndef PDF_H
#define PDF_H

#include "PdfGraphTypes.h"
#include <string>

using namespace std;

class PDF{
	private:
		string name;
	public:
		PDF(string n);
		void create();
};

#endif

