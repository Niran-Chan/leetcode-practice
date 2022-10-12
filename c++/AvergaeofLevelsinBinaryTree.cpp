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
    vector<double> averageOfLevels(TreeNode* root) {
        //bfs
        queue <TreeNode*> q;
        vector<double> res;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            long long int sm = 0;
            for(int i =0; i < n;i++)
            {
                TreeNode* x = q.front();
                q.pop();
                if(x->left)q.push(x -> left);
                if(x->right)q.push(x -> right);
                sm += x -> val;
            }
            long double avg = double(sm)/n;
            res.push_back(avg);
            
        }
        return res;
        
    }
};
