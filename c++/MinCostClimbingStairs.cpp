#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        vector<int> dp (cost.size()+1,0);
        for(int i =2;i < cost.size()+1;i++)
            dp[i] = min(cost[i-2] + dp[i-2],cost[i-1] + dp[i-1]);
        return dp[cost.size()];
       
    };


    // Recursive Solution
       
 int helper(int i ,vector<int> &cost, vector<int> &dp)
    {
    	
    	if(i < 0)
    		return 0;
     if(dp[i] != -1)
         return dp[i];
         
    	return dp[i] = cost[i] + min(helper(i-1,cost,dp),helper(i-2,cost,dp));
    	
    }
    int minCostClimbingStairsRecur(vector<int>& cost)
    {
    	int n = cost.size();
    	vector <int> dp (n,-1);
    	return min(helper(n-1,cost,dp),helper(n-2,cost,dp));
    };
};



int main ()
{
	Solution obj;
	vector <int> cost = {10,15,20};
	cout << obj.minCostClimbingStairsRecur(cost);
	return 0;
}