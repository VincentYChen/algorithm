#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int> &num) {

        quickSort(num, 0, num.size() -1);

        string result;

        vector<int>::iterator iter = num.begin();

        if (*iter == 0) return "0";

        for ( ;iter != num.end(); ++iter){
            result += intToStr(*iter) ;
        }

        return result;           
        
    }
private:

    string intToStr(int i){
        stringstream res;
        res << i;
        return res.str();
    }
    bool compareNum(int lft, int rgt) {

        string sum1 = intToStr(lft) + intToStr(rgt);
        string sum2 = intToStr(rgt) + intToStr(lft);

        // std::cout << "Will judge between " << sum1 << " and " << sum2 << std::endl;
        
        return sum1 > sum2;
    }
    
    void quickSort(vector<int> &num, int elementLo, int elementHi){
        if (elementLo >= elementHi ){
            return;
        }

        int pivot = partition( num, elementLo, elementHi);

        quickSort(num, elementLo, pivot-1 );
        quickSort(num, pivot + 1, elementHi );
        
    }

    int partition(vector<int> &num, int elementLo, int elementHi){
        int pivotIndex = choosePivot(num, elementLo, elementHi);

        int pivotValue= num[pivotIndex];

        swap(num, pivotIndex, elementHi);

        int storeIndex = elementLo;

        for (int i = elementLo; i != elementHi; ++i){
            if ( compareNum(num[i], pivotValue)){
                // std::cout << "Compare True" << std::endl;
                swap(num, i, storeIndex);
                ++storeIndex;
            }
        }

        swap(num, storeIndex, elementHi);

        return storeIndex;

    }

    int choosePivot(vector<int> &num, int elementLo, int elementHi){
        int pivotIndex = (elementLo + elementHi) / 2;

        // std::cout << "Choose pivot Value " << num[pivotIndex] << std::endl;

        return pivotIndex;
    }

    void swap(vector<int> &num, int leftIndex, int rightIndex){
        // std::cout << "Will swap element :" << leftIndex << " with "<< rightIndex << std::endl;
        if ( leftIndex == rightIndex ){
            return;
        }

        print(num);
        int tmp = num[leftIndex];
        num[leftIndex] = num[rightIndex];
        num[rightIndex] = tmp;
        print(num);
    }

    void print(std::vector<int> &num){
        // for (vector<int>::iterator iter = num.begin(); iter != num.end(); ++iter){
        //     std::cout << *iter << " ";
        // }
        // std::cout << std::endl;

    }
};

int main()
{
    vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    Solution s;
    std::cout << s.largestNumber(test) << std::endl;

    return 0;
}
