/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(TreeNode* root1,TreeNode* root2)
    {
        if(root1 == NULL || root2 == NULL)
        {
            return (root1)?root1:root2;
        }
        root2->val += root1->val; 
        root2 -> left = dfs(root1->left,root2->left);
        root2 -> right = dfs(root1->right,root2->right);
        
        return root2;
    }
    
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        TreeNode* root3 = dfs(root1,root2);
        return root3;
    }
};