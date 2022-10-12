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
    TreeNode* helper (int l,int r,vector<int> &nums)
    {
        if(l>=r)
            return NULL;
        int m = (l + r)/2;
        TreeNode* head = new TreeNode(nums[m]);
        head -> left = helper(l,m,nums);
        head -> right = helper(m+1,r,nums);
        return head;
    }
    
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //using a binary search method, we can loop through the left and right children and form a height 
based tree
        int l = 0,r = nums.size();
        TreeNode* root = helper(l,r,nums);
        return root;
    }
};
