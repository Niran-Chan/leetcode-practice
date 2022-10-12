#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
        void helper (TreeNode* trav,int h,vector<int> &res)
    {
 
       if(trav == NULL)
       return;
       //Dynamically expand vector size AND only push into vector when the right is done
       if(h>res.size()) res.push_back(trav->val);
        helper(trav -> right,h+1,res);
        helper(trav -> left,h+1,res);
   
    }
    
    
    
    vector<int> rightSideView(TreeNode* root) {

        vector <int> res;
        helper(root,1,res);
        return res;
    }
};




int main ()
{
	Solution obj;
	cout << obj.rightSideView(root);


}