#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size=nums.size(), f=1, d=1;
        for(int i=1; i<size; ++i){
                 if(nums[i]>nums[i-1]) f=d+1;
            else if(nums[i]<nums[i-1]) d=f+1;
        }
        return min(size, max(f, d));     
    }
};


int main ()
{
    Solution obj;

    vector <int> nums = {1,12,6,124};
    cout << obj.wiggleMaxLength(nums) << endl;


    return 0;
}