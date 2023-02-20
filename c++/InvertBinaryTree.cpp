class Solution {
public:
    TreeNode* dfs(TreeNode* root){
        if(root == NULL)
            return root;
        TreeNode* leftTree = dfs(root->left);
        TreeNode* rightTree = dfs(root->right);
        root -> left = rightTree;
        root -> right = leftTree;
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        //we form a new tree, then attach it to the root later
        return dfs(root);
    }
};
