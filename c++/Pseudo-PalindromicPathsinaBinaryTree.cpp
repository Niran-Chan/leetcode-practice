/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int cnt = 0;
    void dfs(TreeNode* root,vector<int> v)
    {
        
        if(root == NULL)
            return;
        
         v[root->val]++;
        if(root -> left == NULL && root -> right == NULL)
        {

            int isOdd = 0;
            for(auto digit : v)
            {
                if(digit %2)
                    isOdd++;
                
            }
            if(isOdd <= 1)
                cnt++;
            
            return ;
            
        }
       
        dfs(root->left,v);
        dfs(root->right,v);
        return;
        
        
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> v(10,0);
        dfs(root,v);
        return cnt;
    }
};