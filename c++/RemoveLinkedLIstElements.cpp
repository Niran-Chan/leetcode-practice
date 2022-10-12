#include <iostream>
#include <vector>






 //Definition for singly-linked list.
 struct ListNode {
     int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 


 ListNode* listPopulation(std::vector <int> li)
 {	ListNode headNode = ListNode(li[0]);
 	ListNode *head = &headNode;
 	ListNode* temp = &headNode;
    ListNode iterNode;

 	for(int i =1;i < li.size();i ++ )

		{	
			iterNode = ListNode(li[i]);
			temp-> next = &iterNode;
			temp = temp->next;

			}

                      

			return head;
 }


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* trav = head;
        ListNode* lag = head;
        if(!head) return head;
        /*
        while(trav->next && trav ->next -> next)

        {	
            trav = trav -> next;
        	if(trav->val == val)
        	{
        		lag -> next = trav->next;
        	}
        	
        	lag = lag -> next;

        }
        */

std::cout << head -> val << std::endl ;
return head;
    }

};





int main ()
{
	std::vector <int> list  = {1,2,6,3,4,5,6};
	int val = 6;
	ListNode* head = listPopulation(list);	
	Solution result;
	ListNode* output = result.removeElements(head,val);
	std::cout << output -> val << std::endl;


}