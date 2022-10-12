#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    int rob(vector<int>& nums) {
        int a = 0,b = 0;  
        for(int i =0; i < nums.size();i++)
            {
                
                int temp = max(nums[i] + a,b);
                a = b;
                b = temp;
            }
        return b;
        }
};

int main ()
{
	Solution obj;
	vector <int> nums = {1,2,3,1};
	cout << obj.rob(nums);
	return 0;
}