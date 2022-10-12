class Solution {
    public boolean increasingTriplet(int[] nums) {
        if(null == nums || nums.length<3) return false;
        
        // take two largest possbile value
        int max1 = Integer.MAX_VALUE, max2 = Integer.MAX_VALUE;
        
        for(int val : nums){
            if(val <= min1) min1 = val; // when we find first small value 
assign it to 'max1'
            else if(val <= min2) min2 = val; // when we firn second small 
value which is larger than 'max1' but smaller than 'max2'
            else return true; // third value, which is larger than 'max1' 
and 'max2'
        }
        
        return false;
    }
}
