#ifndef __CONVERTER_HPP__
#define __CONVERTER_HPP__

class Converter {

public:

	Converter(){}
	
	string ToString(vector<int>& M) {
		string res = "";

		for(int i=0;i<M.size();i+=8){
			vector<int> v;
			for(int j=i;j<i+8;++j) v.push_back(M[j]);
		
			res += ToChar(v);
			if((res.back() == '#') && (res[res.size()-2] == '#')) break;
		}

		res.pop_back(); res.pop_back();

		return res;
	}

	
	void AddLeadingZeroes(const int len, string& s) {
		int n = s.size();
		for(int i=0;i<len-n;++i) s = "0" + s;
	}

	
	void ToBinary(string& s, vector<int>& M) {
		for(int i=0;i<s.size();++i) {
			int n = s[i];
			string lookup = "01";
			string res = "";
			while(n) {
				res  = lookup[n&1] + res;
				n >>= 1;
			}

			AddLeadingZeroes(8, res); 
			for(int j=0;j<res.size();++j) M.push_back(res[j]-'0');  
		}
	}


	string ToChar(vector<int>& v) {
		int sum = 0, mul = 1;
		for(int i=v.size()-1; i>=0; --i){
			sum += v[i] * mul;
			mul <<= 1;
		}

		char c[5];
		sprintf(c, "%c", sum);
		string ret = c;
		return ret;
	}

};


#endif
