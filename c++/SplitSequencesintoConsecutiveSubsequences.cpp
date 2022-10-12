class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map <int,int> freq,mp;
        for(int i =0;i < nums.size();i++)
            freq[nums[i]]++;
        for(auto num : nums)
        {
            if(freq[num] ==0)
                continue;
            
            freq[num]--;
            if (mp[num-1]) //there exists an existing subsequence
            {mp[num-1]--;mp[num]++;}
            //create a subsequence
            else if (freq[num+1] && freq[num+2])
            {
                freq[num+1]--;
                freq[num+2]--;
                mp[num+2]++;;
            }
            else return false;
            
        }
        return true;
    }
};
