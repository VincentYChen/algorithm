#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
    	if (n == 1) return string("1");

    	string s = countAndSay(n - 1);

    	return countSay(s);
        
    }

    string countSay( const string& s){
    	stringstream res;

    	char currentValue = s[0];
    	int index = 1;
    	int count = 1;

    	while (index < s.length()){
    		if (s[index] == currentValue){
    			++count;
    		} else {
    			res << count << currentValue;
    			count = 1;
    			currentValue = s[index];
    		}
    		++index;
    	}
    	if (count){
    		res << count << currentValue;
   		}

   		cout << res.str() << endl;
    	return res.str();
    }
};


int main(int argc, char ** argv)
{
	Solution s;

	cout << s.countAndSay(65535) << endl;
	return 0;
}