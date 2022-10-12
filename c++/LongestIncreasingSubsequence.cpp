class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> sub;
        
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            auto it = lower_bound(sub.begin(), sub.end(), nums[i]); //returns index of value found that 
compares less than the value nums[i]
            if(it != sub.end()) {
                *it = nums[i]; //We change the value found
            } else {
                sub.push_back(nums[i]); //We can now safely move our iterator up after pushing back
            }
        }
        for(auto a : sub)
            cout << a << endl;
        return sub.size();
    }
};

