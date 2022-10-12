#include <bits/stdc++.h>

using namespace std;
class Soln
{
	public:
	
		 bool checkPossibility(vector<int>& nums) {
 			bool condition = false;
	        for(int i = 1; i < nums.size(); i++){
	            if(nums[i-1] > nums[i]){
	                if(condition)
	                    return false;
	                condition = true;
	                //There can be a case where there is only one odd number in between that is larger than the rest of the array and creates an expectation that all numbers should follow it but turns out that thats the odd one
	                
	                if(i-2<0 || nums[i-2] <= nums[i])nums[i-1] = nums[i];
	                else nums[i] = nums[i-1];
	            }
	        }
	        return true;
	    };


};



int main ()
{
	//Calling default constructor
	Soln check1 = Soln() ;
	vector <int> nums = {4,2,3};
	bool res =  check1.checkPossibility(nums);
	cout << res <<endl;
	return 0;


}