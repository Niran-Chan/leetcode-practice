class Solution {
public:
    int dp [1001][1001];
    int MOD = 1e9 + 7;
    vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

    bool isValid (int r,int c,pair<int,int> dir,vector<vector<int>>& 
grid){
        int nr = r + dir.first,nc = c + dir.second;
        if(nr < 0 || nr == grid.size() || nc < 0 || nc == grid[0].size())
            return false;
        return true;
    }
    int dfs(int r,int c,vector<vector<int>>& grid){

        if(dp[r][c] != -1)
            return dp[r][c];
        int ans = 1;
        for(auto &dir : dirs){
            if(isValid(r,c,dir,grid) && grid[r + dir.first][c + 
dir.second] > grid[r][c])
            ans = (ans + dfs(r + dir.first,c + dir.second,grid)) % MOD;
        }
        return dp[r][c] = ans;
    }
    int countPaths(vector<vector<int>>& grid) {
        //include current path, as well as the next path that is strictly 
increasing
        //You need path visited hashmap
        memset(dp,-1,sizeof(dp));
        int ans =0 ;
        for(int r =0; r < grid.size();++r){
            for(int c = 0 ; c < grid[0].size();++c){
                int tmp = dfs(r,c,grid) % MOD;
                
                ans = (ans + tmp) % MOD;
            }
        }

        return ans;

    }   
};
