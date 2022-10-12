class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int l =0,r = nums.size()-1;
        vector<int> ans (nums.size());
        if(nums.size()==1){nums[0] = pow(nums[0],2);return nums;}
        int idx = nums.size()-1;
        while(l <= r)
        {

            if(abs(nums[l]) > abs(nums[r]))
            {ans[idx] = pow(nums[l],2);idx--;l++;}
            else 
            {ans[idx] = pow(nums[r],2);idx--;r--;}
            
          
            }   
        return ans;
    }
};