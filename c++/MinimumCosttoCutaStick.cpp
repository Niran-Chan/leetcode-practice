class Solution {
public:
    int solve(int i,int j,vector<int>&cuts,vector<vector<int>>&dp){
        if(i>j) //We have reached the end of the smaller stick
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans=INT_MAX;
        
        for(int k=i;k<=j;k++){ 
            int h=cuts[j+1]-cuts[i-1] + solve(i,k-1,cuts,dp) + 
solve(k+1,j,cuts,dp); //Adding: Current Stick Size + Cuts in new stick on 
Left + Cuts in new stick on Right
            ans=min(ans,h);
        }
         return dp[i][j]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n); 
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end()); 
        vector<vector<int>>dp(cuts.size(),vector<int>(cuts.size(),-1)); 
//Cache
        return solve(1,cuts.size()-2,cuts,dp);
    }
};
