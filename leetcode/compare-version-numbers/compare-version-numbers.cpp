#include <iostream>

using namespace std;


class Solution {
public:
    int compareVersion(string version1, string version2) {
    	int subversion1 = getPriVersion(version1);
    	int subversion2 = getPriVersion(version2);

    	if (subversion1 > subversion2 ){
    		return 1;
    	} else if (subversion1 < subversion2){
    		return -1;
    	}

    	subversion1 = getSecVersion(version1);
    	subversion2 = getSecVersion(version2);

    	if (subversion1 > subversion2){
    		return 1;
    	} else if ( subversion1 < subversion2) {
    		return -1;
    	}

    	return 0;
        
    }


    int getPriVersion(const string& version)
    {
    	int index = version.find('.');

    	int priVersion = atoi(version.substr(0, index).c_str());
    	// cout << "Get a Pri Version " << priVersion << endl;
    	return priVersion;
    }


    int getSecVersion(const string& version)
    {
    	int index = version.find('.');

    	if (index == string::npos) return 0;

    	int secVersion = atoi(version.substr(index + 1).c_str());
    	cout << "Get a sec version " << secVersion << endl;
    	return secVersion;
    }
};

int main()
{
	string version1("1");
	string version2("1.13");
	Solution s;
	cout << s.compareVersion(version1, version2) << endl;
	return 0;
}