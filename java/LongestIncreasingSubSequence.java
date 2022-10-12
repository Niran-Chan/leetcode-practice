class Solution {

    public int lengthOfLIS(int[] nums) {
       
        int n = nums.length;
         int dp []  = new int [n+1];
         for(int i =0 ; i < dp.length;i++)
            dp[i] = 1;
        for(int i = n-1; i >= 0;i--)
        {
            for(int j = i; j < n;j++){
                if(nums[i] < nums[j])
                    dp[i] = Math.max(dp[i],dp[j] + 1);
            }
        }
        int maxSeq = 0;
        for(int i =0; i < n;i++)
            maxSeq = Math.max(maxSeq,dp[i]);
        for(int i =0;i < n;i++)
            System.out.print(dp[i] + ",");
        return maxSeq;
    }
}