#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Solution {
public:

    //Divide and Conquer solution
    //helper functions
    int max (int x,int y){return (x>y)?x:y;}

     int max_sum(int arr[], int low, int mid, int high)
{
    //finding sum of elements on left side
    int sum = 0;
    int left_sum = -pow(10,4);
    for (int i = mid; i >= low; i--) {
        sum = sum + arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }
 
    //finding sum of elements on right side
    sum = 0;
    int right_sum = -pow(10,4);
    for (int i = mid + 1; i <= high; i++) {
        sum = sum + arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }
 
    // Return sum of elements on left and right of mid
    
    return max(left_sum + right_sum, max(left_sum, right_sum));
}



    //recursive function
     int divide_conquer(int arr[], int low,int high )
    {   
        if (high == low) return arr[low];
        
        
        //split array into half
        
        int mid = (low+high) / 2;
        int left_sum = divide_conquer(arr,low,mid);
        int right_sum = divide_conquer(arr,mid+1,high);
        int total_sum = max_sum(arr,low,mid,high);
        return total_sum;


    };
   

    int maxSubArray(vector<int>& nums) {
      
      //KADANE'S ALGORITHM
        /*
    //Finding maximum of subarrays of each as we iterate through and we compare that with the currnet value    
    
    int lmax = 0,gmax = INT_MIN;
    for(int i =0;i < nums.size();i++)
      {
          lmax = max(lmax + nums[i],nums[i]);
          gmax = max(gmax,lmax);
      } 
    return gmax;
    */
    }




   

        int arr [nums.size()]; 
      for(int i =0;i < nums.size();i++){
        arr[i] = nums[i];
      }
      int result =  divide_conquer(arr,0,nums.size()-1);
      return result;
}
};





int main()
{
Solution result;
vector <int> nums = {-2,1,-3,4,-1,2,1,-5,4};
cout << result.maxSubArray(nums) << endl;


}