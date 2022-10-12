/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    Node* bfs (Node* head)
    {
        if(!head) return head;

        queue <Node*> q;
        q.push(head);
        while(!q.empty())
        {
            int n = q.size();
            for(int i =0; i < n;i++)
            {
                Node* src = q.front();
                q.pop();
                if(i < n-1) //Until second last element
                {
                    Node * dest = q.front();       
                    src -> next = dest;

                }
                else
                    src -> next = NULL;
                
                if(src -> left != NULL)q.push(src -> left); 
                if(src -> right != NULL)q.push(src -> right); 

                }
            
        }
        return head;
    }
    
    Node* connect(Node* root) {
        return bfs(root);
    }
};
