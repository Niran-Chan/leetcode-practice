class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> visited;
    void solve(int i,vector<int> path,vector<int>&nums){
        if(i == nums.size()){
            return;
        }
        for(int x=i+1 ; x < nums.size();++x){
            if(nums[x] < path.back())
                continue;
            path.push_back(nums[x]);
            if(visited.find(path) != visited.end()) //in visited set
                {path.pop_back();
                continue;}
            visited.insert(path);
            ans.push_back(path);
            solve(x,path,nums);
            path.pop_back();
        }
        return;

    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        for(int i =0; i < nums.size();++i)
            solve(i ,{nums[i]},nums);
        return ans;
    }
};
