class Solution {
public:
    struct isGreater{
     bool operator()( ListNode* a, ListNode* b){
        return a -> val >= b -> val;
    }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //Take each element, place into heap, and then take them out
        if(lists.size() == 0)
            return NULL;
        priority_queue <ListNode*, vector<ListNode*>,isGreater> pq;
        for(int i =0; i < lists.size();++i)
            {
            auto a = lists[i]; 
            if(!a)
                continue;
            pq.push(a); //we only need the iterator 
            }
        ListNode* root = new ListNode(); //dummy node first
        ListNode* trav = root;

        while(!pq.empty())
        {
            ListNode* curr = pq.top();
            if(!curr)
                break;
            trav -> next = curr;
            trav = curr;
            pq.pop();
            if(curr -> next)
                pq.push(curr -> next);
        }

        return root -> next;
    }
};
