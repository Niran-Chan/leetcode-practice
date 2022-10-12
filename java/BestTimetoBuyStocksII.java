class Solution {

    public int maxProfit(int[] prices) {
            //If we encounter a node that is lesser than before, we can sell the stock that we alr bought and buy this current one
        int lmax = 0, gmax =0 , difference = 0,n = prices.length;

        for(int i = 1 ;i < n;i++)
        {
            difference = prices[i] -prices[i-1];
            lmax = Math.max(0,Math.max(lmax,lmax + difference));
            gmax = Math.max(lmax,gmax);
        }
        
        return gmax;
    }
}
