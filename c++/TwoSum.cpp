#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {


        /*
        //Long and easy method
        vector <int> solution;
       for(int i=0;i < nums.size();i++)
       {
           for(int z=i+1; z < nums.size();z++){
               if(nums[i] + nums[z] == target){
                   solution.push_back(i);
                   solution.push_back(z);
                   break;
               };
            
           }
           if (solution.size() != 0) break; 
           
       }
        return solution;
    }
    */	

    //Hashmap Method
        
        unordered_map<int,int> mp;
        vector <int> output; 
        for(int i =0; i < nums.size(); i++)
        {
            //Find target
            int newT = target-nums[i];
            //Include cases where newT might be 0
            if(mp.find(newT)!=mp.end())
            {
                output.push_back(i);
                output.push_back(mp[newT]);
                break;
                }
            else
                mp[nums[i]] = i;
        }
        return output;
    }
};




int main ()
{
	Solution result;
	vector <int> nums = {3,2,3}; 
	int target = 6;
	vector <int> output = result.twoSum(nums,target);
		cout << "[" << output[0] << "," << output[1] << "]" <<endl;;
	


}
