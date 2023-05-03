class Solution {
public:
    int dp [501][501];
    int dfs(int i,int j,string& s){
        if(i > j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = 501;
        if(s[i] != s[j]){
            ans = min(1 + dfs(i+1,j,s),1 + dfs(i,j-1,s));
        }
        else
            ans = dfs(i + 1,j-1,s);
        return dp[i][j] = ans;
    }
    int minInsertions(string s) {
        memset(dp,-1,sizeof(dp));
        return dfs(0,s.size()-1,s);
        
    }
};
