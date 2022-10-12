#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    int maxResult(vector<int>& nums, int k) {
       priority_queue <pair< int , int>> pq ;
       int n = nums.size();
       vector <int> dp (n,0);
        
        for(int i =n-1;i >= 0; i--)
        {
            //Remove useless elements from pq
            while(!pq.empty() && pq.top().second > i+k)
                pq.pop();

            dp[i] = nums[i] + (!pq.empty() ? pq.top().first : 0);
            pq.push({dp[i],i});

        }
        return dp[0];


        }
};
int main ()
{
    Solution obj;
    vector <int> nums = {100,-1,-100,-1,100};
    int k = 2;
    cout << obj.maxResult(nums,k);

    return 0;
}