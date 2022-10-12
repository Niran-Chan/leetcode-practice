#include <iostream>
#include <vector>

using namespace std;

 int removeDuplicates(vector<int>& nums) {
        int loc = 1;
        for(int i =0;i < nums.size()-1;i++)
        {
            if(nums[i] != nums[i+1])
                {
                    nums[loc] = nums[i+1];
                    loc++;
            }
        }
    	cout << "[" ;
    	for (auto elem : nums)
    	{
    		cout << elem << "," ;
    	}
    	cout << "]";
        return loc;
    };


 int main()
 {
 	vector <int> nums = {1,1,2};
 	int k = removeDuplicates(nums);
 	return 0;


 }