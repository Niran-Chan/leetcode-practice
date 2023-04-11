
class Solution {
public:
    ListNode* middleNode(ListNode* head){
       //if(head == NULL || head->next==NULL) return NULL;
        ListNode* fast = head,* slow = head,* prev = slow;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = NULL;
        return slow;
    }

    TreeNode* addToTree(ListNode* start){
        if(!start)
            return NULL;
        if(start -> next == NULL) //we are at the end of the list
            {return new TreeNode(start -> val);}
        
        ListNode* target = middleNode(start); //find the current middle listnode
        TreeNode* currRoot = new TreeNode(target -> val); 
        currRoot -> right = addToTree(target -> next); //need to move to find the next middle as we alr have assigned the current middle
        target -> next = NULL;
        currRoot -> left = addToTree(start); 
        return currRoot;

    }
    TreeNode* sortedListToBST(ListNode* head) {
        //recursively find the middle of the linked list, and add that as the current root node, and then find the subtree for that
        if(!head)
            return NULL;
        return addToTree(head);
    }
};

