#include <iostream>

using namespace std;



class Solution {
public:
    int titleToNumber(string s) {
    	int res = 0;
    	for (int i = 0; i < s.length(); ++i){
    		res *= 26;
    		res += s[i] - 'A' + 1;
    	}
        return res;
    }
};



int main(int argc, char** argv)
{

	Solution s;
	cout << s.titleToNumber(string("AB")) << endl;
	return 0;
}