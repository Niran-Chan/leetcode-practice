/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), 
left(left), right(right) {}
 * };
 */
class Solution {
public:
    string dfs(TreeNode* root,string currPath,unordered_map <string,int>& 
mp,vector<TreeNode*> &ans){
        if(root == NULL)
            {return "#";}

        string left = dfs(root -> left,currPath,mp,ans);
        string right = dfs(root -> right,currPath,mp,ans);
        currPath += left + "," + right + "," + to_string(root -> val);
        if(mp[currPath] == 1)
            {ans.push_back(root);}
        mp[currPath]++;
        //form a string for the subtrees,# for NULLs,L for left and R for 
Right
        return currPath;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        //post order traversal
        //Traverse left subtree first, then root, then right
        //How do we keep track of the combination of nodes that we visit?
        //we populate a hashtable for existing linkages
        unordered_map<string,int> mp;
        vector<TreeNode*> ans;
        dfs(root,"",mp,ans);
        return ans;
        //hashmap to keep track of prev node


    }
};
