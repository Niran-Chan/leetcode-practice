class Solution {
public:
    bool solve(TreeNode* root,int a){
        if(root == NULL)
            return a == 0;
        a -= root -> val;
        if(root -> left && root -> right == NULL)
            return solve(root ->left,a);
        else if (root -> right && root -> left == NULL)
            return solve(root -> right,a);
        else
            return solve(root -> left,a) || solve(root -> right,a);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        //Either way, we require to reach the end
        //Root is a must
        //We go down recursively each node and see if we are able to reach 
targetsum
        if(root == NULL)
            return false;
        return solve(root,targetSum);


    }
};
