class Solution {
public:
    bool dfs(int u,vector<vector<int>> &adj,vector<int> &visited){
        if(visited[u] == 1) //node has been visited in the current cycle
            return false;
        if(visited[u] == 0){ //node has not been visited at all
            visited[u] = 1;
            for(int v =0 ; v < adj[u].size();++v)
                if(!dfs(adj[u][v],adj,visited))
                    return false;
        }
        visited[u] = 2; //has been visited and cleared
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& preq) {
        //We populate edge list
        //We keep iterating through each vertex to check if we revisit some node that we already do
        vector<vector<int>> adj(n);
        for(int u =0; u < preq.size();++u){
            adj[preq[u][1]].push_back(preq[u][0]);
        }
        vector<int> visited(n,0);
        for(int u =0; u < n;++u){
           
            if(!dfs(u,adj,visited))
                return false;
        }
        return true;
    }
};
