#include <iostream>
#include <algorithm> 
#include <stdlib.h>

class Solution {

public:

    int maxProduct(int A[], int n) {
        int maxhere = A[0];
        int minhere = 0;
        int maxherebefore = A[0];
        int minherebefore = A[0];
        int maxsofar = A[0];
        for (int i = 1; i < n ; ++i){
            /*
            std::cout << i << ":" << A[i] << std::endl;
            std::cout << i << ":maxhere" << maxhere << std::endl;
            std::cout << i << ":minhere" << minhere << std::endl;
            */
            maxhere=std::max(std::max(maxherebefore*A[i],minherebefore*A[i]),A[i]);
            minhere=std::min(std::min(maxherebefore*A[i],minherebefore*A[i]),A[i]);
            maxsofar = std::max(maxhere,maxsofar);
            maxherebefore = maxhere;
            minherebefore = minhere;
            /*
            std::cout << i << ":maxhere" << maxhere << std::endl;
            std::cout << i << ":minhere" << minhere << std::endl;
            */
        }
        return maxsofar;


    }

};
int main()
{
    //int A[]={0,-1,2,3,-4,5,0};
    //int A[]={-2};
    //int A[]={-4,-3};
    //int A[]={3,-1,4};
    int A[]={-4,-3,-2};
    Solution s;
    std::cout << "The answer is: " << s.maxProduct(A,sizeof(A)/sizeof(int)) << std::endl;
    return 0;
}


