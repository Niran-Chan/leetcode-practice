class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        //iterate to end to find size, determine number of steps, iterate from another pointer 
        ListNode* trav = head;
        int n =0 ;
        while(trav){
            n++;
            trav = trav -> next ;
        }
         //if theres only two elements, we remove the tail
        if(n < 2){
            if(n == 1){
                return NULL;
            }
            head -> next = NULL;
            return head;

            }

        ListNode* prev = head;
    n=n/2 - 1;
           
        
        while(n--)
            prev = prev -> next;    

        prev -> next = prev -> next -> next;
        return head; 

        
    }
};
