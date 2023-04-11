class Solution {
public:
    int visited [101][101];
    int dfs(int r,int c,vector<vector<int>>&grid){
        if(r < 0 || r == grid.size() || c < 0 || c == grid[0].size())
            return 0;
        if(visited[r][c] != -1)
            return visited[r][c];
        if(grid[r][c] == 1)
            return visited[r][c] = 1;
        visited[r][c] = 1;
        int lft,rgt,tp,bt;
        lft = dfs(r,c-1,grid);
        rgt = dfs(r,c+1,grid);
        tp = dfs(r + 1,c,grid);
        bt = dfs(r - 1,c,grid);
        return visited[r][c] = lft && rgt && tp && bt ? 1 : 0;
    }
    int closedIsland(vector<vector<int>>& grid) {
      memset(visited,-1,sizeof(visited));
      vector<pair<int,int>> pos;
      for(int i =0; i < grid.size();++i)
        for(int j =0; j < grid[i].size();++j)
            if(grid[i][j] == 0)
                pos.push_back({i,j});
    
        int ans = 0;
        for(int i =0; i < pos.size();++i)
            if(visited[pos[i].first][pos[i].second] == -1)
                ans += dfs(pos[i].first,pos[i].second,grid) ? 1 : 0;
        return ans;
    }
};
