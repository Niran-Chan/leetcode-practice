#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
   
	int i = m-1 , j = n-1;

   while(i>-1 && j>-1)
    {   
    	//Changing num1 from the back      
    	//Comparing the indexes in both arrays
    	//decrement i or j, depending on array that we pick to take number from 
        nums1[i+j+2]= (nums1[i] <= nums2[j])?nums2[j--]:nums1[i--];
    }
    //If num1 dies out first
    //Want to fill up the remaining of num1 with its own numbers
    if(i<0)
    	for(i=0;i<=j;i++)
        	nums1[i]=nums2[i];
	}





};

int main ()
{	Solution result;
	vector <int> nums1 = {1,2,3,0,0,0};
	vector <int> nums2  = {};
	int m = 1,n=0;
	

	result.merge(nums1,m,nums2,n);


	
}
