class Solution {
public:
    
    bool bfs(int node,vector<vector<int>> &graph,vector<int> &color){
        queue<pair<int,int>> q;
        q.push({node,0});
        
        while(q.size()){
            int size = q.size();
            while(size--){
                auto top = q.front(); q.pop();
                int top_val = top.first;
                int parent_color = top.second;
                
                color[top_val] = !parent_color;
                
                for(auto it : graph[top_val]){
                    if(color[it] == -1){
                        q.push({it,color[top_val]});
                    }else{
                        if(color[it] == color[top_val]) return true;
                    }
                }
                
            }
        }
        
        return false;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> color(n,-1);
        
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(bfs(i,graph,color))
                    return false;
            }
        }
        
        return true;
    }
};
