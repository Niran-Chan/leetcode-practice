class Solution {
public:
    bool recursiveSearchTree(TreeNode* p,TreeNode* q){
        if(!p || !q){
            if(p || q)
                return false;
            return true;
        }
        if(p->val != q->val)
            return false;
        return recursiveSearchTree(p->left,q->left) && 
recursiveSearchTree(p->right,q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return recursiveSearchTree(p,q);
                
    }
};
