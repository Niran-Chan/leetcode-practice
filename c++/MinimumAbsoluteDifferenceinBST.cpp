/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), 
left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diff = 100001,val = -1;
    void dfs(TreeNode* root){
        if(root -> left)
            dfs(root -> left);
        
        if(val >= 0)
            diff = min(diff,abs(root -> val - val));
        
        val = root -> val;
        
        if(root -> right)
            dfs(root -> right);
    }
    int getMinimumDifference(TreeNode* root) {
        //INORDER TRAVERSAL SOLUTION
        /*
        1. Go to edge node on the left tree
        2. set the current node as the prev val
        3. As we go back up, we compare the difference between curr node 
and prev val, and set curr val as prev val for the next node up
        
        */
        dfs(root);
        return diff;
    }
};
