#include <iostream>
#include <vector>

using namespace std;



//Using binary search
int searchInsert(vector<int>& nums, int target) {
          int l = 0, h = nums.size()-1;
        while (l <= h) {
            int mid = (h+l)/2;
            if (nums[mid] < target)
                l = mid+1;
            else
                h = mid-1;
        }

         return l;
    };

int main()
{
    vector <int> nums = {1,3,5,6};
    int target = 5;
    int k = searchInsert(nums,target);

    return 0 ;
}

//Iterative Method
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //Binary Search
        int l=0,r = nums.size(),m =0;
        while(l < r)
        {
  
            m = int((l+r)/2);
            if(nums[m] == target)
                return m;
            if(nums[m] > target)
                r = m;
            else
                l = m+1;
        }
        return l;
    }
};
