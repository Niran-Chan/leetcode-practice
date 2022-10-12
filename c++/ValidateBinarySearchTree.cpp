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
    int helper(TreeNode* root, long long mn,long long  mx)
    {
        if(root == NULL)
            return true;
        
        if(root->val <= mn || root->val >= mx) return false;
        
        bool left = helper(root->left, mn, root->val);
        bool right = helper(root->right, root->val, mx);
        
        return left && right;
    }
    
    
    
    bool isValidBST(TreeNode* root) {
        //recursively check each node and the value before
        bool res = helper(root,LONG_MIN,LONG_MAX);
        return res;
        }
};
