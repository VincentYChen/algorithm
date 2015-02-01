#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {

    	map<int, int> numSize;

    	for (vector<int>::iterator iter = num.begin(); iter != num.end(); ++iter){
    		map<int, int>::iterator foundItem = numSize.find(*iter);
    		if ( foundItem == numSize.end() ){
    			numSize.insert(pair<int,int>(*iter, 1));
    		} else {

    			// cout << foundItem->second << " " << num.size() << endl;

    			if (foundItem->second > (num.size() / 2) ){
    				return foundItem->first;
    			}

    			++foundItem->second;
    		}
    	}

    	for (map<int, int >::iterator iter = numSize.begin(); iter != numSize.end(); ++iter){
    		if (iter->second > (num.size() / 2)) return iter->first;
    	}
        
    }
};


int main(int argc, char** argv)
{
	Solution s;

	std::vector<int> v;
	// v.push_back(5);v.push_back(5);v.push_back(3);v.push_back(3);v.push_back(3);v.push_back(3);
	// v.push_back(3);v.push_back(5);v.push_back(3);
	v.push_back(1);

	cout << s.majorityElement(v) << endl;
	return 0;
}