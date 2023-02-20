class Solution {
public:
    int solve(TreeNode* root,int minNum,int maxNum ){
        //memo
        if(root == NULL){
            //return absolute difference
            return maxNum - minNum;
        }
        if(root -> val >maxNum)
            maxNum = root -> val;
        if (root -> val < minNum)
            minNum = root -> val;
        int left = solve(root ->left,minNum,maxNum);
        int right = solve(root -> right,minNum,maxNum);
        if(left > right)
            return left;
        return right;

    }
    int maxAncestorDiff(TreeNode* root) {
     return solve(root,INT_MAX,INT_MIN);
    }
};
