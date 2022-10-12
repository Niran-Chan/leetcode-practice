#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iostream>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash;                // Hash table
        for(int i=0;i<nums.size();i++){
            if(hash.find(nums[i])==hash.end())  // If number not found in the Hash table, add it.
                hash.insert(nums[i]);
            else
                return true;                    // Return true if duplicate found.
        }
        return false;
    }
};

int main()
{
Solution result;
vector <int> nums = {0,1,2,3,4};
bool output = result.containsDuplicate(nums);
cout << output << endl;


}