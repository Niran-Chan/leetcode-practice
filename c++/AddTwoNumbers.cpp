#include <iostream>
#include <list>

using namespace std;
 //Definition for singly-linked list.
 struct ListNode {
    int val;
     ListNode *next;
  	 ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
  	 ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode final (0),*ptr = &final;
        int temp = 0;
        //simple math addition instead of constantly casting and looping
        while(l1|| l2||temp)
        {
            int total = (l1 ? l1 -> val : 0 ) + (l2  ? l2 -> val : 0) + temp ;
            temp = total/10;
            
            ptr -> next = new ListNode(total % 10);
            ptr = ptr -> next;
            l1 = (l1 ? l1 -> next : l1);
            l2 = (l2 ? l2 -> next : l2);
        }
        
    
        return final.next;
        }
      
};




int main()
{
	//Create a linked list with struct type ListNode
	//list <int> list1 = {2,4,3},list2 = {5,6,4} ; 

	Solution obj;
	ListNode* final = obj.addTwoNumbers(l1,l2);
	for(auto elem : final)
		cout << elem << endl;

	return 0;

}