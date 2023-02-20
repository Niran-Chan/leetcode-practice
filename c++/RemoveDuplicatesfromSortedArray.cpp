class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int loc = 1;
        for(int i =0;i < nums.size()-1;i++)
        {
            if(nums[i] != nums[i+1])
                {
                    nums[loc] = nums[i+1];
                    loc++;
            }
        }
    
        return loc;
    }
};
