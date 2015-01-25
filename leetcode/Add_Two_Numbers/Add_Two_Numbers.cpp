/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #include <iostream>
 #include <cstdlib>

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

    	int remain = 0;
    	ListNode * res ;

    	ListNode *tmp;

    	bool startFlag = true;

    	while (l1 != NULL || l2!= NULL || remain != 0){
    		int left = 0;
    		if (l1 != NULL){
    			left = l1->val;
    		}

    		int right = 0;
    		if (l2 != NULL){
    			right = l2->val;
    		}

    		int tmpValue = left + right + remain;
    		// std::cout << "tmp value is" << tmpValue << std::endl;

    		if (tmpValue >= 10){
    			remain = tmpValue / 10;
    			tmpValue = tmpValue % 10;
    		} else {
    			remain = 0;
    		}



    		if (l1!= NULL) l1= l1->next;
    		if (l2!= NULL) l2= l2->next;

    		if (startFlag){
    			// std::cout << "The first node value is " << tmpValue << std::endl;
    			res = new ListNode(tmpValue);
    			tmp = res;
    			startFlag = false;
    		} else {
    			// std::cout << "The node value is " << tmpValue << std::endl;
    			tmp->next = new ListNode(tmpValue);
    			tmp = tmp->next;
    		}

    	}

    	return res;
        
    }

   
    	static void printLNode(ListNode* list){
	    	while (list != NULL){
				std::cout << list->val << "-->";
				list = list->next;
			}
			std::cout << std::endl;

    	}
};


int main()
{
	ListNode * l1 = new ListNode(5);
	// l1->next = new ListNode(4);
	// l1->next->next = new ListNode(3);
	// l1->next->next->next = new ListNode(6);

	ListNode * l2 = new ListNode(5);
	// l2->next = new ListNode(6);
	// l2->next->next = new ListNode(4);

	Solution::printLNode(l1);
	Solution::printLNode(l2);

	Solution s;
	ListNode * l3 = s.addTwoNumbers(l1,l2);

	Solution::printLNode(l3);
	return 0;
}