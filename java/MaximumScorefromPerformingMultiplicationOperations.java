class Solution {
    

    Integer [][] cache = new Integer[1000][1000];
    public int dfs(int i,int j,int[] nums,int[] multipliers)
    {
        if(j == multipliers.length)
            return 0;
        if(cache[i][j] != null)
            return cache[i][j];
        int left = dfs(i+1,j+1,nums,multipliers) + nums[i] * multipliers[j];
        
        int right = dfs(i ,j+1,nums,multipliers) + nums[nums.length - 1 - (j-i)] * multipliers[j];
        
        return cache[i][j] = Math.max(left,right);
        
    }
    
    public int maximumScore(int[] nums, int[] multipliers) {
        
        return dfs(0,0,nums,multipliers);
        
        
    }
}