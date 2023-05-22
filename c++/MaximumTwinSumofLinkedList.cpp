class Solution {
public:
    int pairSum(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while(temp){
            n++;
            temp = temp -> next;
        }

        int ans =0, i = (int)((n/2)-1);
        stack <int> stk;
        ListNode* trav = head;
        while(trav){
            if(i >= 0)
                {
                    stk.push(trav -> val);
                    --i;
                }
            else{
                if(!stk.empty())
                    {ans = max(ans,stk.top() + trav -> val);
                    stk.pop();
                    }
                else
                    break;
            }
            trav = trav -> next;
        }
        return ans;
    }
};
