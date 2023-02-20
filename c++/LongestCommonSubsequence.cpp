class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
       int dp [1001][1001];
        memset(dp,0,sizeof(dp));
        for(int i =text1.size()-1; i >= 0;--i){
            for(int j =text2.size()-1; j >=0 ;--j){
                dp[i][j] = text1[i] == text2[j] ? 1 + dp[i+1][j+1] : 
max(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};
