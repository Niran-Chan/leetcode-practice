class Solution {
public:
    int dp [201][201] ;

    int dfs(int r,int c,vector<vector<int>> &grid){
        if(dp[r][c] != -1)
            return dp[r][c];
        if(r == grid.size()-1 && c == grid[0].size()-1)
            return grid[r][c];
        int ans = INT_MAX;
        if(r + 1 != grid.size())
            ans = min(ans,grid[r][c] + dfs(r + 1,c,grid));
        if(c + 1 != grid[0].size())
            ans = min(ans,grid[r][c] + dfs(r,c+1,grid));
        return dp[r][c] = ans;
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return dfs(0,0,grid);
    }
};
