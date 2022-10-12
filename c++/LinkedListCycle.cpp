#include <iostream>
#include <vector>
#include <algorithm>

//IMPORTANT CONCEPT ON LINKED LISTS!
//using namespace std;

 // Definition for singly-linked list.
    struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {} //constructor
  };
//2 pointer solution

class Solution {
public:
    bool hasCycle(ListNode *head) {
        //using two pointers,slow and fast,we can find traversal
           
        if(!head) return false;

        ListNode *slowptr = head,*fastptr = head;
                  std:: cout << "Slow pointer :"<<slowptr << std::endl;
        while( fastptr -> next && fastptr -> next -> next )
        {   
            
            
            //moving pointer to next node in list
            slowptr = slowptr ->  next ;
  
            fastptr = fastptr -> next->next ;
            if(slowptr == fastptr) return true;
        }
        return false;

    }
};

int main()
{   
   
    Solution result;
    
    int list [1] = {1};
    //head pointer
    //temp pointer
    //new pointer
   // ListNode *n,*temp,*head;
    
 ListNode start = ListNode(list[0]);
 ListNode *temp = &start;

 ListNode trav = start;
 ListNode *head = &start;
 std::cout <<   "Head memory addy:" << &start << std::endl;
 std::cout << temp -> val << std::endl;
    for (int i=1;i < 1;i++)
    {
        // Construct stores val -> list[i] and next as NULL
       trav = ListNode(list[i]);
        std::cout << temp -> val << std::endl;
       //Traverse to link the prev node to the current one
       temp -> next = &trav;
       temp = temp -> next;
       std::cout << "Traverse Ptr addy:" << &trav << std::endl;

    }

    bool output = result.hasCycle(head);
    std::cout << output;

    return 0;
}