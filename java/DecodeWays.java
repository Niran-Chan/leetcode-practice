class Solution {
    public int numDecodings(String s) {
        int dp[] = new int[s.length()];
        Arrays.fill(dp, -1);
        return helper(0, s, dp);
    }
    
    public int helper(int ind, String s, int[] dp) {        
        if(ind >= s.length()) return 1;
        if(s.charAt(ind) == '0') return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        // pick current
        int op1 = helper(ind+1, s, dp);
        // pick 2
        int op2 = 0;
        if(ind+1 < s.length() && Integer.parseInt(s.substring(ind, ind+2)) <= 26) {
            op2 = helper(ind+2, s, dp);
        }
        return dp[ind] = op1 + op2;
    }
}