#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dp[101][21][101];
    int helper(int i,int prev,vector<int>& houses, vector<vector<int>>& cost, int m, int n,int t)
    {
        /*
        Case 1: if we have reached the end and target ==0 then we can safely return back 0;
        Case 2: If unpainted, c+=cost[i], target-- if new neighbourhood,i++, for loop into the various colours we can have
        Case 3: Same colour experienced means c++,target-- if new neighbourhood,i++ continue on 
        */
        //For all cases, we need to store it in a 3D array so as to ensure that 
        
        
        int ans=INT_MAX/2;
        
        //Case 1
        if(i == m)
            return (t == 0) ? 0 : INT_MAX/2 ;
        else if (t <0)
            return INT_MAX/2;
        else if (dp[i][prev][t] != -1)
            return dp[i][prev][t];

        //Case 2
        else if(houses[i] == 0)
        {
            int minCost = INT_MAX/2;
            for(int j = 0;j < n;j++)
            {
                //if current colour equals to colour of prev house
                    minCost= min(minCost,cost[i][j] + helper(i+1,j+1,houses,cost,m,n,(j+1==prev)?t : t-1));
            }
            ans= minCost;
        }
        //Case 3
        else
            ans= min(ans,helper(i+1,houses[i],houses,cost,m,n,(houses[i] == prev) ? t : t-1)); 
        
        return dp[i][prev][t] = ans;
        
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int i =0, prev = 0,c=0;
        
        int res = helper(i,prev,houses,cost,m,n,target);
        return res == INT_MAX/2 ?-1 : res;
        
    }
};


int main ()
{
    Solution obj;

    vector<int> houses = {0,0,0,0,0};
    vector<vector<int>> cost = {{1,10},{10,1},{10,1},{1,10},{5,1}};
    int m = 5, n=2, target=3;
    int res = obj.minCost(houses,  cost,  m,  n,  target);
    cout << res << endl;
    return 0;
}