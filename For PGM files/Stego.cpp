#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define runtime printf("%.2f\n",(double)clock()/CLOCKS_PER_SEC);

#define debug(args...) {dbg,args; cerr<<endl;}
struct debugger{
    template<typename T>debugger& operator ,(const T& v) { cerr<<v<<" ";return *this; }
}dbg;

#include "CONVERTER.hpp"

ifstream inp;
ofstream out;

vector< vector<int> > pixels;
vector<string> pgmInfo;
string msg;
vector<int> binaryMsg;

void Input() {

	string inp_file;

	cout << "Enter the name of the PGM file: ";
	cin >> inp_file;
	inp_file += ".pgm";
	inp.open(inp_file);

	int i = 0;
	string s;
	while(i < 4) { getline(inp, s); pgmInfo.push_back(s); ++i; }

	while(getline(inp, s)) {
		stringstream ss(s);
		vector<int> p;
		while(ss) {
			int x;
			ss >> x;
			p.push_back(x);
		}

		p.pop_back();
	
		pixels.push_back(p);
	}

}


void Encrypt() {

	Input();
	
	string out_file;
	cout << "Enter the name of the output file: ";
	cin >> out_file;
	out_file += ".pgm";
	out.open(out_file);

	Converter Convert;

	rep(i,0,pgmInfo.size()) out << pgmInfo[i] << endl;

	cout << "enter the message to hide : ";

	cin.ignore();
	getline(cin, msg);

	msg += "##";

	Convert.ToBinary(msg, binaryMsg);       

	int k = 0;
	rep(i,0,pixels.size()) {
		if(k == binaryMsg.size()) break;
		rep(j,0,pixels[i].size()) {
			if(k == binaryMsg.size()) break;
			if(binaryMsg[k++]) pixels[i][j] |= 1;
			else pixels[i][j] &= ~1; 
		}
	}

	rep(i,0,pixels.size()) {
		rep(j,0,pixels[i].size())
			out << pixels[i][j] << "  ";
		out << endl;
	}
}


void Decrypt() {

	Input();
	
	Converter Convert;

	rep(i,0,pixels.size()){
		rep(j,0,pixels[i].size()){
			binaryMsg.push_back(pixels[i][j] & 1);
		}
	}

	string res = Convert.ToString(binaryMsg);

	cout << "\nMessage : " << res << endl;

}

int main() {

	int opt;
	cout << "1. Encrypt\n2. Decrypt\n\nEnter your option : ";
	cin>>opt;

	if(opt == 1) Encrypt();

	else if(opt == 2) Decrypt();

	return 0;
}
