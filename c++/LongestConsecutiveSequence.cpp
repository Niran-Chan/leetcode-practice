#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() < 1) //Edge case of no elements
            return 0;
        //Sort first then check if the numbers are consecutive
        sort(nums.begin(),nums.end());
        
        int lmax = 1,gmax = 1;
        for(int i = 1;i < nums.size();i++)
        {
            //Skip duplicates
            if(nums[i] == nums[i-1])
                continue;
            lmax = (nums[i] ==  nums[i-1] + 1) ? lmax + 1 : 1; //Check if incremental and if not, reset
            gmax = max(gmax,lmax); 
        }
        return gmax;
    }

    int longestConsecutiveHash(vector <int> &nums)
    {
    	unordered_set <int> s(nums.begin(),nums.end());
    	//We can just iterate through the vector and see if its consecutive element is available
    	//Populate hashtable along the way
	  if(nums.size() < 1)
            return 0;

    	int gmax =1,lmax;
    	for(int i =0;i < nums.size();i++)
    	{
    		//Check if duplicate and if it is, continue
    		if(s.find(nums[i] -1) != s.end()) continue;
    		lmax = 0;
    		int key = nums[i];
    		while(s.find(key) != s.end()){
    			key++;
    			//cout << "\tChecking " << key << endl;
    			lmax++;	
    		}

    		gmax = max(lmax,gmax);
    	}
    	return gmax;
    }

    //DFS methods
    int longestConsecutiveDFS(vector <int > &nums)
    {

        unordered_set <int> s(nums.begin(),nums.end());
        unordered_map <int,int> visited;
        //Another way is to think of them as connected chains that we iterate through
        //Delete visited nodes
        //We will have to use an iterator for the set
        int gmax = 0;
        for(int i =0;i < nums.size();i++)
        {
            //Run dfs on each number and add into a unordered_map 
            int lmax = 1,key = nums[i];
            if(visited [key])
                continue;
            
            while(s.find(key-1)!= s.end() && visited[key-1] == 0)
            {
                visited[key-1] ++;
                key--;
                lmax++;
     
            }
                   key = nums[i];
            while(s.find(key+1) != s.end() && visited[key+1] == 0)
            {
                visited[key-1] ++;
                key++;
                lmax++;
                
            }
            gmax = max(lmax,gmax);
        }
        return gmax;
    }


};

int main ()
{
	Solution res;
	vector <int> nums = {0,-1};
	int out1 = res.longestConsecutive(nums);
	int out2 = res.longestConsecutiveHash(nums);
	cout << out1 << " " << out2 << endl;
	return 0;	

}