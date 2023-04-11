/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node *solve(Node* root,unordered_map<Node*,Node*>& visited){

        if(!root)
            return NULL;
        if(visited[root]) //If we have already visited this root, then return
            return visited[root];
        
        int newVal = root -> val;
        Node* newRoot = new Node(newVal);
        visited[root] = newRoot;
        for(int i =0; i < (root -> neighbors).size();++i)
        {
            if(visited[root->neighbors[i]])
                (newRoot -> neighbors.push_back(visited[root->neighbors[i]]));
            else
                (newRoot -> neighbors).push_back(solve(root->neighbors[i],visited));
        }
        return newRoot;
    }
    Node* cloneGraph(Node* node) {
        //Recursively go down the node, and create a new one and populate 
        unordered_map <Node* ,Node*> visited;
        return solve(node,visited);
    }
};
