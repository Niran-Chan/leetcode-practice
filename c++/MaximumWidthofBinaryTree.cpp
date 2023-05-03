class Solution {
public:
    int widthOfBinaryTree(TreeNode* a) {
        vector<int>v;
        if(!a)
        return 0;
        int ans = 1;
        queue<pair<TreeNode*,long long int>>q;
        q.push({a,0}); //Node and index
        while(!q.empty()) //BFS
        {
            int sz = q.size(); 
            int a1 = 0, b1 = 0;
            int l = 0;
            int mn = q.front().second;
            for(int i = 0; i < sz; i++)
            {
                auto p = q.front();
                TreeNode* b = p.first;
                // To avoid integer overflow,
                // we modify all the address values with 
                // respect to leftmost tree address value.
                long long int k = p.second-mn;
                q.pop();
                // leftmost node
                if(i == 0)
                a1 = k;
                // rightmost node
                if(i == sz-1)
                b1 = k;

                if(b->left)
                q.push({b->left,2*k+1}); //attach index of node
                
                if(b->right)
                q.push({b->right,2*k+2}); //attach index of node
            }
            // To store maximum difference.
            ans = max(ans,b1-a1+1);
        }

        return ans;
        
    }
};
