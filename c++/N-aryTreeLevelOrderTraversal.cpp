/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> v;
        if(!root) return v;
        queue <Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            vector<int> comb;
            for(int i =0; i < n;i++)
            {
                Node* temp = q.front();q.pop();
                
                for(int x =0; x < temp ->children.size();x++ )
                {
                    q.push(temp -> children[x]);
                }
                comb.push_back(temp -> val);
                
            }
            v.push_back(comb);
            
            
        }
        return v;
    }
};
