class Solution {
public:
    int maxSum = INT_MIN;
    int solve(TreeNode* root){
        if(root == NULL)
            {
                return 0;
            }
        int left = solve(root -> left);
        int right = solve(root -> right);
        maxSum = max(maxSum,max(root->val,max(left + root->val + 
right,max(left + root -> val,right + root->val))));
        return max(max(left,right) + root->val,root->val);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};
