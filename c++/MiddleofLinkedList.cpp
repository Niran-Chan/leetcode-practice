class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int cnt = 0;
        ListNode* fast = head,*slow = head;
        //Traverse to end of linked list
        while(fast){
            fast = fast->next;
            cnt++;
        }
        cnt /=2;
        while(cnt)
            {
                slow= slow->next;
                cnt--;
            }
        return slow;


    }
};