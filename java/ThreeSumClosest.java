class Solution {
    public int threeSumClosest(int[] nums, int target) {
     
        //sort the array first and we can use a two pointer solution
        Arrays.sort(nums);
        int n = nums.length;
        int a,b,c,sum;
        int gmin = Integer.MAX_VALUE,lmin;
        for(int i =0 ; i < n - 1;i++)
        {
            a = i;
            b = i+1;
            c = n-1;

            lmin = 0;
            while(b < c )
            {
                sum = nums[a] + nums[b] + nums[c];
                if(sum < target)
                    b++;
                else 
                    c--;
//find minimum difference from target
                if(Math.abs(sum - target) < Math.abs( gmin - target))
                    gmin = sum;
            }
            

        }
        return gmin;
    }
}