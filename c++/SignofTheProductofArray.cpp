class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool ans = true;
        for(int i =0 ; i < nums.size();++i){
            if(nums[i] == 0)
                return 0;
            if(nums[i] < 0)
                ans = !(ans);
        }
        return ans ? 1 : -1;
    }
};
