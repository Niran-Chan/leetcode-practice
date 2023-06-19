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
    int maxLevelSum(TreeNode* root) {
        //Priority is given to smaller level
        //BFS to find sum
        queue<TreeNode*> q;
        int lvl =1,mx = root -> val,ans = lvl;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int sm =0;
            for(int i =0; i < n; ++i){
                auto curr = q.front();
                q.pop();
                sm += curr -> val;
                if(curr -> left)
                q.push(curr -> left);
                if(curr -> right)
                q.push(curr -> right);
            }
            if(sm > mx)
                {
                    mx = sm;
                    ans = lvl;
                }
            lvl++;
        }
        return ans;
    }
};
