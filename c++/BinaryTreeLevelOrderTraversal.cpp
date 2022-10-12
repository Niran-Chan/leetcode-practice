#include <bits/stdc++.h>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL )
            return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push({root});
        while(!q.empty())
        {    
            vector<int> comb;
            int heightSize = q.size();
            for(int i = 0; i < heightSize;i++){
               TreeNode* s = q.front();
               q.pop();
            comb.push_back(s -> val);
            
            if(s -> left)
                q.push(s -> left);
            if(s -> right)
                q.push(s -> right);
            }
            res.push_back(comb);
        }
        return res;
    }
};

int main ()
{
Solution obj;
//Forming Tree
vector <int> test = {3,9,20,NULL,NULL,15,7};
TreeNode *root = TreeNode(3,NULL,NULL);
int h = 0;
int i =0;
vector<bool> visited = (test.size(),false);
 
while(i < test.size())
{
	for(int x = 0;x < 2**h;x++)
		{
	
			TreeNode();
			int left = 2*i,right = 2*i +1;
			if(visited[left])
					
		}
}

vector<vector<int>> res = obj.levelOrder(root);
return 0;
}