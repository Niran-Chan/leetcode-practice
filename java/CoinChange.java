class Solution {
    public int dfs(int[] coins,int amount,int[] cache)
    {
        if(amount == 0)
            return 0;
        
        if(cache[amount] != -1)
            return cache[amount];
 
        int minimum = 100000;
        for(int i =0 ; i < coins.length;i++)
        {
            if(amount - coins[i] < 0) continue;
            
            int temp = dfs(coins,amount-coins[i],cache);
            minimum = Math.min(minimum,temp + 1);
        }
        return cache[amount] = minimum;
    }
    
    public int coinChange(int[] coins, int amount) {
       if(amount == 0)
           return 0;
        int [] cache = new int[amount+1];
        Arrays.fill(cache,-1);
        int ans = dfs(coins,amount,cache);
        
        return ans == 100000 ? -1 : ans;
    }
}
