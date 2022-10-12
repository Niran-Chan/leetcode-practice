#include <iostream>
#include <vector>

int removeElement(vector<int>& nums, int val) {
     //Grabbing elements from the back and checking if its val or not
    //if not val, then continue to next element
        int length = nums.size(), index = 0;
		while ( index < length )
		{
			 if ( nums[index] == val )
			 {
				 nums[index] = nums[length - 1];
				 -- length;
			 }
				
			else ++index;
		}


		 return length; 
    }

 int main ()
 {
 	vector <int> nums = {3,2,2,3};
 	int val = 2; 
 	int k = removeElement(nums,val);

 }