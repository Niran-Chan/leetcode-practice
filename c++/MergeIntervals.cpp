class Solution {
public:
    bool isOverlap(vector<int> &a,vector<int> &b){ //a is the current interval that b tests against
        return !(b[1] < a[0] || b[0] > a[1]);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //Helper function to determine if overlap
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i =1; i < intervals.size();++i){

            if(isOverlap(intervals[i],ans.back()))
                {
             
                    vector<int> newInterval = {min(intervals[i][0],ans.back()[0]),max(intervals[i][1],ans.back()[1])};
                    ans.back().swap(newInterval);
                    //cout << "Current ans : " << ans[0][0] << "," << ans[0][1] << endl;
                }
            else
                ans.push_back(intervals[i]);
        }
        return ans;
    }
};
