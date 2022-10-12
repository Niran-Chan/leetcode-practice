class Solution {
public:
    
    int binarySearch(int l,int r ,vector<int> &nums)
    {
        if(l >=r)
            return nums[l];
        int m = (l+r)/2;
        cout << nums[m] << endl;
        if(nums[m] > nums[r]) //means that inflection point is on the right
            return binarySearch(m+1,r,nums);
        else
            return binarySearch(l,m,nums);
       
        
    }
    
    int findMin(vector<int>& nums) {
     //use binary search to the side with the lesser number   
            return binarySearch(0,nums.size()-1,nums);
    }
};