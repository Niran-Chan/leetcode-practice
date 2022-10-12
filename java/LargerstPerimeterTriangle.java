class Solution {
    public int largestPerimeter(int[] nums) {
           //Considered triangle if sum of 2 smaller sides is greater than 
the longer side
        Arrays.sort(nums);
        int n = nums.length;
        
    for(int i = n-1;i >= 2;i--)
    {
        if(nums[i] < nums[i-1] + nums[i-2])
            return nums[i] + nums[i-1] + nums[i-2];
    }

    return 0;
    }   
}