#include <iostream>

using namespace std;


class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
    	int up = true;

    	int record[1000000] = {0};

    	if (m >= 2) up = (A[0] < A[1]);

    	int j = 0;
    	for (int i = 0; i != n; ++i){
    		if (up){
    			while (A[j] < B[i] && j < m ) ++j;
    		} else {
    			while (A[j] > B[i] && j < m ) ++j;

    		}

    		// std::cout << "Record " << i << ":" << j << std::endl;
    		record[i] = j;
    	}

    	doMerge(A,m,B,n,record);        
    }

    void doMerge(int A[], int m, int B[], int n, int record[]){
    	for (int i = m-1; i >= 0; --i){
    		int delta = findDelta(i, record, n);
    		move(A, i, delta);
    	}

    	for (int i = 0; i < n ; ++i){
    		A[i + record[i]] = B[i];
    	}

    }

    void move(int A[], int i, int delta){
    	// std::cout << "Move the element from " << i << " to" << i + delta << std::endl;
    	A[i+delta] = A[i];
    }

    int findDelta(int index, int record[], int n){
    	int delta = n - 1;
    	while (record[delta] > index){
    		--delta;

    	}
    	// std::cout << "Get a delta value equals " << delta + 1 << std::endl;
    	return delta + 1;
    }
};


int main(int argc, char ** argv)
{
	int a[20] = {1};
	int b[5] = {2};
	Solution s;

	s.merge(a,1, b,1);

	for (int i = 0 ; i< 7; ++i){
		std::cout << a[i] << " ";
	}
	return 0;
}