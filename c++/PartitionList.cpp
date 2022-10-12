/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
    ListNode *head1 = new ListNode(0),*head2 = new ListNode(0),*ptr1=head1,*ptr2=head2,*ctr = head;

    while(ctr)
    {
        if(ctr -> val < x)
        {
            ptr1-> next = ctr;
            ptr1 = ptr1->next;
        }
        else
        {
            ptr2 -> next = ctr ;
            ptr2 = ptr2 -> next;
        }
        ctr = ctr -> next;
        
    }
        ptr2 -> next = NULL;
        ptr1 -> next = head2 -> next;
    
    return head1->next;
    
    
    }
};