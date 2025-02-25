#include<iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct cordinate{
	int x;
	int y;
};

struct color{
	float r;
	float g;
	float b;
};

class textBox{
	private:
		string content;
		string label;
		int fontSize;
		cordinate location;
		color txtColor;
		double theta;
	public:
		textBox(string lbl){
			label = lbl;
			fontSize = 10;
			location.x = 20;
			location.y = 20;
			txtColor.r = 0;
			txtColor.g = 0;
			txtColor.b = 1;
			theta = 0;
		}
		void setLocation(int x, int y){
			location.x = x;
			location.y = y;
		}
		void setFontSize(int fs){
			fontSize = fs;
		}
		void setColor(float r, float g, float b){
			txtColor.r = r;
			txtColor.g = g;
			txtColor.b = b;
		}

		void rotate(double a){
			const double pi = acos(-1);
			theta = (pi * a) / 180;
			//[ cos(θ) sin(θ) -sin(θ) cos(θ) X Y ] Tm
		}
		string get(){
			string content = 
				"BT\n"
				"/F1 " + to_string(fontSize) + " Tf\n"       // First Line: Font = Helvetica, Size = 24
				"" + to_string(txtColor.r) +" " + to_string(txtColor.g) + " " + to_string(txtColor.b) + " rg\n"//% First Line: Blue Color
				"" + to_string((int)cos(theta)) + " " + to_string((int)sin(theta)) + " " + to_string(-(int)sin(theta)) + " " + to_string((int)cos(theta)) + " " + to_string(location.x) + " " + to_string(location.y) + " Tm\n"
				"(" + label + ") Tj\n"
				"ET\n";
			return content;
				//"" + to_string(location.x) + " "  + to_string(location.y) + " Td\n"       //% Move to (200,700)
		}

};


class line{
	private:
		int width;
		cordinate from;
		cordinate to;
		color lineColor;
	public:
		line(){
			width = 1;
			from.x = 50;
			from.y = 50;
			to.x = 30;
			to.y = 30;
			lineColor.r = 1;
			lineColor.g = 1;
			lineColor.b = 1;
		}
		void start(int x, int y){
			from.x = x;
			from.y = y;
		}
		void end(int x, int y){
			to.x = x;
			to.y = y;
		}
		void setWidth(int w){
			width = w;
		}
		void setColor(float r, float g, float b){
			lineColor.r = r;
			lineColor.g = g;
			lineColor.b = b;
		}
		string get(){

			string content = 
				"q\n"
				"" + to_string(lineColor.r) +" " + to_string(lineColor.g) + " " + to_string(lineColor.b) + " RG\n"//set fill color
			   	"" + to_string(width) + " w\n"	// Set line thickness
				"" + to_string(from.x) + " " + to_string(from.y) + " m\n"	//Move to start position (from.x,from.y)
				"" + to_string(to.x) + " " + to_string(to.y) + " l\n"	//Draw line to (to.x,to.y)
			   	"S\n"	//Fill and stroke
			   	"Q\n"; 

			return content;
		}

};




class axis{
	private:
		string content;
		string label;
		int fontSize;
		cordinate location;
		color txtColor;
	public:
		axis(string lbl){
			label = lbl;
			fontSize = 10;
			location.x = 20;
			location.y = 20;
			txtColor.r = 0;
			txtColor.g = 0;
			txtColor.b = 1;
		}
		void setLocation(int x, int y){
			location.x = x;
			location.y = y;
		}
		void setFontSize(int fs){
			fontSize = fs;
		}
		void setColor(float r, float g, float b){
			txtColor.r = r;
			txtColor.g = g;
			txtColor.b = b;
		}
		string get(){
			/*
			   % y-axis
			   q                   % Save state
			   0.28 0.55 0.47 RG            % Set fill color to GREEN
			   1 w                 % Set line thickness
			   50 50 m           % Move to start position (100,100)
			   50 550 l           % Draw line to (200,300)
			   S                   % Fill and stroke
			   Q                   % Restore state

			   % y-axis Label
			   BT
			   /F1 15 Tf        % First Line: Font = Helvetica, Size = 24
			   0 0 1 rg         % First Line: Blue Color
			   %100 550Td       % Move to (200,700)
			   0 1 -1 0 15 300Tm
			   (y-axis label) Tj
			   ET
			 */
			line l;
			l.start(50, 50);
			l.end(50, 550);
			l.setWidth(1);
			l.setColor(0, 0, 0);

			textBox title(label);
			title.setFontSize(15);
			title.setLocation(15,300);
			title.setColor(1, 0, 0);
			title.rotate(90);

			string content = 
				l.get() + title.get();

			return content;
		}


};

class PDF{
	private:
		string name = "";
	public:
		void create(){
			std::ofstream pdfFile("test.pdf", std::ios::binary);

			if (!pdfFile) {
				std::cerr << "Error: Unable to create PDF file!" << std::endl;
				return;
			}

			// PDF Header
			pdfFile << "%PDF-1.4\n";

			// Object 1: Catalog
			pdfFile << "1 0 obj\n"
				"<< /Type /Catalog /Pages 2 0 R >>\n"
				"endobj\n";

			// Object 2: Pages
			pdfFile << "2 0 obj\n"
				"<< /Type /Pages /Kids [3 0 R] /Count 1 >>\n"
				"endobj\n";

			// Object 3: Page
			pdfFile << "3 0 obj\n"
				"<< /Type /Page /Parent 2 0 R /MediaBox [0 0 792 612] /Contents 4 0 R\n" //we can set page size here
				"/Resources << /Font << /F1 5 0 R /XObject << /Im1 6 0 R >> >> >>\n"
				"endobj\n";

			// Object 4: Page Contents (Text and Image Placement)
			// Graph Title

			textBox title("Graph Title");
			title.setFontSize(15);
			title.setLocation(350,580);
			title.setColor(0, 0, 1);
			
			textBox subTitle("Graph sub Title");
			subTitle.setFontSize(12);
			subTitle.setLocation(350,565);
			subTitle.setColor(0, 0, 1);

			axis y_axis("temp");
		
			std::string pageContent = 
				title.get() + "\n" +
				subTitle.get() + "\n" +
				y_axis.get();

			pdfFile << "4 0 obj\n"
				"<< /Length " << pageContent.length() << " >>\n"
				"stream\n"
				<< pageContent << "\n"
				"endstream\n"
				"endobj\n";

				/*
% Object 4: Page Content

% y-axis
q                   % Save state
0.28 0.55 0.47 RG            % Set fill color to GREEN
1 w                 % Set line thickness
50 50 m           % Move to start position (100,100)
50 550 l           % Draw line to (200,300)
S                   % Fill and stroke
Q                   % Restore state

% y-axis Label
BT
/F1 15 Tf        % First Line: Font = Helvetica, Size = 24
0 0 1 rg         % First Line: Blue Color
%100 550Td       % Move to (200,700)
0 1 -1 0 15 300Tm
(y-axis label) Tj
ET

% x-axis
q                   % Save state
%0 1 0 RG            % Set fill color to GREEN
0.28 0.55 0.47 RG            % Set fill color to GREEN
1 w                 % Set line thickness
50 50 m           % Move to start position (100,100)
750 50 l           % Draw line to (200,300)
S                   % Fill and stroke
Q                   % Restore state

% x-axis Label
BT
/F1 15 Tf        % First Line: Font = Helvetica, Size = 24
0 0 1 rg         % First Line: Blue Color
300 10Td       % Move to (200,700)
(x-axis label) Tj
ET


endstream
endobj

		*/

			// Object 5: Font (Helvetica)
			pdfFile << "5 0 obj\n"
				"<< /Type /Font /Subtype /Type1 /BaseFont /Helvetica >>\n"
				"endobj\n";

			// Cross-reference table
			pdfFile << "xref\n"
				"0 7\n"
				"0000000000 65535 f \n"
				"0000000010 00000 n \n"
				"0000000065 00000 n \n"
				"0000000120 00000 n \n"
				"0000000260 00000 n \n"
				"0000000355 00000 n \n"
				"0000000500 00000 n \n";

			// Trailer
			pdfFile << "trailer\n"
				"<< /Size 7 /Root 1 0 R >>\n"
				"startxref\n"
				"600\n"
				"%%EOF\n";

			pdfFile.close();
			std::cout << "PDF file 'test.pdf' created successfully!" << std::endl;

		}

};

int main(){
	PDF pdf;
	pdf.create();
	return 0;
}
