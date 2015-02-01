#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {

    	if (nRows <= 1) return s;

    	string res;

    	int T = nRows * 2 - 2;

    	for ( int rowNum = 0; rowNum != nRows; ++rowNum){
    		dealWithRow(res, s, rowNum, T, nRows);
    	}

    	return res;
        
    }

    void dealWithRow( string& res, const string s, int rowNum, int T, int nRows){
    	int index = rowNum;

    	while ( index < s.length() ){
    		res += s[index]; 

    		if ( rowNum != 0 && rowNum != nRows - 1){
    			int secondIndex = findASecondIndex(index, T);
    			if (secondIndex < s.length()){
    				res += s[secondIndex];
    			}  	

    		}

    		
    		index += T;

    	}
    }

    int findASecondIndex(int index, int T){
    	int res = ((index/T) + 1) * T - index % T;
    	// cout << "find a index " <<  res << endl;
    	return res;
    }
};

int main()
{

	string input = "PAYPALISHIRING";
	Solution s;

	cout << s.convert(input, 3) << endl;
	return 0;
}