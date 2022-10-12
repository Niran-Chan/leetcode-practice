class Solution {
public:
    
    int binarySearch(int l,int r,int target,vector<int> &nums)
    {
        if(l >= r)
            return -1;
        int m = (l+r)/2;
        if(nums[m] == target)
            return m;
        else if (nums[m] > target)
            return binarySearch(l,m,target,nums);
    
        return binarySearch(m+1,r,target,nums);
        

        
        
    }
    
    
    int search(vector<int>& nums, int target) {
        return binarySearch(0,nums.size(),target,nums);
       
    }
};
