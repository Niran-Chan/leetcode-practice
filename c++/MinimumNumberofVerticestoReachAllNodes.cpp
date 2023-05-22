class Solution {
public:
   
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& 
edges) {
        /*
        From each vertex, we want to find the total number of vertices 
that we can reach
        Then, we want to include the vertices that cannot be found from 
just iterating through
        */
        vector<int>visited(n,0);
        vector<vector<int>> adj(n);
        for(int i =0; i < edges.size();++i){
            visited[edges[i][1]] = 1;
        }
        
        vector<int> ans;
        for(int i =0; i < n;++i){
            if(visited[i] == 0)
                ans.push_back(i);
        }
        return ans;
    }
};
