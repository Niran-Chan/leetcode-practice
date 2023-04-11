
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
       if(!root)
        return 0;
        int rightSub = sumOfLeftLeaves(root -> right); 
        int leftSub = sumOfLeftLeaves(root -> left);
        if(root && root -> left && !root -> left -> left && !root -> left -> right)
        return rightSub + root -> left -> val;

        return leftSub + rightSub;

    }
};
