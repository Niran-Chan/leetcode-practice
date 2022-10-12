class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int lmin = 1,lmax = 1,gmax=INT_MIN;
    
        for(int i = 0 ;i < nums.size();i++)
        {
    
           if (nums[i] == 0){ //Edge case
                lmax=1;
                lmin=1;
               gmax= max(gmax,0);
            }
            else{
                int temp = lmin;
                lmin = min(min(nums[i],nums[i]*lmin),nums[i]*lmax);
                lmax = max(max(nums[i]*lmax,nums[i]),nums[i]*temp);
                gmax = max(gmax,lmax);
            }
            
        }
        return gmax;
    }
};