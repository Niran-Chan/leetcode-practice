class Solution {
    public int trap(int[] arr) {
        //1. Precompute maximum on left and maximum on right of current 
index
        int [] left,right;
    
        int n = arr.length;
        left = new int[n];
        right = new int[n];
        
        for(int i =1 ; i < n;i++ )
            left[i] = Math.max(left[i-1],arr[i-1]);
        
        for(int i = n-2; i>= 0 ;i--)
            right[i] = Math.max(right[i+1],arr[i+1]);
        //Use precomputated values to calculate the minimum of both, then 
use that to subtract current index to find out how much water
        int trappedWater = 0;
        
        for(int i =1;i < n - 1;i++)
        {
            trappedWater += Math.max(0,Math.min(left[i],right[i]) - 
arr[i]);
            
        }
        
        return trappedWater;
    }
}
