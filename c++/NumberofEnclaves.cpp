class Solution {
public:
    int n,m;
    void dfs (int i, int j,vector<vector<int>>& grid) {
                if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0) {
                    return;
                }
                grid[i][j] = 0;
                dfs(i+1, j,grid);
                dfs(i-1, j,grid);
                dfs(i, j+1,grid);
                dfs(i, j-1,grid);
            };
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || j == 0 || n-1 == i || m-1 == j) && grid[i][j] == 1) {
                    dfs(i, j,grid); //Take all boundary 1s and 1s linked to boundary and change to 0
                }
            }
        }
        
        int s = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                s += grid[i][j];
            }
        }
        return s;
    }
};
