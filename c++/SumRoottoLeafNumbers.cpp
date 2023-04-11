class Solution {
public:
    int dfs(TreeNode* root,string curr){
        if(!root)
            return 0;
        curr += to_string(root ->val);
        if(!root ->left && !root -> right)
            return stoi(curr); 
        else
            return dfs(root -> left,curr) + dfs(root -> right,curr);
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root,"");
    }
};
