#include <bits/stdc++.h>
using namespace std;


bool canJump(vector<int>& nums) {
      int m = nums.size()- 1;
    //Greedy Algorithm
    for(int i = nums.size()-1;i >=0; i-- )
    {
        if(nums[i] + i >=m)
            m = i;
    }
        return m == 0;
    }


int main (){

vector <int> nums = {2,3,1,1,4};
bool res = canJump(nums); 
cout << res << endl;
return 0;
}
