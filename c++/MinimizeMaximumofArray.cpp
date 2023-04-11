class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long int ans=0,s=0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i]; //add the current number
            ans=max(ans,(s/(i+1) + (s % (i+1) != 0))); //Round up the 
number 
        }
        return ans;
    }
};
