#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
    	bool negative = false;
    	if ( x < 0 ){
    		x = -x;
    		negative = true;
    	}

    	string s = convertIntToStr(x);

    	for (int index = 0; index != s.length()/2; ++index){
    		swap(s,index, s.length() - index - 1);
    	}


    	int res = convertStrToInt(s);

    	if (negative) res = -res;

    	return res;
        
    }

    void swap(string& s, int index_left, int index_right){
    	char tmp = s[index_left];
    	s[index_left] = s[index_right];
    	s[index_right] = tmp;
    }

    int convertStrToInt(const string& str){
    	// cout << "str " << str << ": INT_MAX" << convertIntToStr(INT_MAX) << endl;

    	if (compareStrNum(str, convertIntToStr(INT_MAX)))
    		return 0;

    	return atoi(str.c_str());
    }

    string convertIntToStr(int num){

    	stringstream tmpstream;
    	tmpstream << num;
    	return tmpstream.str();
    }

    bool compareStrNum(const string& s1, const string& s2){
    	if (s1.length() != s2.length()){
    		return s1.length() > s2.length();
    	}

    	return s1 > s2;
    }
};


int main(int argc, char ** argv)
{
	Solution s;

	cout << s.reverse(123) << endl;
	cout << s.reverse(-1234) << endl;
	return 0;
}