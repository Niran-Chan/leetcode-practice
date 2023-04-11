class Solution {
public:
    bool dfs(TreeNode* r1,TreeNode* r2)
        {
            if(!r1 && !r2) return true; //both null means true
            if(!r1 && r2 || !r2 && r1) return false; //one of them is null
            if(r1 -> val != r2 -> val) return false;
            return dfs(r1 -> left,r2 -> right) && dfs(r1 -> right,r2 -> left);

        }
    bool isSymmetric(TreeNode* root) {
        return dfs(root -> left, root -> right);
    }
};
