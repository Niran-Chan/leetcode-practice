#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

 vector<vector<int>> threeSum(vector<int>& nums) {
 		//If size is lesser than 3
        if(nums.size() < 3)
            return {};
        //Sort out in ascending order for 2 pointer solution
        sort(nums.begin(),nums.end());
        vector <vector<int>> output;
        
        for(int i = 0;i < nums.size() - 2;i++)
        {
            //Don't reuse same value so that we avoid any duplicate triplets
            if(i>0 && nums[i] == nums[i-1])
                continue;
         
            //2 pointers come here
            int j = i + 1,k = nums.size()-1;
            //While left pointer (j) is smaller than right pointer (k)
            while (j<k)
            {
                int threesum = nums[i] + nums[j] + nums[k];
                if(threesum > 0)
                    k--;
                //DONT USE IF. USE ELSE IF. This is because we can get a case where both ifs
                //are evaluated, j becomes j>=k and the while loop DOES NOT break from the loop

                else if(threesum < 0)
                    j++;
                else{
                    output.push_back({nums[i],nums[j],nums[k]});
                    //Skip all duplicates
// cout << " i Value : " << i << "\tJ Value : "<<  j << "\tK-Value : "<<  k << endl;
                    j++;
                   //Ensure that we can find the next pair of triplets by just moving our 
                    //left pointer
                    while(nums[j] == nums[j-1] && j < k)
                        j++;
          
                 
                } 
                
                
            }
            
        }
        return output;
    };


int main ()
{
	vector <vector <int>> res;
	vector <int> nums = {-1,0,1,2,-1,-4};
	res = threeSum(nums);
	for(auto x : res)
	{
		cout << "[";
		for(auto y : x)
			cout << y << ",";
		cout << "]";
	}
	return 1;

}