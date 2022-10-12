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
    void dfs(TreeNode* root,int x,int& count)
    {
        if(root == NULL)
            return;
        if(root -> val >= x) count ++;
        x = max(x,root -> val);
        dfs(root -> left,x,count);
        dfs(root -> right,x,count);
        return;
        
    }
    
    
    int goodNodes(TreeNode* root) {
    //Recursively search the tree, with the next value must be larger than 
the current
    int count = 0;
    dfs(root,root -> val,count);
    return count;
    }
};
