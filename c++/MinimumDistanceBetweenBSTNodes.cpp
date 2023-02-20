
class Solution {
public:
    void dfs(TreeNode* root,int&prevVal, int& minDiff){
        if(root == NULL)
            return;
        dfs(root -> left,prevVal,minDiff);
        if(prevVal != -1)
            minDiff = min(minDiff,abs(root->val - prevVal));
        prevVal = root -> val;
        dfs(root -> right,prevVal,minDiff);
    }
    int minDiffInBST(TreeNode* root) {
        //Inorder Traversal
        int minDiff = INT_MAX,prevVal = -1;
        dfs(root,prevVal,minDiff);
        return minDiff;
    }
};
