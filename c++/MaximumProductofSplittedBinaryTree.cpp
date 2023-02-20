class Solution {
public:
    int MOD = 1000000007;
    long long GMAX=INT_MIN;

    int totalSumOfTree(TreeNode* root){
        if(root == NULL)
            return 0;
        
        return totalSumOfTree(root -> left) + totalSumOfTree(root -> right) + root->val;
    }
    int solve(TreeNode* root,int total){
        if(root->left == NULL && root -> right == NULL)
            {
                GMAX = max(GMAX,(((long long )total - (long long )root->val) * (long long )root -> val ));
                return root->val;
            }
        long long left = 0,right = 0;
        if(root -> left)
            left = solve(root -> left,total);
        if(root -> right)
            right = solve(root->right,total);
        long long  currSm = left + right + root -> val;
        long long  currProd = ( currSm * (total - currSm) );
        GMAX=max(GMAX,currProd);
        return currSm; 
    }
    int maxProduct(TreeNode* root) {
        //keep sum until the last node, and return the maximum as we return back
        int total = totalSumOfTree(root);
        solve(root,total);
        return GMAX % MOD;
    }
};