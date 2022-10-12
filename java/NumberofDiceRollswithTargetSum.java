class Solution {

    int dp[][];
    int MOD = 1000000007;
    public int solve(int n,int k,int target)
    {
       if(target<0) //if target is negative 
            return 0;
        if(n!=0 && target==0) //if target is 0 but we have the dices to throw 
            return 0;
        if(target !=0 && n==0)//if target is not 0 but we don't have dices to throw
            return 0;
        if(target==0 && n==0)//if both target and dice are 0
            return 1;
        if(dp[n][target]!=-1)
            return dp[n][target]%MOD; //Return Cached count 
        int cnt =0;
        for(int i=1;i<=k;i++)
        {
            cnt = (cnt + solve(n-1,k,target-i))%MOD;
        }
        return dp[n][target]=cnt%MOD;
    }
    public int numRollsToTarget(int n, int k, int target) {
        //dfs search into each possible value
        dp = new int[31][1001];
        for(int i =0; i < 31;i++)
            for(int j = 0; j < 1001;j++)
                dp[i][j] = -1;
        int ans = solve(n,k,target);
        return ans;
    }
}