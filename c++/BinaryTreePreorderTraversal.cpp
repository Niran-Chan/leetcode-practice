class Solution {
public:
    vector<int> ans;
    void recursiveSolution(TreeNode* root){
        if(!root)
            return;
        ans.push_back(root -> val);
        recursiveSolution(root->left);
        recursiveSolution(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
    if(!root)
        return ans;
    recursiveSolution(root);
    return ans;

    }
};
