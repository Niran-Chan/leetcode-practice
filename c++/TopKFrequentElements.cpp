class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //We can use a binary heap to solve for freq
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> q;
        for(int i =0; i < nums.size();++i)
            mp[nums[i]]++;
        vector<int> ans;
        for(auto &it : mp){
            q.push({it.second,it.first});
        }

        for(int i =0; i < k;++i){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;

    }
};
