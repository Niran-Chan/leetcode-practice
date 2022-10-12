#include <bits/stdc++.h>
using namespace std;

 int jump(vector<int>& nums) {
        //Greedy algorithm is still relevant
        //Using BFS
       
        int l = 0, r = 0,ans = 0; 
        while(r < nums.size()-1)
        {
            int farthest = 0;
            // Finding the maximum that r can go
            for(int i = l;i < r+1;i++)
            {
                farthest = max(nums[i] + i,farthest);  
            }
            l = r+1;
            r = farthest;
            ans++;
        }
        return ans;
        
    };

int main (){

int res = jump({2,3,1,1,4});
cout << res << endl;
return 0;
}
