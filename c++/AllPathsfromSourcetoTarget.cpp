class Solution {
public:
    void solve(int i ,vector<int> path,vector<vector<int>>&res,vector<vector<int>>& graph){
        int n = graph.size();
        for(int j =0 ; j < graph[i].size();++j){
            if(graph[i][j] == n-1)
            {
                path.push_back(graph[i][j]);
                res.push_back(path);
                path.pop_back();
            } 
            else
                {
                    path.push_back(graph[i][j]);
                    solve(graph[i][j],path,res,graph);
                    path.pop_back();
                }
        }

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        int n = graph.size();
        solve(0,{0},res,graph);
        return res;
    }
};
