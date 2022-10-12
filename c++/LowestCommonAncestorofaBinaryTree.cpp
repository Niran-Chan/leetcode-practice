/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   
    TreeNode* dfs(TreeNode* head,TreeNode* p, TreeNode *q )
    {
        // Return current node if we reach
        if(head == NULL || head == p || head == q)
            return head;
        TreeNode *head1 = dfs(head -> left,p,q); //recurse to left subtree
        TreeNode *head2 = dfs(head -> right,p,q);//recurse to right sub tree
        return (head1 && head2) ? head : (head1 ? head1 : head2) ; //if both heads exist, return current head
        //else return the head that is defined from the recursion that we called 
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  
        return dfs(root,p,q);
        }
};