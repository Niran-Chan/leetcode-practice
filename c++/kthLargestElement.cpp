#include <bits/stdc++.h>

using namespace std;

  int findKthLargest(vector<int>& nums, int k) {
        //We can implement a sort and return the -k from the last
        //Easy approach
        
        //O(nlogn)
        sort(nums.begin(),nums.end());
        return (nums[nums.size()-k]);
    }

int main ()
{
vector <int> nums = {1,12,3,5,6};
int k = 3;
int res = findKthLargest(nums,k);
cout << res << endl;
return 0;
}
