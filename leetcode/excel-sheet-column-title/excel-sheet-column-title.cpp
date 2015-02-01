#include <iostream>

using namespace std;


class Solution {
public:
    string convertToTitle(int n) {

    	string res;

    	while (n){
    		res += 'A' + (n - 1)% 26;
    		n = (n - 1) / 26;
    	}

    	for (int i = 0; i < res.length()/2; ++i){
    		char tmp =  res[i];

    		res[i] = res[res.length() - i -1];
    		res[res.length() - i -1] = tmp;

    	}

    	return res;
        
    }
};

int main(int argc, char ** argv)
{
	Solution s;
	cout << s.convertToTitle(28) << endl;
	cout << s.convertToTitle(26) << endl;
	return 0;
}