class Solution {
public:
     void dfs(TreeNode* root, int col, int row, map<int, map<int, 
multiset<int>>>& nodes) {

        if (root == NULL) return;
        nodes[col][row].insert(root -> val);
        
        dfs(root-> left, col - 1, row + 1, nodes);
        dfs(root-> right, col + 1, row + 1, nodes);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> v;
        // nodes is used to store the node values grouped by column 
        // see above diagram for better understanding
        // use multiset here as the value could be same
        // use map here to take care of the order
        map<int, map<int, multiset<int>>> nodes;
        dfs(root, 0, 0, nodes);
        for (auto column : nodes) {
            vector<int> col;
            for (auto rows : column.second) {
                // we can use `insert` to add all elelments to a vector
                // instead of adding them one by one
                col.insert(col.end(), rows.second.begin(), 
rows.second.end());
            }
            v.push_back(col);
        }
        // return final ans
        return v;
    }
};
