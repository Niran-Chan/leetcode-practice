class Solution {
public:
   int coinChange(vector<int>& coins, int amount) {
        int n = amount+1;
        vector<int>dp(n,100000);
        dp[0]=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]>=0){
                    int s = dp[i-coins[j]];
                    dp[i]=min(dp[i],s+1);
                }
            }
        }
        if(dp[n-1]>10000){
            return -1;
        }
        else{
            return dp[n-1];
        }
    }
};
