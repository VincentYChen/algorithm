#include <iostream>
#include <string>
#include <sstream>

using namespace std;



class Solution {
public:
    int atoi(const char *str) {

    	const char * ch = str;
    	bool negative = false;
    	int pos = 0;

    	string resStr;

    	int res = 0;

    	while (*ch == ' ' ) ++ch;

    	while (validChar(ch, pos)){

    		if (*ch == '-' ){
    			negative = true;
    		} else if (*ch == '+' ){
    			negative = false;
    		} else{
    			resStr += *ch;
    		}
    		++ch;
    		++pos;
    	}

    	if (negative){
    		if (compareStrNum(string(resStr), convertIntToStr(INT_MAX + 1))) return INT_MIN;
    	} else {
    		if (compareStrNum(string(resStr), convertIntToStr(INT_MAX))) return INT_MAX;
    	}


    	for (int i = 0; i != resStr.length(); ++i){
    		res *= 10;
    		res += resStr[i] - '0';
    	}

    	if (negative){
    		res = -res;
    	}
    	return res;
        
    }

    bool validChar(const char * ch, int pos){
    	if ( *ch == '+' || *ch == '-' )
    		return pos == 0;
    	return (*ch >= '0' && *ch <= '9');
    }

    string convertIntToStr(unsigned int num){

    	stringstream tmpstream;
    	tmpstream << num;
    	return tmpstream.str();
    }


    bool compareStrNum(const string& s1, const string& s2){
    	// cout << s1 << " " << s2 << endl;
    	if (s1.length() != s2.length()){
    		return s1.length() > s2.length();
    	}

    	return s1 > s2;
    }
};


int main(int argc, char** argv)
{

	Solution s;

	string s1("-2147483648");
	cout << s.atoi(s1.c_str()) << endl;

}