class Solution {
public:
    int dp[200][200];

    int solve(int i ,int j ,vector<vector<int>> &matrix){
        int n = matrix.size();
        if(i==n)
        {
            return 0;
        }
        if(j < 0 || j == n)
            return INT_MAX;
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = (matrix[i][j] + min(solve(i+1,j+1,matrix),min(solve(i+1,j,matrix),solve(i+1,j-1,matrix))));

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof(dp));
        int n = matrix.size();
        int mn = INT_MAX;
        for(int j =0; j < n;++j){
            mn = min(solve(0,j,matrix),mn);
        }
        return mn;
    }
};
