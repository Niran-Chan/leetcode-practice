class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //use hash table to see if visited node. if it is then we have reached the starting
        unordered_map <ListNode*,int> visited;
        while(head){
            if(visited[head])
                return head;
            
            visited[head]++;
            head = head -> next;

        }
        return head;
    }
};
