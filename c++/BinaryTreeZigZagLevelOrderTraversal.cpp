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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //we can BFS and keep track of whether left to right or right to 
left
        vector<vector<int>> ans;
        queue<TreeNode* > q;
        
        if(root == NULL)
            return {};

        q.push(root);
        bool isLeft = true;
        while(!q.empty()){

            int n = q.size();
            vector<int> tmp(n); //size of tmp is size n
            for(int i =0; i < n;++i){
                TreeNode* currRoot = q.front();
                q.pop();
                if(isLeft)
                    tmp[i] = currRoot -> val;
                else
                    tmp[n-i-1] = currRoot -> val;
                if(currRoot-> left)
                    q.push(currRoot -> left);
                if(currRoot -> right)
                    q.push(currRoot -> right);
            }
            isLeft = !isLeft;
  
            if(!tmp.empty())
                ans.push_back(tmp);
        }
        return ans;
    }
};
