class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        //use kadane's algorithm
        int n = nums.size(),ans =nums[0];
        int lmax = nums[0],lmin = nums[0],sm = nums[0],gmax = nums[0],gmin 
= nums[0];
        //we calculate gmin so that we can find the minimum contiguous sub 
array sum, which allows us to subtract from the total sum of the entire 
array and see if our maximum contiguous sub array is circular or not. if 
it is not circular, then gmax will be returned; else, the sum - gmin will 
be returned;
        for(int i =1;i < n;++i){
            lmax = max(nums[i],nums[i] + lmax);
            lmin = min(nums[i],nums[i] + lmin);
            gmax = max(gmax,lmax);
            gmin = min(gmin,lmin);
            sm += nums[i];
        }
        if(sm == gmin)
            return gmax;
        return max(gmax,sm - gmin);
    }
};
