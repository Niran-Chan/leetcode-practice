#include <bits/c++.h>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //prefix sum problem
        unordered_map <int,int> res;
        res[0] = 1; //initial prefix of 0 is 1
        int output = 0;
        for(int i =0;i < nums.size();i++)
        {
            nums[i] = i ? nums[i-1] + nums[i] : nums[i]; //prefix sum
            int target = nums[i] - k;  //target number
            if(res[target])
                output += res[target];
            res[nums[i]]++; //add prefix to table
        }
        return output;
    }
};

int main ()
{
Solution obj;
//Expected is 2
cout << subarraySum({1,1,1},2) << endl;

return 0;
}
