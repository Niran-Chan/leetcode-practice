class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0,r = nums.size()-1;
        vector<int> output;
        while(l<r)
        {
            if(nums[l] + nums[r] == target)
            {output.push_back(l+1);output.push_back(r+1);break;}
            else if (nums[l] + nums[r] > target)
                r--;
            else
                l++;
        }
        return output;
    }
};