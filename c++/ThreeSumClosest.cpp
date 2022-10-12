#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


 int threeSumClosest(vector<int>& nums, int target) {
        
        if(nums.size() <3)
            return 0;
        //Random gauge for sum
        int sum = nums[0] + nums[1] + nums[2];
        sort(nums.begin(),nums.end());
        for(int i =0;i < nums.size()-2;i++)
        {
            if(i>0 && nums[i-1] == nums[i])
                continue;
            int l = i+1,r = nums.size()-1;
            while(l<r)
            {
                int cSum = nums[i] + nums[l] + nums[r];
                if(cSum == target)
                    return cSum;
                //Calculate the difference and find minimal difference
                sum = abs(cSum - target)  < abs(sum - target) ? cSum: sum;
            //  cout << "\nSum : " << sum  << "\tfrom " << "i: " << i << "\tl: " << l << "\tr:" << r<< endl;
                if(cSum < target)
                    l++;
                else if (cSum > target)
                    r--;
                
            }
            
        }
        return sum;
        
        
    };

 int main ()
 {
 	vector <int> nums = {0,2,1,-3};
 	int val = 1;
 	int res = threeSumClosest(nums,val);
 	cout << res << endl;
 	return 0;
 }