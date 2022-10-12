class Solution {
public:

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res= {-1,-1};
        int l =0, r = nums.size()-1;
        while(l<r)
        {
            int mid = (l+r)/2;
            if(nums[mid]<target)
                l = mid + 1;
            else 
                r=mid;
        }
        if(nums.size() ==0 || nums[l] != target)
            return res;
        
        //Second binary search is to find the right limit
        res[0]= l,r = nums.size() - 1;
        while(l < r)
        {
            int mid = (l+r)/2 + 1;
            if(nums[mid] > target)
                r = mid - 1;
            else 
                l = mid;
        }
        res[1] = l;
        return res;
        
    }
};